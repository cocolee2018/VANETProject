//
// Copyright (C) 2013 Andras Varga
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

#ifndef __INETVEINS_IPSOCKET_H
#define __INETVEINS_IPSOCKET_H

#include "inetveins/common/INETVEINSDefs.h"
#include "inetveins/networklayer/common/IPProtocolId_m.h"

namespace inetveins {

/**
 * TODO
 */
class INETVEINS_API IPSocket
{
  private:
    cGate *gateToIP;

  protected:
    void sendToIP(cMessage *message);

  public:
    IPSocket(cGate *gateToIP = nullptr) { this->gateToIP = gateToIP; }
    virtual ~IPSocket() {}

    /**
     * Sets the gate on which to send to IP. Must be invoked before socket
     * can be used. Example: <tt>socket.setOutputGate(gate("ipOut"));</tt>
     */
    void setOutputGate(cGate *gateToIP) { this->gateToIP = gateToIP; }

    /**
     * Registers the given IP protocol to the connected gate.
     */
    void registerProtocol(int protocol);
};

} // namespace inetveins

#endif // ifndef __INETVEINS_IPSOCKET_H
