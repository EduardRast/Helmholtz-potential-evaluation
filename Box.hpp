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
    double length;
    int index;
    Geometry::Coordinate edge;
    
    std::list<Box*> NearField;
    std::list<Box*> FarField;
        
    
    friend std::ostream& operator<<(std::ostream& os, const Box& aBox);
};
 

class Tree{  //tree that contains boxes
public:
    //OCF
    Tree(double Dp, int Lp, float Gp = 3);
    Tree(const Tree &aTree);
    ~Tree(){};
    //~OCF
    
    Box* find_box_by_coordinate(int level, Geometry::Coordinate aCoordinate, bool check = 0); //returns the box of the level requested that contains the coordinate required
    Box* find_box_by_index(int level, int index, bool check = 0); // returns a box with the number requested in the level requested
    
    void print_tree(int levels = -1); //print the tree with the option to pring part of it is the parameter is passed
    
private:
    double D; //length of the largest box
    int L; //max level
    float g; //gamma, factor for determining the near/far field boxes
    
    Box* root; //tree origin
    
    bool assign_children(Box* aBox); //assigns children to a box
    bool assign_branch(Box* aBox); //assigns a full branch to the box (until the max level)
    Box* new_Box_childfree(Geometry::Coordinate anEdge, int aLevel ,int anIndex, Box* aParent = NULL); //creates a new box based on the parameters pased
    
    double get_level_length(int aLevel); //returns length of a box based on its level
/*
 
 possible imlementations??
 Q: will it help with optimization?
    int get_level_row_length(int aLevel);
    int get_level_layer_length(int aLevel);
 */
};






#endif /* Box_hpp */
