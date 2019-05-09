//
// Created by fernando on 29/04/19.
//

#include "greedy_construction.h"

GreedyConstruction::GreedyConstruction( GraphAdjacencyList *graph, int size ) :
        graph( graph ),
        size( size )
{}

int* GreedyConstruction::build( int origin, int *solution )
{

    int processed[size], actual, count = 0;
    std::vector< int > C( size );

    for ( int i = 0; i < size; i++ )
        solution[i] = 0,
        processed[i] = 0,
        C[i] = i;

    pq.push( std::make_pair( 0, origin ));

    while ( true )
    {

        actual = -1;

        while ( !pq.empty() )
        {
            int temp = pq.top().second;
            pq.pop();

            if ( !processed[temp] )
            {
                processed[temp] = 1;
                actual = temp;
                solution[count++] = temp;
                //C.erase( C.begin() + actual );
                for ( int i = 0; i < C.size(); i++ )
                    if ( C[i] == actual )
                        C.erase( C.begin() + i );
                while(!pq.empty()) pq.pop();
                break;
            }
        }

        if ( actual == -1 )
            break;

        for ( int i = 0; i < C.size(); i++ )
        {
            pq.push( std::make_pair( graph->adj[actual][C[i]].second, C[i] ));
        }
    }

}
