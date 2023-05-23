//
//  Space.hpp
//  Fast evaluation of Helmholtz potential
//
//  Created by Eduard on 5/1/23.
//

#ifndef Space_hpp
#define Space_hpp

#include <iostream>
#include <cmath>

namespace Geometry{

struct Coordinate{

public:
    //OCF
    Coordinate(int x, int y, int z): x(x), y(y), z(z){};
    Coordinate(const Coordinate &aCoordinate) : x(aCoordinate.x), y(aCoordinate.y), z(aCoordinate.z) {};
    Coordinate& operator=(const Coordinate &aCoordinate);
    ~Coordinate(){};
    //~OCF
    
    int x;
    int y;
    int z;
};

class Charge{
    //OCF
    //~OCF
        
    //variables
    int charge = 0;
    Coordinate aCoordinate = Coordinate(0,0,0);
    
    
};

class Space{
public:
    //OCF
    
    //make static + condition
    Space(int size) : size(std::pow(2,size)){};
    Space(const Space &aSpace) : size(aSpace.size){};
    Space& operator=(const Space &aSpace);
    ~Space(){};
    //~OCF
    
    //methods
    Coordinate generate_random_coordinates();
    int get_size();
    //generate random charges
    
    //variables
    int size = 0;
    //needs list of charges
};


}



#endif /* Space_hpp */
