//
// Created by fernando on 29/04/19.
//

#ifndef PROJETOFINALAPA_GREEDY_CONSTRUCTION_H
#define PROJETOFINALAPA_GREEDY_CONSTRUCTION_H

#include <vector>
#include <queue>

#include "../Graph/graph_adjacency_list.h"

class GreedyConstruction
{

    std::priority_queue < std::pair< int, int >,
            std::vector< std::pair< int, int > >, std::greater< std::pair< int, int > > > pq;
    GraphAdjacencyList *graph;
    int size;
public:
    GreedyConstruction(GraphAdjacencyList *graph, int size );

    int* build( int origin, int *solution );
};


#endif //PROJETOFINALAPA_GREEDY_CONSTRUCTION_H
