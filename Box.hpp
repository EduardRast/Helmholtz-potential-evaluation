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
    
    Box* parent;
    Box* children[8];
    
    int level;
    int length;
    int index;
    Geometry::Coordinate edge;
    
    std::list<Box*> NearField;
    std::list<Box*> FarField;
    
    
    friend std::ostream& operator<<(std::ostream& os, const Box& aBox);
};


class Tree{  //tree that contains boxes
    //OCF
    
    Tree(double Dp, int Lp, float Gp = 3);
    Tree(const Tree &aTree);
    ~Tree();
    //~OCF
    
    double D; //length of the largest box
    int L; //max level
    float g; //gamma, factor for determining the near/far field boxes
    
    Box* root; //tree origin
    
    Box* find_box_containing_coordinate(Geometry::Coordinate aCoordinate, int level); //returns the box of the level requested that contains the coordinate required
    Box* find_box_by_number(int level, int index); // returns a box with the number requested in the level requested
    
    void print_tree(int levels = 0); //print the tree with the option to pring part of it is the parameter is passed
    
private:
    void assign_children(Box* aBox); //assigns children to a box
};






#endif /* Box_hpp */
