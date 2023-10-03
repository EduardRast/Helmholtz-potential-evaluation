//
//  Coordinate.cpp
//  Helmholtz-potential-evaluation
//
//  Created by Eduard on 10/2/23.
//

#include "Coordinate.hpp"

Coordinate::Coordinate(double Xp, double Yp , double Zp){
    this->x = Xp;
    this->y = Yp;
    this->z = Zp;
}

Coordinate::Coordinate(const Coordinate &aCoordinate){
    this->x = aCoordinate.x;
    this->y = aCoordinate.y;
    this->z = aCoordinate.z;
}
