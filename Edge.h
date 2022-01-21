#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <vector>


class edge {

    const std::string Previous_Node;
    const std::string Next_Node;
    const double Value_Edge;


    public:


    edge(const std::string Previous_Node, const std::string Next_Node, const double Value_Edge) ;
    
    
    double value();


    std::string previous() const;


    std::string next() const;


};