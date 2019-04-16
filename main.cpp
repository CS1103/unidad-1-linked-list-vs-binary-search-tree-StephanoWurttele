#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include "LinkedList.h"
#include <chrono>
#include "BinarySearchTree.h"

// Nombres de archivos
const std::string LOCATION_FILE = "Locations.csv";
const std::string SEARCH_FILE = "Search.txt";

using namespace UTEC;

int main() {
    // Declarando variables
    LinkedList ll;
    BinarySearchTree bst;
    std::vector<int> vsearch;
    // Grabar Datos del archivo "Locations.csv" en ll
    // Grabar Datos del archivo "Locations.csv" en bst
    UTEC::load_locations(&ll,LOCATION_FILE);
    UTEC::load_locations(bst,LOCATION_FILE);
    // Leer los datos del archivo "Search.txt" y grabarlos en vsearch
    std::ifstream input(SEARCH_FILE);
    std::string temp;
    int x;
    while(input.eof()!=true){
        getline(input,temp);
        std::istringstream(temp)>>x;
        vsearch.push_back(x);
    }
    double avgtime_ll = 0;
    double avgtime_bst = 0;
    // Utilizar cada item de vsearch para buscar los lugares en ll y bsd
    // Calcular los tiempos promedios en cada caso
    for (int i=0;i<vsearch.size();i++) {
        // Buscar en ll
        auto start_point1=std::chrono::system_clock::now();
        ll.search(std::to_string(vsearch[i]));
        auto final_point1=std::chrono::system_clock::now();
        std::chrono::duration<double,std::nano>duration1=(final_point1-start_point1);
        avgtime_ll+=duration1.count();

        // Buscar en bsd
        auto start_point2=std::chrono::system_clock::now();
        bst.search(std::to_string(vsearch[i]));
        auto final_point2=std::chrono::system_clock::now();
        std::chrono::duration<double,std::nano>duration2=(final_point2-start_point2);
        avgtime_bst+=duration2.count();
    }
    std::cout<<"time for binary search "<<avgtime_bst/100<<" nanosegundos"<<std::endl<<"time for linked list "<<avgtime_ll/100<<" nanosegundos"<<std::endl;

    return 0;
    
}
