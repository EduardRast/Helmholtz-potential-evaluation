//
//  Box.hpp
//  Helmholtz-potential-evaluation
//
//  Created by Eduard on 5/18/23.
//

#ifndef Box_hpp
#define Box_hpp

#include <iostream>
#include <vector>
#include <list>
#include <cmath>

#include "Coordinate.hpp"
#include "Source.hpp"

struct Box{  // node for the tree
    //OCF
    Box(){};
    Box(const Box &aBox);
    Box& operator = (const Box &aBox);
    ~Box(){};
    
    Box* parent;
    Box* children[8];
    
    int level;
    double length;
    int index;
    Coordinate edge;
    std::list<Source*> Sources;
    
    std::list<Box*> NearField;
    std::list<Box*> FarField;
        
    
    friend std::ostream& operator<<(std::ostream& os, const Box& aBox);
};
 





#endif /* Box_hpp */
