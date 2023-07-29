//
//  Space.hpp
//  Fast evaluation of Helmholtz potential
//
//  Created by Eduard on 5/1/23.
//

#ifndef Space_hpp
#define Space_hpp

#include <iostream>
#include <random>
#include <vector>
#include <cmath>

namespace Geometry{

struct Coordinate{

    //OCF
    Coordinate(){};
    //Coordinate(double x, double y, double z): x(x), y(y), z(z){};
    //Coordinate(const Coordinate &aCoordinate) : x(aCoordinate.x), y(aCoordinate.y), z(aCoordinate.z) {};
    ~Coordinate(){};
    //~OCF
    
    double x;
    double y;
    double z;
};





/*
struct Charge{
    //OCF
    Charge(int charge, Coordinate aCoordinate) : charge(charge), aCoordinate(aCoordinate){};
    Charge(const Charge &aCharge) : charge(aCharge.charge), aCoordinate(aCharge.aCoordinate) {};
    ~Charge(){};
    //~OCF
        
    //variables
    int charge;
    Coordinate aCoordinate;
    
    
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
    Coordinate generate_random_coordinate(bool print = 0);
    bool generate_uniform_random_charges(int percent);
    //generate random charges
    
    //variables
    int size = 0;
    std::vector<Charge> charges;
    //needs list of charges
};
*/


}



#endif /* Space_hpp */
