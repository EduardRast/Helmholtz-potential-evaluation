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

#include "Space.hpp"

struct Box{  // node for the tree
    //OCF
    Box(){};
    Box(const Box &aBox);
    Box& operator = (const Box &aBox);
    ~Box(){};
    //~OCF
    
    
    Box* parent;
    std::vector< Box* > children;
    
    int level;
    int length;
    Geometry::Coordinate edge;
    
    std::list<Box*> NearField;
    std::list<Box*> FarField;
    
    
    friend std::ostream& operator<<(std::ostream& os, const Box& aBox);
};


class Tree{  //tree that contains boxes
    
};






#endif /* Box_hpp */
