#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include "Edge.h"
#include "Adjacent_list_representation.h"

class AdjacentListRepresentation ;


class AdjacentMatrixRepresentation {
    
    private :
    
    std::vector<double> graph;
    std::vector<std::string> Nodes;


    public:


    AdjacentMatrixRepresentation (std::vector<double> graph, std::vector<std::string> Nodes);

    
    std::vector<edge> get_edges(std::string& node);


    std::vector<std::string> getNodes() const ;


    std::vector<double> getGraph() const ;


    double at(int i, int j) const ;


    std::unordered_map<int, std::string> Index_of_Keys(std::vector<std::string> Nodes) ;


    AdjacentListRepresentation MatrixToList(const AdjacentMatrixRepresentation& matrix) ;


    void print() ;

};