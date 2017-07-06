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

#ifndef __INETVEINS_ALTERNATINGENERGYCONSUMER_H
#define __INETVEINS_ALTERNATINGENERGYCONSUMER_H

#include "inetveins/power/contract/IEnergyConsumer.h"
#include "inetveins/power/contract/IEnergySource.h"

namespace inetveins {

namespace power {

/**
 * This class implements a simple alternating energy consumer.
 *
 * See the corresponding NED file for more details.
 *
 * @author Levente Meszaros
 */
class INETVEINS_API AlternatingEnergyConsumer : public cSimpleModule, public IEnergyConsumer
{
  protected:
    bool isSleeping;
    int energyConsumerId;
    IEnergySource *energySource;
    W powerConsumption;
    cMessage *timer;

  protected:
    virtual void initialize(int stage) override;

    virtual void handleMessage(cMessage *message) override;

    virtual void updatePowerConsumption();

    virtual void scheduleIntervalTimer();

  public:
    AlternatingEnergyConsumer();
    virtual ~AlternatingEnergyConsumer();

    virtual W getPowerConsumption() const override { return powerConsumption; }
};

} // namespace power

} // namespace inetveins

#endif // ifndef __INETVEINS_ALTERNATINGENERGYCONSUMER_H
