//
// Created by fernando on 01/05/19.
//

#include "neighbor_struct.h"

void NeighborStructure::swap( int *s, int i, int j )
{
    int aux = s[i];
    s[i] = s[j];
    s[j] = aux;
}
