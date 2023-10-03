//
//  Source.hpp
//  Helmholtz-potential-evaluation
//
//  Created by Eduard on 10/2/23.
//

#ifndef Source_hpp
#define Source_hpp

#include <iostream>
#include "Coordinate.hpp"

struct Source{
    //OCF
    Source();
    Source(const Source &aSource);
    Source& operator = (const Source &aSource);
    ~Source();
    //~OCF
        
    //variables
    int charge;
    Coordinate aCoordinate;
    
};


#endif /* Source_hpp */
