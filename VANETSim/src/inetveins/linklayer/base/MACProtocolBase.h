//
// Copyright (C) 2013 OpenSim Ltd
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

#ifndef __INETVEINS_MACPROTOCOLBASE_H
#define __INETVEINS_MACPROTOCOLBASE_H

#include "inetveins/common/LayeredProtocolBase.h"
#include "inetveins/common/lifecycle/NodeOperations.h"
#include "inetveins/networklayer/common/InterfaceEntry.h"

namespace inetveins {

class INETVEINS_API MACProtocolBase : public LayeredProtocolBase, public cListener
{
  public:
    /** @brief Gate ids */
    //@{
    int upperLayerInGateId;
    int upperLayerOutGateId;
    int lowerLayerInGateId;
    int lowerLayerOutGateId;
    //@}

    InterfaceEntry *interfaceEntry;

  protected:
    MACProtocolBase();

    virtual void initialize(int stage) override;

    virtual void registerInterface();
    virtual InterfaceEntry *createInterfaceEntry() = 0;

    virtual void sendUp(cMessage *message);
    virtual void sendDown(cMessage *message);

    virtual bool isUpperMessage(cMessage *message) override;
    virtual bool isLowerMessage(cMessage *message) override;

    virtual bool isInitializeStage(int stage) override { return stage == INITSTAGE_LINK_LAYER; }
    virtual bool isNodeStartStage(int stage) override { return stage == NodeStartOperation::STAGE_LINK_LAYER; }
    virtual bool isNodeShutdownStage(int stage) override { return stage == NodeShutdownOperation::STAGE_LINK_LAYER; }
};

} // namespace inetveins

#endif // ifndef __INETVEINS_MACPROTOCOLBASE_H
