#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "Edge.h"



edge::edge(const std::string Previous_Node, const std::string Next_Node, const double Value_Edge) : 
Previous_Node(Previous_Node), 
Next_Node(Next_Node), 
Value_Edge(Value_Edge){}


double edge::value(){
    return Value_Edge;
}

std::string edge::previous() const{
    return Previous_Node;
}

std::string edge::next() const{
    return Next_Node;
}