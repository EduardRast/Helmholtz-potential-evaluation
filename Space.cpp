//
//  Space.cpp
//  Fast evaluation of Helmholtz potential
//
//  Created by Eduard on 5/1/23.
//

#include "Space.hpp"
using namespace Geometry;

struct RandomCoordinateList{
    RandomCoordinateList(int size){
        int space[size][3];
            for (int z = 0; z<size; z++){
                for (int y = 0; y<size; y++){
                    for (int x = 0; x<size; x++){
                        space[(z+y+x)][0] = x;
                        space[(z+y+x)][1] = y;
                        space[(z+y+x)][2] = z;
                    }
                }
            }
    };
    RandomCoordinateList(const RandomCoordinateList& aRandomCoordinateList){};
    ~RandomCoordinateList(){};
    
    
};
/*
Coordinate Space::generate_random_coordinates(){
    
}
*/
int Space::get_size(){return size;}

