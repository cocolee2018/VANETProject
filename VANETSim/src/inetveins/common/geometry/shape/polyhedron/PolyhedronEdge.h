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

#ifndef __INETVEINS_POLYHEDRONEDGE_H
#define __INETVEINS_POLYHEDRONEDGE_H

#include "inetveins/common/geometry/shape/polyhedron/PolyhedronPoint.h"
#include "inetveins/common/geometry/shape/polyhedron/PolyhedronFace.h"
#include "inetveins/common/geometry/common/Coord.h"

namespace inetveins {

class PolyhedronFace;
class PolyhedronPoint;

class INETVEINS_API PolyhedronEdge
{
    protected:
        PolyhedronPoint *point1; // start point
        PolyhedronPoint *point2; // end point
        PolyhedronFace *parentFace; // the face that contains this edge
        PolyhedronFace *jointFace; // the face that shares this edge with the parent face
        PolyhedronEdge *jointEdge; // the common edge between the parentFace and jointFace (this points to the joint face's edge)
        PolyhedronEdge *next; // the edge that follows the current edge (in a face)
        PolyhedronEdge *prev; // the edge that precedes the current edge (in a face)

    public:
        PolyhedronEdge(PolyhedronPoint *point1, PolyhedronPoint *point2, PolyhedronFace *parentFace) :
             point1(point1), point2(point2), parentFace(parentFace), jointFace(nullptr),
             jointEdge(nullptr), next(nullptr), prev(nullptr) {};
        PolyhedronPoint *getP1() { return point1; }
        PolyhedronPoint *getP2() { return point2; }
        const PolyhedronPoint *getP1() const { return point1; }
        const PolyhedronPoint *getP2() const { return point2; }
        void setNextEdge(PolyhedronEdge *next) { this->next = next; }
        void setPrevEdge(PolyhedronEdge *prev) { this->prev = prev; }
        void setJointEdge(PolyhedronEdge *jointEdge) { this->jointEdge = jointEdge; }
        PolyhedronEdge *getjointEdge() { return jointEdge; }
        PolyhedronEdge *getNextEdge() { return next; }
        PolyhedronEdge *getPrevEdge() { return prev; }
        PolyhedronFace *getParentFace() { return parentFace; }
        void setJointFace(PolyhedronFace *jointFace) { this->jointFace = jointFace; }
        PolyhedronFace *getJointFace() { return jointFace; }
        PolyhedronPoint getEdgeVector() const;
        bool operator==(const PolyhedronEdge& rhs) const;
};

} /* namespace inetveins */

#endif // ifndef __INETVEINS_POLYHEDRONEDGE_H