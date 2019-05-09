//
// Created by fernando on 01/05/19.
//

#include "swap.h"

Swap::Swap( GraphAdjacencyMatrix *graph ):
        graph{ graph }
{}

int Swap::localSearch( int *solution, int evaluation, int size )
{
    int new_evaluation;

    int it = 1000;
    srand(time(nullptr));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if ( i == j )
                continue;
            new_evaluation = evaluation;

            int i_sub = (i - 1 < 0) ? size - 1 : i - 1;
            int i_add = (i + 1 == size) ? 0 : i + 1;
            int j_sub = (j - 1 < 0) ? size - 1 : j - 1;
            int j_add = (j + 1 == size) ? 0 : j + 1;

            int w, x, y, z;
            w = graph->matrix[solution[i_sub]][solution[i]];
            x = graph->matrix[solution[i]][solution[i_add]];
            y = graph->matrix[solution[j_sub]][solution[j]];
            z = graph->matrix[solution[j]][solution[j_add]];

            new_evaluation = new_evaluation - (w + x + y + z);

            swap(solution, i, j);

            w = graph->matrix[solution[i_sub]][solution[i]];
            x = graph->matrix[solution[i]][solution[i_add]];
            y = graph->matrix[solution[j_sub]][solution[j]];
            z = graph->matrix[solution[j]][solution[j_add]];

            new_evaluation = new_evaluation + (w + x + y + z);

            if (new_evaluation >= evaluation) {

                swap(solution, i, j);

            } else
                evaluation = new_evaluation;
        }
    }

    return evaluation;

}
