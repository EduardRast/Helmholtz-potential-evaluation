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



int main() {

//    std::cout << "Hello, World!\n";
    Geometry::Space TheSpace(3);
//    std::cout << TheSpace.size <<"\n";
    
    //print random coordinates:
/*
    
    Geometry::Coordinate aCoordinate1 = TheSpace.generate_random_coordinate(1);
    std::cout<<aCoordinate1.x<<" "<<aCoordinate1.y<<" "<<aCoordinate1.z<<std::endl;
    
    Geometry::Coordinate aCoordinate2 = TheSpace.generate_random_coordinate();
    std::cout<<aCoordinate2.x<<" "<<aCoordinate2.y<<" "<<aCoordinate2.z<<std::endl;
    
    Geometry::Coordinate aCoordinate3 = TheSpace.generate_random_coordinate();
    std::cout<<aCoordinate3.x<<" "<<aCoordinate3.y<<" "<<aCoordinate3.z<<std::endl;
    
 */
    
    //generate and print random charges vector:
    TheSpace.generate_uniform_random_charges(20);
    
    for(int i = 0; i<TheSpace.charges.size();i++){
        std::cout<<"Charge: "<<TheSpace.charges.at(i).charge<<"\tCoordinate: {"<<TheSpace.charges.at(i).aCoordinate.x<<","<<TheSpace.charges.at(i).aCoordinate.y<<","<<TheSpace.charges.at(i).aCoordinate.z<<"}\n";
    }

    
    return 0;
}
 
/*
 Next steps:
 - create struct of a box
 - create a coordinate sub struct
 - create particles class
 */
