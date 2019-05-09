//
// Created by fernando on 01/05/19.
//

#ifndef PROJETOFINALAPA_NEIGHBOR_STRUCT_H
#define PROJETOFINALAPA_NEIGHBOR_STRUCT_H


class NeighborStructure
{
public:

    virtual int localSearch( int *solution, int evaluation, int size ) = 0;

    void swap( int *s, int i, int j);
};


#endif //PROJETOFINALAPA_NEIGHBOR_STRUCT_H
