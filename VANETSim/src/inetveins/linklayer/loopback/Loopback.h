//
// Copyright (C) 2013 OpenSim Ltd.
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
// Author: Zoltan Bojthe
//

#ifndef __INETVEINS_LOOPBACK_H
#define __INETVEINS_LOOPBACK_H

#include "inetveins/common/INETVEINSDefs.h"

#include "inetveins/linklayer/base/MACBase.h"
#include "inetveins/linklayer/common/TxNotifDetails.h"

namespace inetveins {

class InterfaceEntry;
class IPassiveQueue;

/**
 * Loopback interface implementation.
 */
class INETVEINS_API Loopback : public MACBase
{
  protected:
    // statistics
    long numSent = 0;
    long numRcvdOK = 0;

    static simsignal_t packetSentToUpperSignal;
    static simsignal_t packetReceivedFromUpperSignal;

  protected:
    virtual InterfaceEntry *createInterfaceEntry() override;
    virtual void flushQueue() override;
    virtual void clearQueue() override;
    virtual bool isUpperMsg(cMessage *msg) override;

  public:
    Loopback() {}
    virtual ~Loopback();

  protected:
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void initialize(int stage) override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void updateDisplayString();
};

} // namespace inetveins

#endif // ifndef __INETVEINS_LOOPBACK_H
