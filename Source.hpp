//
//  Source.hpp
//  Helmholtz-potential-evaluation
//
//  Created by Eduard on 10/2/23.
//

#ifndef Source_hpp
#define Source_hpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Coordinate.hpp"

struct Source{
    //OCF
    Source(){}
    //Source(const Source &aSource); -TODO fix the bug (WHEN THE COPY CONSTRUCTOR IS added, the code does not compile)
    Source& operator = (const Source &aSource);
    ~Source(){}
    //~OCF
        
    //variables
    int charge;
    Coordinate aCoordinate;

    friend std::ostream& operator<<(std::ostream& os, const Source& aSource);
};

class Distribution{
public:
     //OCF
    Distribution(){}
    Distribution(const Distribution &aDistribution);
    Distribution& operator = (const Distribution &aDistribution);
    ~Distribution(){}
    //~OCF

    bool get_sources(); //method to read the sources from the sources.txt file and 
    bool get_sources_mockup(); //placeholder for the sources recieving

    bool print_sources(); // prints the list of sources

    std::vector<Source> sourceList; // list containiing all the sourcs in the distribution


};

#endif /* Source_hpp */
