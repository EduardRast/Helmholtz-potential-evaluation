//
//  Box.cpp
//  Helmholtz-potential-evaluation
//
//  Created by Eduard on 5/18/23.
//

#include "Box.hpp"

    //Box

std::ostream& operator<<(std::ostream& os, const Box& aBox){
    os<<"Hello, I'm a box"<<std::endl;
    return os;
}



    //Tree

//constructor
Tree::Tree(double Dp, int Lp, float Gp){
    
    //setting up parameters
    std::cout<<"Generating tree\n";
    this->D = Dp;
    this->L = Lp;
    this->g = Gp;
    
    //initializing the tree
    root = new Box;
    root->level = 0;
    root->length = D;
    root->index = 0;
}


