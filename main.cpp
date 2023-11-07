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
#include <chrono>

#include "Tree.hpp"
#include "Box.hpp"
#include "Source.hpp"
#include "Coordinate.hpp"


int main() {


    std::cout<<"Start program \n";
    
    auto start = std::chrono::high_resolution_clock::now();
    Tree theTree(4194304,4);
    auto stop  = std::chrono::high_resolution_clock::now();
    
    long duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
    
    std::cout<<"duration of generating a tree: "<<duration<<std::endl;

    //theTree.print_tree();
    Box* testing1 = theTree.find_box_by_index(4, 160, 1);
    std::cout<<"Testing the box: "<<*testing1;
    
    Coordinate aCoordinate1(1000,650,3.3);
    
    Box* testing2 = theTree.find_box_by_coordinate(4, aCoordinate1, 1);
    std::cout<<"Testing the box: "<<*testing2;

    Distribution theDistribution;
    theDistribution.get_sources_mockup();
    theDistribution.print_sources();
   
    return 0;
}
 
//https://github.com/nlohmann/json

//g++ main.cpp Box.cpp Coordinate.cpp Source.cpp Tree.cpp -o run

