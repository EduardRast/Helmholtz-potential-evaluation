//
//  Space.cpp
//  Fast evaluation of Helmholtz potential
//
//  Created by Eduard on 5/1/23.
//

#include <random>
#include <vector>
#include "Space.hpp"

using namespace Geometry;


Coordinate Space::generate_random_coordinates(bool print){
    static bool check = 1;
    static std::vector<Coordinate> space;
    if (check){
    int size = 500;
    for (int i = 0; i< size*size*size;){
        
        for (int z = 0; z<size; z++){
            
            for (int y = 0; y<size; y++){
                
                for (int x = 0; x<size; x++){
                    Coordinate aCoordinate(x,y,z);
                    space.push_back(aCoordinate);
                    i++;
                }
            }
        }
    }
    
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(space.begin(),space.end(),g);
        
    check = false;
    }
    if (print){
        for (int i = 0; i<space.size();i++){
                std::cout<<space[i].x<<" "<<space[i].y<<" "<<space[i].z;
            std::cout<<"\t";
        }
        std::cout<<std::endl;
    }
    
    static int current = 0;
    Coordinate theCoordinate(space.at(current).x,space.at(current).y,space.at(current).z);
    current++;
    return theCoordinate;

}


int Space::get_size(){return size;}

