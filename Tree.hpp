//
//  Tree.hpp
//  Helmholtz-potential-evaluation
//
//  Created by Eduard on 10/2/23.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <iostream>
#include <vector>
#include <list>
#include <cmath>

#include "Coordinate.hpp"
#include "Source.hpp"
#include "Box.hpp"


class Tree{  //tree that contains boxes
public:
    //OCF
    Tree(double Dp, int Lp, float Gp = 3);
    Tree(const Tree &aTree);
    //TODO: add copy constructor to return the tree (do not copy) (+ make sure that thats not what happens by default)
    ~Tree(){};
    //~OCF
    
    //Methods //Methods
        //Getters, box
    Box* find_box_by_coordinate(int level, Coordinate aCoordinate, bool check = 0); //returns the box of the level requested that contains the coordinate required
    Box* find_box_by_index(int level, int index, bool check = 0); // returns a box with the number requested in the level requested
    
    void print_tree(int levels = -1); //print the tree with the option to pring part of it is the parameter is passed
    
        //Getters, sampling points
        //Getters, sources
    
private:
    //parameters
    double D; //length of the largest box
    int L; //max level
    float g; //gamma, factor for determining the near/far field boxes
    
    Box* root; //tree origin
    //~parameters
    
    //Methods //Methods
        //Generate empty tree
    bool assign_children(Box* aBox); //assigns children to a box
    bool assign_branch(Box* aBox); //assigns a full branch to the box (until the max level)
    Box* new_Box_childfree(Coordinate anEdge, int aLevel ,int anIndex, Box* aParent = NULL); //creates a new box based on the parameters pased
        
        //Getters, internal
    double get_level_length(int aLevel); //returns length of a box based on its level
        
        //Find and assign near- farfiels boxes
        //Assign sources
/*
 
 possible imlementations??
 Q: will it help with optimization?
    int get_level_row_length(int aLevel);
    int get_level_layer_length(int aLevel);
 */
};


#endif /* Tree_hpp */
