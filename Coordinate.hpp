//
//  Coordinate.hpp
//  Helmholtz-potential-evaluation
//
//  Created by Eduard on 10/2/23.
//

#ifndef Coordinate_hpp
#define Coordinate_hpp

#include <iostream>

struct Coordinate{

    //OCF
    //Coordinate(){};
    Coordinate(double Xp = 0,double Yp = 0, double Zp = 0);
    Coordinate(const Coordinate &aCoordinate);
    ~Coordinate(){};
    //~OCF
    
    double x;
    double y;
    double z;
};

#endif /* Coordinate_hpp */
