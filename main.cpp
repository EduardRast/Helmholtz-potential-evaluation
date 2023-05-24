//
//  main.cpp
//  Fast evaluation of Helmholtz potential
//
//  Created by Eduard on 4/30/23.
//

#include <iostream>
#include <vector>
#include <random>

#include "Space.hpp"



int main() {

    std::cout << "Hello, World!\n";
    Geometry::Space TheSpace(2);
    std::cout << TheSpace.size <<"\n";
    
    //print random coordinate:
    //Geometry::Coordinate aCoordinate = TheSpace.generate_random_coordinates();
    
    Geometry::Coordinate aCoordinate1(*get_rand());
    std::cout<<aCoordinate1.x<<" "<<aCoordinate1.y<<" "<<aCoordinate1.z<<std::endl;
    
    Geometry::Coordinate aCoordinate2(*get_rand());
    std::cout<<aCoordinate2.x<<" "<<aCoordinate2.y<<" "<<aCoordinate2.z<<std::endl;
    
    Geometry::Coordinate aCoordinate3(*get_rand());
    std::cout<<aCoordinate3.x<<" "<<aCoordinate3.y<<" "<<aCoordinate3.z<<std::endl;
    
    

    
    return 0;
}
 
/*
 Next steps:
 - create struct of a box
 - create a coordinate sub struct
 - create particles class
 */
