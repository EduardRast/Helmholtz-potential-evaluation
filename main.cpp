//
//  main.cpp
//  Fast evaluation of Helmholtz potential
//
//  Created by Eduard on 4/30/23.
//

#include <iostream>

#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

#include "Space.hpp"





int main() {

    std::cout << "Hello, World!\n";
    Geometry::Space TheSpace(4);
    std::cout << TheSpace.size <<std::endl;
    
    int size = 5;
    int space[size*size*size][3];
    for (int i = 0; i< std::pow(size,3);){
        for (int z = 0; z<size; z++){
            for (int y = 0; y<size; y++){
                for (int x = 0; x<size; x++){
                    space[i][0] = x;
                    space[i][1] = y;
                    space[i][2] = z;
                    std::cout<<i<<" - "<<space[i][0] << " " << space [i][1] << " " << space[i][2] << "\n";
                    i++;
                }
            }
        }
    }
    
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(&space[0][0],&space[size*size*size-1][2],g);
    
    
    // print the result
    for (int row = 0; row < std::pow(size,3); ++row) {
        for (int col = 0; col < 3; ++col) {
            std::cout << space[row][col] << ' ';
        }
        std::cout << std::endl;
    }
    
    
    return 0;
}
 
/*
 Next steps:
 - create struct of a box
 - create a coordinate sub struct
 - create particles class
 */
