//
//  Space.hpp
//  Fast evaluation of Helmholtz potential
//
//  Created by Eduard on 5/1/23.
//

#ifndef Space_hpp
#define Space_hpp

#include <iostream>

namespace Geometry{

class Space{
public:
    //OCF
    
    //make static + condition 
    Space(int size) : size(size){};
    Space(const Space &aSpace) : size(aSpace.size){};
    Space& operator=(const Space &aSpace);
    ~Space(){};
    //~OCF
    
    int size = 0;
    
    /*
     box struct that is a part of space
     has center coordinate and corner coordinates
     needs:
        1) find center based on corners
        2) check that coordinates do not exceed the space size
        3) be a child class of a space class
     */
    
    /*
     coordinate struct:
     has x,y,z, have to be smaller than the space size
     */
};
/*
class Coordinate : Space{
public:
    //OCF
    Coordinate(int x, int y, int z): x(x), y(y), z(z){};
    //~OCF
    
    int x;
    int y;
    int z;
};

*/
}



#endif /* Space_hpp */
