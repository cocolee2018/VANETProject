//
// Copyright (C) 2014 OpenSim Ltd.
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

#ifndef __INETVEINS_BPSKMODULATION_H
#define __INETVEINS_BPSKMODULATION_H

#include "inetveins/physicallayer/base/packetlevel/MQAMModulationBase.h"

namespace inetveins {

namespace physicallayer {

/**
 * This class implements binary phase-shift keying.
 *
 * http://en.wikipedia.org/wiki/Phase-shift_keying#Binary_phase-shift_keying_.28BPSK.29
 */
class INETVEINS_API BPSKModulation : public MQAMModulationBase
{
  public:
    static const BPSKModulation singleton;

  protected:
    static const std::vector<APSKSymbol> constellation;

  public:
    BPSKModulation();

    virtual std::ostream& printToStream(std::ostream& stream, int level) const override { return stream << "BPSKModulation"; }

    virtual double calculateSER(double snir, Hz bandwidth, bps bitrate) const override;
    virtual double calculateBER(double snir, Hz bandwidth, bps bitrate) const override;
};

} // namespace physicallayer

} // namespace inetveins

#endif // ifndef __INETVEINS_BPSKMODULATION_H
