#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include "Edge.h"
#include "Adjacent_matrix_representation.h"


class AdjacentMatrixRepresentation ;


class AdjacentListRepresentation{

    std::unordered_map<std::string, std::vector<edge> > AdjList;

    public:


    AdjacentListRepresentation(std::unordered_map<std::string, std::vector<edge> > AdjList) ;
    

    int size() const ;


    std::unordered_map<std::string, std::vector<edge> > Get_Dict_List() const ;


    std::vector<edge> at(const std::string& s) const ;


    std::unordered_map<std::string, int> Keys_of_Index(std::vector<std::string> Nodes) ;


    AdjacentMatrixRepresentation ListToMatrix(const AdjacentListRepresentation& list) ;
    

    double edgeAccess(std::string Previous_Node, std::string Next_Node, std::unordered_map<std::string, std::vector<edge> > dictOfEdges) ;


    void print(std::unordered_map<std::string, std::vector<edge> > dictOfEdges) ;


    void printmatrix(std::unordered_map<std::string, std::vector<edge> > dictOfEdges) ;

};

