//
// Created by fernando on 30/04/19.
//

#include "best_insertion.h"

BestInsertion::BestInsertion( GraphAdjacencyList *graph, GraphAdjacencyMatrix *graph_m, int size ):
        graph( graph ),
        graph_m( graph_m ),
        size( size )
{}

int BestInsertion::build( int origin, int *solution )
{
    int processed[size], count = 1;
    solution[0] = origin;
    processed[origin] = 1;

    for ( int i = 1; i < size; i++ )
        processed[i] = 0;

    int less = 100000000;
    int value = -1;
    //std::cout << graph->adj[0].size() << std::endl;
    for ( int i = 0; i < graph->adj[0].size(); i++ )
    {
        int first = graph->adj[0][i].first;
        int second = graph->adj[0][i].second;
        if ( !processed[first] and second < less )
            less = second,
            value = first;
    }

    processed[value] = 1;
    solution[count++] = value;

    int matrix[2][size];

    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < size; ++i) {
            matrix[j][i] = 100000000;
        }
    }

    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < graph->adj[0].size(); ++i) {
            matrix[j][graph->adj[j][i].first] = graph->adj[j][i].second;
        }
    }

    less = 100000000;
    for ( int i = 0; i < size; i++)
    {
        int second = matrix[0][i] + matrix[1][i];
        if ( !processed[i] and second < less )
            less = second,
            value = i;
    }

    processed[value] = 1;
    solution[count++] = value;

//    for (int j = 0; j < size; ++j)
//        std::cout << solution[j] << " ";
//    std::cout << "\n";
    for (int i = count; i < size; ++i) {

        int a, b;
        value = -1;
        less = 100000000;
        for (int j = 1; j < size; ++j) {

            if ( !processed[j] )
            {
//                std::cout << j << "\n";
                int dist[count];
                for (int k = 0; k < count; ++k) {
                    dist[k] = graph_m->matrix[solution[k]][j];

//                    std::cout << dist[k] << " ";
                }
//                std::cout << "\n";

                for (int k = 0; k < count - 1; ++k) {
                    if ( dist[k] + dist[k + 1] < less)
                        a = k, b = k + 1, value = j,
                        less = dist[k] + dist[k + 1];
                }

                if ( dist[count - 1] + dist[0] < less)
                    a = count - 1, b = 0, value = j,
                    less = dist[0] + dist[a];
            }
        }
        //std::cout << "\n" << less << "\n";
        processed[value] = 1;
//        std::cout << a << " "<< b << std::endl;
//        for (int j = 0; j < 5; ++j)
//            std::cout << solution[j] << " ";
//        std::cout << std::endl;

        if ( b != 0)
        {
            for (int j = count; j >= b; --j)
            {
                solution[j + 1] = solution[j];
            }

            solution[b] = value;
            count++;
        }
        else
        {
            solution[count++] = value;
        }

    }

//    for (int j = 0; j < size; ++j)
//        std::cout << solution[j] << " ";
//    std::cout << std::endl;

}
