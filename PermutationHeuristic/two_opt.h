//
// Created by fernando on 30/04/19.
//

#ifndef PROJETOFINALAPA_TWO_OPT_H
#define PROJETOFINALAPA_TWO_OPT_H

#include "../Graph/graph_adjacency_matrix.h"
#include "neighbor_struct.h"

class TwoOpt: public NeighborStructure
{
public:

    explicit TwoOpt( GraphAdjacencyMatrix *graph );

    int localSearch( int *solution, int evaluation, int size ) override;

private:

    GraphAdjacencyMatrix *graph;
};


#endif //PROJETOFINALAPA_TWO_OPT_H
