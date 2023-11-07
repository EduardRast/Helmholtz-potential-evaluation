//
//  Source.cpp
//  Helmholtz-potential-evaluation
//
//  Created by Eduard on 10/2/23.
//

#include "Source.hpp"


std::ostream& operator<<(std::ostream& os, const Source& aSource){
    os << "Coordinate: " << aSource.aCoordinate.x << "\t" << aSource.aCoordinate.y << "\t" << aSource.aCoordinate.z << "\t\t"
    << "Charge: " << aSource.charge << std::endl;
    return os;
}


bool Distribution::get_sources(){
    std::ifstream dataList;
    dataList.open("sources.txt");
    while(dataList){
        std::string dataString;
        std::getline (dataList, dataString);
        std::cout<<dataString<<std::endl;

    }

    return 0;
}

bool Distribution::get_sources_mockup(){

    for (int i = 0; i < 10; i++){
        Source aSource;
        aSource.aCoordinate = Coordinate(i*3.14, i*2.7, i*9.8);
        aSource.charge = i;
        sourceList.push_back(aSource);
    }

    return 0;
}

bool Distribution::print_sources(){

    for(int i = 0; i<sourceList.size();i++){
        std::cout << sourceList.at(i);
    }

    return 0;
}