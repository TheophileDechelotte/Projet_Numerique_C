#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include "Adjacent_matrix_representation.h"




AdjacentMatrixRepresentation::AdjacentMatrixRepresentation(std::vector<double> graph, std::vector<std::string> Nodes): 
graph(graph), 
Nodes(Nodes)
{}   


std::vector<edge> AdjacentMatrixRepresentation::get_edges(std::string& node){
    std::vector<edge> edges;
    std::unordered_map<int, std::string> Dict = Index_of_Keys(Nodes);
    for (int i = 0; i < Nodes.size(); i++){
        if( Dict.at(i) == node){
            for (int j = 0; j < Nodes.size(); j++){
                if(graph.at(i*Nodes.size() + j) != 0){
                    edge edge(Dict.at(i), Dict.at(j), graph.at(i*Nodes.size() + j));
                    edges.push_back(edge);
                }
            }
        }
    }
    return edges;
}


std::vector<std::string> AdjacentMatrixRepresentation::getNodes() const{
    return Nodes;
}


std::vector<double> AdjacentMatrixRepresentation::getGraph() const{
    return graph;
}


double AdjacentMatrixRepresentation::at(int i, int j) const{
    return graph[i*Nodes.size()+j];
}

std::unordered_map<int, std::string> AdjacentMatrixRepresentation::Index_of_Keys(std::vector<std::string> Nodes){
    //Cette fonction prend en parametre la liste des sommets et donne le dictionnaire qui au nom d'un sommet associe un numéro, son indice
    std::unordered_map<int, std::string> Dict_index;
    for (int i = 0; i < Nodes.size(); i++){
        Dict_index.insert({i, Nodes[i]});
    }
    return Dict_index;
}

AdjacentListRepresentation AdjacentMatrixRepresentation::MatrixToList(const AdjacentMatrixRepresentation& matrix){

    std::unordered_map<std::string, std::vector<edge> > AdjList;
    
    std::vector<std::string> Nodes = matrix.getNodes();
    std::vector<double> graph = matrix.getGraph();

    std::unordered_map<int, std::string> Dict_indexNodes = Index_of_Keys(Nodes);
    
    int dim = Nodes.size();
    for (int i = 0; i < dim; i++){
        AdjList.insert({Dict_indexNodes.at(i), {}}); //on insere le sommet associé à l'indice i, puis on va parcourir la ligne de la matrice associé à ce sommet pour voir ses sommets adjacents
        for (int j = 0; j < dim; j++){
            if( matrix.at(i, j) !=0){
                edge edge(Dict_indexNodes.at(i), Dict_indexNodes.at(j), matrix.at(i, j));
                AdjList.at(Dict_indexNodes.at(i)).push_back(edge);
            }
        }
    }

    return AdjList;
}


void print(std::vector< std::vector<double> > matrix){
        int i =0;
        for (int i = 0; i<matrix.size(); i++){
            int j = 0;
            for (int j = 0; j<matrix.size(); j++){
                std::cout << matrix[i][j];
            }
            printf("\n" );
        }
}
