//
// Created by fernando on 01/05/19.
//

#ifndef PROJETOFINALAPA_SWAP_H
#define PROJETOFINALAPA_SWAP_H

#include "../Graph/graph_adjacency_matrix.h"
#include "neighbor_struct.h"


class Swap: public NeighborStructure
{
public:

    explicit Swap( GraphAdjacencyMatrix *graph );

    int localSearch( int *solution, int evaluation, int size ) override;

private:

    GraphAdjacencyMatrix *graph;

};


#endif //PROJETOFINALAPA_SWAP_H
