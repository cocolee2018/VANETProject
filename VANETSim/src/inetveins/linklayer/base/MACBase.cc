//
// Copyright (C) 2013 Opensim Ltd.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//
// Author: Andras Varga (andras@omnetpp.org)
//

#include <stdlib.h>

#include "inetveins/linklayer/base/MACBase.h"

#include "inetveins/common/lifecycle/NodeStatus.h"
#include "inetveins/common/NotifierConsts.h"
#include "inetveins/networklayer/common/InterfaceEntry.h"
#include "inetveins/networklayer/contract/IInterfaceTable.h"
#include "inetveins/common/lifecycle/NodeOperations.h"
#include "inetveins/common/ModuleAccess.h"

namespace inetveins {

MACBase::~MACBase()
{
}

void MACBase::initialize(int stage)
{
    cSimpleModule::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {
        hostModule = findContainingNode(this);
        if (hostModule)
            hostModule->subscribe(NF_INTERFACE_DELETED, this);
    }
    else if (stage == INITSTAGE_LINK_LAYER) {
        updateOperationalFlag(isNodeUp());    // needs to be done when interface is already registered (=last stage)
    }
}

bool MACBase::handleOperationStage(LifecycleOperation *operation, int stage, IDoneCallback *doneCallback)
{
    Enter_Method_Silent();

    if (dynamic_cast<NodeStartOperation *>(operation)) {
        if ((NodeStartOperation::Stage)stage == NodeStartOperation::STAGE_LINK_LAYER) {
            updateOperationalFlag(true);
        }
    }
    else if (dynamic_cast<NodeShutdownOperation *>(operation)) {
        if ((NodeShutdownOperation::Stage)stage == NodeShutdownOperation::STAGE_LINK_LAYER) {
            updateOperationalFlag(false);
            flushQueue();
        }
    }
    else if (dynamic_cast<NodeCrashOperation *>(operation)) {
        if ((NodeCrashOperation::Stage)stage == NodeCrashOperation::STAGE_CRASH) {
            updateOperationalFlag(false);
            clearQueue();
        }
    }
    else {
        throw cRuntimeError("Unsupported operation '%s'", operation->getClassName());
    }

    return true;
}

void MACBase::receiveSignal(cComponent *source, simsignal_t signalID, cObject *obj DETAILS_ARG)
{
    if (signalID == NF_INTERFACE_DELETED) {
        if (interfaceEntry == check_and_cast<const InterfaceEntry *>(obj))
            interfaceEntry = nullptr;
    }
}

bool MACBase::isNodeUp()
{
    NodeStatus *nodeStatus = dynamic_cast<NodeStatus *>(hostModule->getSubmodule("status"));
    return !nodeStatus || nodeStatus->getState() == NodeStatus::UP;
}

void MACBase::updateOperationalFlag(bool isNodeUp)
{
    isOperational = isNodeUp;    // TODO and interface is up, too
}

void MACBase::registerInterface()    //XXX registerInterfaceIfInterfaceTableExists() ???
{
    ASSERT(interfaceEntry == nullptr);
    IInterfaceTable *ift = findModuleFromPar<IInterfaceTable>(par("interfaceTableModule"), this);
    if (ift) {
        interfaceEntry = createInterfaceEntry();
        ift->addInterface(interfaceEntry);
    }
}

void MACBase::handleMessageWhenDown(cMessage *msg)
{
    if (isUpperMsg(msg) || msg->isSelfMessage()) {    //FIXME remove 1st part -- it is not possible to ensure that no msg is sent by upper layer (race condition!!!)
        throw cRuntimeError("Message received from higher layer while interface is off");
    }
    else {
        EV << "Interface is turned off, dropping packet\n";
        delete msg;
    }
}

} // namespace inetveins
