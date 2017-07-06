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

#ifndef __INETVEINS_APSKCODE_H
#define __INETVEINS_APSKCODE_H

#include "inetveins/physicallayer/contract/bitlevel/IScrambler.h"
#include "inetveins/physicallayer/contract/bitlevel/IInterleaver.h"
#include "inetveins/physicallayer/common/bitlevel/ConvolutionalCode.h"
#include "inetveins/physicallayer/contract/bitlevel/ICode.h"

namespace inetveins {

namespace physicallayer {

class INETVEINS_API APSKCode : public ICode
{
  protected:
    const ConvolutionalCode *convolutionalCode;
    const IInterleaving *interleaving;
    const IScrambling *scrambling;

  public:
    APSKCode(const ConvolutionalCode *convCode, const IInterleaving *interleaving, const IScrambling *scrambling);
    ~APSKCode();

    virtual std::ostream& printToStream(std::ostream& stream, int level) const override;

    const ConvolutionalCode *getConvolutionalCode() const { return convolutionalCode; }
    const IInterleaving *getInterleaving() const { return interleaving; }
    const IScrambling *getScrambling() const { return scrambling; }
};
} /* namespace physicallayer */
} /* namespace inetveins */

#endif /* __INETVEINS_APSKCODE_H */
