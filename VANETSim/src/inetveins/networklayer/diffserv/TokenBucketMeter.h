//
// Copyright (C) 2012 Opensim Ltd.
// Author: Tamas Borbely
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

#ifndef __INETVEINS_TOKENBUCKETMETER_H
#define __INETVEINS_TOKENBUCKETMETER_H

#include "inetveins/common/INETVEINSDefs.h"
#include "inetveins/common/INETVEINSMath.h"

namespace inetveins {

/**
 * Simple token bucket meter.
 */
class INETVEINS_API TokenBucketMeter : public cSimpleModule
{
  protected:
    double CIR = NaN;    // Commited Information Rate (bits/sec)
    long CBS = 0;    // Committed Burst Size (in bits)
    bool colorAwareMode = false;

    long Tc = 0;    // token bucket for committed burst
    simtime_t lastUpdateTime;

    int numRcvd = 0;
    int numRed = 0;

  public:
    TokenBucketMeter() {}

  protected:
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }

    virtual void initialize(int stage) override;

    virtual void handleMessage(cMessage *msg) override;

    virtual int meterPacket(cPacket *packet);
};

} // namespace inetveins

#endif // ifndef __INETVEINS_TOKENBUCKETMETER_H
