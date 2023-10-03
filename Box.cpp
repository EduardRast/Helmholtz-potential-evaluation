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


