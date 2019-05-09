//
// Created by fernando on 01/05/19.
//

#ifndef PROJETOFINALAPA_VND_H
#define PROJETOFINALAPA_VND_H

#include "two_opt.h"
#include "swap.h"
#include <vector>


class VND
{
public:

    VND( GraphAdjacencyMatrix *graph );

    void localSearch( int *solution, int evaluation, int size );

private:

    GraphAdjacencyMatrix *graph;
};


#endif //PROJETOFINALAPA_VND_H
