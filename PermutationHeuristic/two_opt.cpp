//
// Created by fernando on 30/04/19.
//

#include <cstdlib>
#include "two_opt.h"

TwoOpt::TwoOpt( GraphAdjacencyMatrix *graph ):
        graph{ graph }
{}

int TwoOpt::localSearch( int *solution, int evaluation, int size )
{
    int new_evaluation;


    for ( int i = 0; i < size - 2; i++ )
    {
        for ( int j = i + 2; j < size; j++ )
        {
            new_evaluation = evaluation;

            new_evaluation = new_evaluation - ( graph->matrix[solution[i]][solution[i+1]] + graph->matrix[solution[j]][solution[j-1]] );
            new_evaluation = new_evaluation + graph->matrix[solution[i]][solution[j-1]] + graph->matrix[solution[j]][solution[i+1]];

            if ( new_evaluation < evaluation )
            {
                evaluation = new_evaluation;

                int k = i+1, l = j-1;

                while ( k < l )
                {
                    swap( solution, k, l );
                    k++;
                    l--;
                }
            }
        }
    }

    return evaluation;
}
