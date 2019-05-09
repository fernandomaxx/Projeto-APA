//
// Created by fernando on 30/04/19.
//

#ifndef PROJETOFINALAPA_BEST_INSERTION_H
#define PROJETOFINALAPA_BEST_INSERTION_H

#include "../Graph/graph_adjacency_list.h"
#include "../Graph/graph_adjacency_matrix.h"


class BestInsertion
{
    GraphAdjacencyList *graph;
    GraphAdjacencyMatrix *graph_m;
    int size;

public:
    BestInsertion( GraphAdjacencyList *graph, GraphAdjacencyMatrix *graph_m, int size );

    int build( int origin, int *solution );

};


#endif //PROJETOFINALAPA_BEST_INSERTION_H
