//
// Created by petcomputacao on 09/05/19.
//

#include "grasp.h"

Grasp::Grasp(GraphAdjacencyList *graph, GraphAdjacencyMatrix *graph_m, int size):
        graph{ graph },
        graph_m{ graph_m },
        size{ size }
{
    vnd = new VND( graph_m );
}

int Grasp::Build(int origin, int *solution, float alfa )
{

    int processed[size], actual, count = 0;
    std::vector< int > C( size );
    std::vector< std::pair < int, int >> V( size );

    for ( int i = 0; i < size; i++ )
        solution[i] = 0,
        processed[i] = 0,
        C[i] = i;

    //pq.push( std::make_pair( 0, origin ));
    V.push_back( std::make_pair( 0, origin ));

    while ( true )
    {

        actual = -1;

        while ( !V.empty() )
        {
            //int temp = pq.top().second;
            //pq.pop();
            srand( (unsigned)time(NULL) );
            int gt_min = 0;
            int gt_max = V.size() - 1;
            int LCR = gt_min + alfa * ( gt_max - gt_min );
            int id = rand() % (LCR + 1);
            int temp = V[id].second;

            if ( !processed[temp] )
            {
                processed[temp] = 1;
                actual = temp;
                solution[count++] = temp;
                //C.erase( C.begin() + actual );
                for ( int i = 0; i < C.size(); i++ )
                    if ( C[i] == actual )
                    {
                        C.erase(C.begin() + i);
                        break;
                    }
                //while(!pq.empty()) pq.pop();
                V.clear();
                break;
            }
        }

        if ( actual == -1 )
            break;

        for ( int i = 0; i < C.size(); i++ )
        {
            //pq.push( std::make_pair( graph->adj[actual][C[i]].second, C[i] ));
            V.push_back( std::make_pair( graph->adj[actual][C[i]].second, C[i]) );
        }
        sort(V.begin(), V.end());
    }
}

int Grasp::procedimento(int it, float alfa, int *solution) {
    int evaluation = 10000000;

    for ( int i = 0; i < it; i++ )
    {
        int new_solution[size];
        this->Build( 0.5, new_solution, alfa);
        this->vnd->localSearch( new_solution, this->evaluation( graph_m, new_solution, size), size);
        int temp_evaluation = this->evaluation( graph_m, new_solution, size);
        if ( temp_evaluation < evaluation )
        {
            evaluation = temp_evaluation;
            /*for (int j = 0; j < size; ++j)
            {
                solution[j] = new_solution[j];
            }*/
        }

    }
    return evaluation;
}

int Grasp::evaluation( GraphAdjacencyMatrix *graph_m, const int *solution, int size )
{
    int sum = 0, v1, v2;

    for (int i = 0; i < size - 1; ++i) {
        v1 = solution[i];
        v2 = solution[i + 1];
        sum += graph_m->matrix[v1][v2];
    }
    sum += graph_m->matrix[solution[0]][solution[size - 1]];
    return sum;
}
