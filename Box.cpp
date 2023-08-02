//
//  Box.cpp
//  Helmholtz-potential-evaluation
//
//  Created by Eduard on 5/18/23.
//

#include "Box.hpp"

    //Box   //Box

std::ostream& operator<<(std::ostream& os, const Box& aBox){
    os<<"Hello, I'm a box"<<std::endl;
    os<<"index: "<<aBox.index<<"\t length: "<<aBox.length<<"\t level: "<<aBox.level<<std::endl;
    os<<"edge: \n"<<"x: "<<aBox.edge.x<<std::endl<<"y: "<<aBox.edge.y<<std::endl<<"z: "<<aBox.edge.z<<std::endl<<std::endl;
    return os;
}



    //Tree   //Tree

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
    std::cout<<"end for now \n";
}

//assigns children to a box
bool Tree::assign_children(Box *aBox){
    
    //find a starting index of the children boxes:
    int parent_level = aBox->level;
    int parent_index = aBox->index;
    int parent_row_length = std::pow(2,parent_level);
    int parent_layer_length = std::pow(parent_row_length,2);
    
    int child_level = parent_level+1;
    int child_row_length = std::pow(2,child_level);
    int child_layer_length = std::pow(child_row_length,2);
    
    int parent_z_in = parent_index/parent_layer_length;
    int parent_y_in = (parent_index-parent_z_in*parent_layer_length)/parent_row_length;
    int parent_x_in = parent_index - parent_z_in*parent_layer_length - parent_y_in*parent_row_length;
    
    int child_start_index = child_layer_length*parent_z_in + child_row_length*parent_y_in + 2*parent_x_in;
    
    int child_indexes[8] = {child_start_index,child_start_index+1,child_start_index+child_row_length,child_start_index+child_row_length+1,child_start_index+child_layer_length,child_start_index+child_layer_length+1};
    
     
    
    return 1;
}

//creates a new box based on the parameters pased
Box* Tree::new_Box_childfree(Geometry::Coordinate anEdge, int aLevel ,int anIndex, Box* aParent){
    
    Box* aBox = new Box;
    aBox->edge = anEdge;
    aBox->level = aLevel;
    aBox->index = anIndex;
    aBox->length = get_length(aLevel);
    if(aParent!= NULL){aBox->parent = aParent;}
    
    return aBox;
}

//returns length of a box based on its level
double Tree::get_length(int aLevel){
    return(this->D*std::pow(2,-1*aLevel));
}
