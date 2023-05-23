//
//  Space.cpp
//  Fast evaluation of Helmholtz potential
//
//  Created by Eduard on 5/1/23.
//

#include <random>
#include "Space.hpp"

using namespace Geometry;


Coordinate Space::generate_random_coordinates(){
static bool check = 0;
int size = this->size;
static int** space = new int*[size];
    if(!check){
        
        for (int i = 0; i<size*size*size;i++){
            space[i] = new int[3];
        }
        
        for (int i = 0; i< size*size*size;){
            
            for (int z = 0; z<size; z++){
                
                for (int y = 0; y<size; y++){
                    
                    for (int x = 0; x<size; x++){
                        
                        space[i][0] = x;
                        space[i][1] = y;
                        space[i][2] = z;
                        //std::cout<<i<<" - "<<space[i][0] << " " << space [i][1] << " " << space[i][2] << "\n";
                        i++;
                    }
                }
            }
            
        }
       
       std::random_device rd;
       std::mt19937 g(rd());
       std::shuffle(&space[0][0],&space[size*size*size-1][2],g);
       check=1;
    }
    
    static int count = 0;
    
    Coordinate aCoordinate(space[count][0],space[count][1],space[count][2]);
    
    return aCoordinate;

    
    
}


int Space::get_size(){return size;}

