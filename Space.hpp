//
//  Space.hpp
//  Fast evaluation of Helmholtz potential
//
//  Created by Eduard on 5/1/23.
//

#ifndef Space_hpp
#define Space_hpp

#include <stdio.h>

namespace Geometry{

class Space{
public:
    //OCF
    Space(int size) : size(size){};
    Space(const Space &aSpace) : size(aSpace.size){};
    Space& operator=(const Space &aSpace);
    ~Space(){};
    
    int size;
};


}

#endif /* Space_hpp */
