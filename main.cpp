//
//  main.cpp
//  Fast evaluation of Helmholtz potential
//
//  Created by Eduard on 4/30/23.
//


#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>

#include "Space.hpp"
#include "Box.hpp"


void test(){
    int first[2][2][2];
    
    int counter = 0;
    
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            for(int k = 0; k<2; k++){
                first[i][j][k] = counter;
                std::cout<<first[i][j][k]<<" ";
                counter++;
            }
            std::cout<<std::endl;
        }
        std::cout<<"\n";
    }
    std::cout<<"\n\n";
    
    int second[4][4][4];
    
    counter = 0;
    
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            for(int k = 0; k<4; k++){
                second[i][j][k] = counter;
                std::cout<<second[i][j][k]<<" ";
                counter++;
            }
            std::cout<<std::endl;
        }
        std::cout<<"\n";
    }
    std::cout<<"\n\n";
    
    int third[8][8][8];
    
    counter = 0;
    
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            for(int k = 0; k<8; k++){
                third[i][j][k] = counter;
                std::cout<<third[i][j][k]<<" ";
                counter++;
            }
            std::cout<<std::endl;
        }
        std::cout<<"\n";
    }
    std::cout<<"\n\n";
}




int main() {


    std::cout<<"Start program \n";

    Tree theTree(1024,4);

    //theTree.print_tree();
    Box* testing1 = theTree.find_box_by_index(4, 160, 1);
    std::cout<<"Testing the box: "<<*testing1;
    
    Geometry::Coordinate aCoordinate1(1000,650,3.3);
    
    Box* testing2 = theTree.find_box_by_coordinate(4, aCoordinate1, 1);
    std::cout<<"Testing the box: "<<*testing2;

    
   
    return 0;
}
 
/*
 ToDo:
 - Makefile
 
 */
