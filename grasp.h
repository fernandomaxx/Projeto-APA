//
// Created by petcomputacao on 09/05/19.
//

#ifndef PROJETOFINALAPA_GRASP_H
#define PROJETOFINALAPA_GRASP_H

#include "Graph/graph_adjacency_list.h"
#include "Graph/graph_adjacency_matrix.h"
#include "PermutationHeuristic/vnd.h"
#include <time.h>
#include <algorithm>
#include <vector>
#include <queue>

class Grasp
{
public:
    Grasp( GraphAdjacencyList *graph, GraphAdjacencyMatrix *graph_m ,int size );
    int procedimento( int it, float alfa, int * solution );
    int Build( int origin, int *solution, float alfa );
    int evaluation( GraphAdjacencyMatrix *graph_m, const int *solution, int size );

    GraphAdjacencyList *graph;
    GraphAdjacencyMatrix *graph_m;
    VND *vnd;
    int size;

};


#endif //PROJETOFINALAPA_GRASP_H
