//
//  main.cpp
//  Fast evaluation of Helmholtz potential
//
//  Created by Eduard on 4/30/23.
//

#include <iostream>


#include "Space.hpp"





int main() {

    std::cout << "Hello, World!\n";
    Geometry::Space TheSpace(2);
    std::cout << TheSpace.size <<std::endl;
    
    //print random coordinate:
    Geometry::Coordinate aCoordinate = TheSpace.generate_random_coordinates();
    
    std::cout<<aCoordinate.x<<" "<<aCoordinate.y<<" "<<aCoordinate.z<<std::endl;
    
    
    return 0;
}
 
/*
 Next steps:
 - create struct of a box
 - create a coordinate sub struct
 - create particles class
 */
