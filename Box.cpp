//
//  Box.cpp
//  Helmholtz-potential-evaluation
//
//  Created by Eduard on 5/18/23.
//

#include "Box.hpp"

    //Box   //Box

std::ostream& operator<<(std::ostream& os, const Box& aBox){
   // os<<"Hello, I'm a box"<<std::endl;
    os<<"index: "<<aBox.index<<"\t"<<" length: "<<aBox.length<<"    ";
    if(aBox.parent!=NULL){std::cout<<"parent index: "<<aBox.parent->index<<"\t\t";}
    os<<"edge: \t"<<"x: "<<aBox.edge.x<<"\t"<<"y: "<<aBox.edge.y<<"\t"<<"z: "<<aBox.edge.z<<std::endl;
    return os;
}



    //Tree   //Tree

//constructor
Tree::Tree(double Dp, int Lp, float Gp){
    
    //setting up parameters
    std::cout<<"Generating tree ... ";
    this->D = Dp;
    this->L = Lp;
    this->g = Gp;
    
    //initializing the tree
    root = new_Box_childfree(Geometry::Coordinate(0,0,0), 0, 0);
//    assign_children(root);
    
    assign_branch(root);
    root->parent = NULL;
    
    std::cout<<"tree initialized \n";
}

//assign branch to the box
bool Tree::assign_branch(Box* aBox){
    if (aBox->level==(L)){ return 1;}
    assign_children(aBox);
    for(int i = 0; i<8; i++){
        assign_branch(aBox->children[i]);
    }
    
    return 1;
}

//assigns children to a box
bool Tree::assign_children(Box *aBox){
    
    //find indexes of the children boxes:
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
    
    int child_start_index = child_layer_length*parent_z_in*2 + child_row_length*parent_y_in*2 + parent_x_in*2;
    
    int child_indexes[8] = {
        child_start_index,
        child_start_index+1,
        child_start_index+child_row_length,
        child_start_index+child_row_length+1,
        child_start_index+child_layer_length,
        child_start_index+child_layer_length+1,
        child_start_index+child_layer_length+child_row_length,
        child_start_index+child_layer_length+child_row_length+1
    };
    
     //find coordinates of the edges of the boxes
    double parent_x = aBox->edge.x;
    double parent_y = aBox->edge.y;
    double parent_z = aBox->edge.z;
    double child_length = get_length(child_level);
    
    Geometry::Coordinate list_of_edges[8] =
        {Geometry::Coordinate(parent_x,parent_y,parent_z),
         Geometry::Coordinate(parent_x+child_length,parent_y,parent_z),
         Geometry::Coordinate(parent_x,parent_y+child_length,parent_z),
         Geometry::Coordinate(parent_x+child_length,parent_y+child_length,parent_z),
         Geometry::Coordinate(parent_x,parent_y,parent_z+child_length),
         Geometry::Coordinate(parent_x+child_length,parent_y,parent_z+child_length),
         Geometry::Coordinate(parent_x,parent_y+child_length,parent_z+child_length),
         Geometry::Coordinate(parent_x+child_length,parent_y+child_length,parent_z+child_length)
        };
    
    //assigning the children
    
    for (int i = 0; i<8;i++){
        aBox->children[i] = new_Box_childfree(list_of_edges[i], child_level, child_indexes[i],aBox);
    }
    
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
    for (int i = 0; i<8; i++){
        aBox->children[i] = NULL;
    }

    return aBox;
}

//returns length of a box based on its level
double Tree::get_length(int aLevel){
    return(this->D*std::pow(2,-1*aLevel));
}

//find box by index and level
Box* Tree::find_box_by_index(int level, int index){
    //initializing the variables
    int row_length,layer_lenght,number_layers,number_double_layers,number_rows,number_double_rows,number_boxes,number_double_boxes,parent_layer_length,parent_row_length,parent_index,child_index;
    int current_index = index;
    int current_level = level;
    std::vector<int> parent_child_index;
    Box* current = root;
    
    //find index of a child in a parent until root
    while(current_level!=0){
        
        row_length = std::pow(2,current_level);
        layer_lenght = std::pow(row_length,2);
        number_layers = current_index/layer_lenght;
        number_double_layers = number_layers/2;
        number_rows = (current_index-number_layers*layer_lenght)/row_length;
        number_double_rows = number_rows/2;
        number_boxes = current_index - number_layers*layer_lenght - number_rows*row_length;
        number_double_boxes = number_boxes/2;
        parent_row_length = std::pow(2,current_level-1);
        parent_layer_length = std::pow(parent_row_length,2);
        
        parent_index = number_double_layers*parent_layer_length + number_double_rows*parent_row_length+number_double_boxes;
        
        child_index = (number_layers - number_double_layers*2)*4 + (number_rows-number_double_rows*2)*2 + (number_boxes - number_double_boxes*2);
        parent_child_index.push_back(child_index);
        
        current_level--;
        current_index = parent_index;
    }
    
    //traverse the tree to find the box
    for(int i = (int)parent_child_index.size()-1; i>=0;i--){
        int a = parent_child_index.at(i);
        current = current->children[a];
    }
    
    //check
    if (current->index == index && current->level == level)
    {return current;}
    
    return 0;
}

//Printing

void Tree::print_tree(int levels){
    std::cout<<"printing the tree: \n";
    
    std::cout<<"root: "<<*(root)<<"\n";
    std::cout<<"\n\n\n";
    
    std::cout<<"Level 1:\n";
    Box* current = root;
    for(int i = 0; i<8; i++){
        std::cout<<*(current->children[i]);
    }
    std::cout<<"\n\n\n";
    
    std::cout<<"Level 2:\n";
    for(int i = 0; i<8; i++){
        Box* current_1 = current->children[i];
        for(int j = 0; j<8; j++){
        std::cout<<*(current_1->children[j]);
        }
        std::cout<<"\n";
    }
    std::cout<<"\n\n\n";
    

    std::cout<<"Level 3:\n";
    for(int i = 0; i<8; i++){
        Box* current_1 = current->children[i];
        for(int j = 0; j<8; j++){
            Box* current_2 = current_1->children[j];
            for(int k = 0; k<8; k++){
                std::cout<<*(current_2->children[k]);
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n\n\n";

/*
    std::cout<<"Level 4:\n";
    for(int i = 0; i<8; i++){
        Box* current_1 = current->children[i];
        for(int j = 0; j<8; j++){
            Box* current_2 = current_1->children[j];
            for(int k = 0; k<8; k++){
                Box* current_3 = current_2->children[k];
                for(int n = 0; n<8; n++){
                    std::cout<<*(current_3->children[n]);
                }
                std::cout<<"\n";
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n\n\n";
*/
}
