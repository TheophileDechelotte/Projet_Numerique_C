#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include "Adjacent_list_representation.h"
#include "Adjacent_matrix_representation.h"


std::unordered_map<std::string, std::vector<edge> > read_points (std::string filename) {
    std::unordered_map<std::string, std::vector<edge> > empty;
        // chaque ligne du fichier contient la liste des coordonnées d'un point
        // on ouvre le fichier en lecture
    std::ifstream input_file(filename);
        // si problème d'ouverture de fichier on s'en va
    if (!input_file.is_open()) {
        std::cerr << "cannot open file '" << filename << "'" << std::endl;
        return empty;
    }
        // On initialise le dictionnaire contenant les arêtes
    std::unordered_map<std::string, std::vector<edge> > dictOfEdges;
    std::vector<std::string> lines;

        // on lit le fichier ligne par ligne

        // par souci de simplicité, on considère qu'on ne connait pas la
        // dimension des points, mais on pourrait la connaître en lisant la
        // première ligne et en comptant le nombre de coordonnées

        // la chaîne de caractères qui contient toute la ligne
    std::string line;
        // on va lire toutes les lignes du fichier: quand il n'y en aura
        // plus getline retournera 0

        // on lit la ligne et on met son contenu dans la variable line
    
    while(getline(input_file, line)) {

        std::cout << "analyse de la ligne " << line << std::endl;
            //On construit l'arête associée à la ligne
        lines.push_back(line);
    }
        
    for(std::string edgeLine: lines){
        std::string i;
        i += edgeLine.at(0);
        std::string j;
        j += edgeLine.at(2);
        std::cout << i << " -> " << j << " " << ":" << " " << edgeLine.at(4) << std::endl;
    }

    return dictOfEdges;
}




int main(int argc, char** argv){
  // je passe le nom du fichier en argument
    
    std::unordered_map<std::string, std::vector<edge> > dict = read_points(argv[1]) ;

    AdjacentListRepresentation graph(dict);

    //std::vector< std::vector<double> > mgraph= graph.changeRepresentation();

    graph.print(dict);

    graph.printmatrix(dict);

    return 0;


}
