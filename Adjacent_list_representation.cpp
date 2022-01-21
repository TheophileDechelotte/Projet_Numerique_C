#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include "Adjacent_list_representation.h"
#include "Edge.h"

int dimension = 4 ;

AdjacentListRepresentation::AdjacentListRepresentation(std::unordered_map<std::string, std::vector<edge> > AdjList)  : 
AdjList(AdjList)
{}
    

int AdjacentListRepresentation::size() const {
    return AdjList.size();
}


std::unordered_map<std::string, std::vector<edge> > AdjacentListRepresentation::Get_Dict_List() const {
    return AdjList;
}


std::vector<edge> AdjacentListRepresentation::at(const std::string& s) const{
    return AdjList.at(s);
}


std::unordered_map<std::string, int> AdjacentListRepresentation::Keys_of_Index(std::vector<std::string> Nodes){
    //Cette fonction prend en parametre la liste des sommets et donne le dictionnaire qui au nom d'un sommet associe un numéro, son indice
    std::unordered_map<std::string, int> Dict_index;
    for (int i = 0; i < Nodes.size(); i++){
        Dict_index.insert({Nodes[i], i});
    }
    return Dict_index;
}


AdjacentMatrixRepresentation AdjacentListRepresentation::ListToMatrix(const AdjacentListRepresentation& list){

    std::vector<double> graph_matrix;
    std::vector<std::string> Nodes;

    //Commencons par remplir les noms des sommets: on parcourt à la liste en récupérant les keys du dictionnaire et on les ajoute au vecteurs Nodes        
    
        std::unordered_map<std::string, std::vector<edge> > Dict = list.Get_Dict_List();
        
        for (std::unordered_map<std::string, std::vector<edge> >::iterator it=Dict.begin(); it!=Dict.end(); it++){
            Nodes.push_back(it -> first);
        }
    
    //On crée également le dictionnaire qui à un sommet associe son indice dans la matrice       
    
        std::unordered_map<std::string, int> dict_indexNodes = Keys_of_Index(Nodes);
    
    
    //Construisons désormais notre liste vector graph

        //On commence par l'initialiser avec des 0
        
        int dim = list.size();

        for (int i = 0; i < dim; i++){
            for (int j = 0; j < dim; j++){
                graph_matrix.push_back(0.);
            }
        }
        
        //Puis lorsque edge existe entre s_i et s_j on y met la valeur du edge
        for (int k = 0; k < dim; k++){
            std::vector<edge> list_edges = list.at(Nodes[k]);
            for (int l = 0; l < list_edges.size(); l++){
                edge edge = list_edges[l];
                graph_matrix.at(l * dim + dict_indexNodes.at(edge.next())) = edge.value();
            }
        }

    AdjacentMatrixRepresentation matrix(graph_matrix, Nodes);

    return matrix;
}


double AdjacentListRepresentation::edgeAccess(std::string Previous_Node, std::string Next_Node, std::unordered_map<std::string, std::vector<edge> > dictOfEdges){
    
    for(edge edgeAdress: dictOfEdges[Next_Node]){
        edge edge = edgeAdress;
        if( edge.previous() != Previous_Node){
            continue;
        }
        else{
            return edge.value() ;
        }
    }
    return std::nan("");
}


void AdjacentListRepresentation::print(std::unordered_map<std::string, std::vector<edge> > dictOfEdges){
    std::vector<std::string> keys;
    // Je construis ici la liste des clés de la unordered_map.
    keys.reserve(dictOfEdges.size());
    for (const auto& kv : dictOfEdges ){
        keys.push_back(kv.first);
    }
    int i = 0;
    for(int i =0; i!=dimension; i++ ){
        int j = 0; 
        for(int j =0; j!=dimension; j++ ){
            std::cout << keys[i] << " -> "<< keys[j] << ": " << edgeAccess(keys[i],keys[j], dictOfEdges) << std::endl;
        }
    }
}


void AdjacentListRepresentation::printmatrix(std::unordered_map<std::string, std::vector<edge> > dictOfEdges){
    std::vector<std::string> keys;
    // Je construis ici la liste des clés de la unordered_map.
    keys.reserve(dictOfEdges.size());
    for (const auto& kv : dictOfEdges ){
        keys.push_back(kv.first);
    }
    int i = 0;
    for(int i =0; i!=dimension; i++ ){
        int j = 0; 
        for(int j =0; j!=dimension; j++ ){
            std::cout << edgeAccess(keys[i],keys[j], dictOfEdges);
        }
        printf("\n");
    }
}


