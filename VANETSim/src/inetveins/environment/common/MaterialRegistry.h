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

#ifndef __INETVEINS_MATERIALREGISTRY_H
#define __INETVEINS_MATERIALREGISTRY_H

#include <map>
#include "inetveins/environment/contract/IMaterialRegistry.h"

namespace inetveins {

namespace physicalenvironment {

class INETVEINS_API MaterialRegistry : public IMaterialRegistry
{
  protected:
    mutable std::map<const std::string, const Material *> materials;

  public:
    static MaterialRegistry singleton;

  protected:
    void addMaterial(const Material *material) const;

  public:
    MaterialRegistry();
    virtual ~MaterialRegistry();

    virtual const Material *getMaterial(const char *name) const override;
};

} // namespace physicalenvironment

} // namespace inetveins

#endif // ifndef __INETVEINS_MATERIALREGISTRY_H
