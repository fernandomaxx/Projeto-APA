//
// Created by fernando on 01/05/19.
//

#include "vnd.h"

VND::VND( GraphAdjacencyMatrix *graph ):
        graph{ graph }
{}

void VND::localSearch( int *solution, int evaluation, int size )
{
    std::vector< NeighborStructure* > ns;
    ns.push_back( new TwoOpt( graph ) );
    ns.push_back( new Swap( graph ) );

    int k = 0, new_evaluation;
    while ( k < ns.size() )
    {
        new_evaluation = ns[k]->localSearch( solution, evaluation, size );

        if ( new_evaluation < evaluation )
            evaluation = new_evaluation,
            k = 0;
        else
            k++;
    }
}
