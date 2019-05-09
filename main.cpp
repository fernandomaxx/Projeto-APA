#include "main.h"

int evaluation( GraphAdjacencyMatrix *graph_m, const int *solution, int size );

int main()
{
    int size;
    GraphAdjacencyList *graph;
    GraphAdjacencyMatrix *graph_m;
    FileReader fileReader( "tsp1.txt", &size );
    graph = new GraphAdjacencyList( size );
    graph_m = new GraphAdjacencyMatrix( size );
    fileReader.createGraph( graph, graph_m );
    int solution[size];
    Grasp grasp( graph, graph_m, size );
    std:: cout << grasp.procedimento( 1, 0.5, solution ) << std::endl;

    //printf("\n");

//    int size;
//    freopen( "input", "r", stdin );
//    int weight;
//    std::cin >> size;
//    GraphAdjacencyList *graph = new GraphAdjacencyList( size );
//    GraphAdjacencyMatrix *graph_m = new GraphAdjacencyMatrix( size );
//    for ( int i = 0; i < size; ++i )
//    {
//        for ( int j = 0; j < size; ++j )
//        {
//            std::cin >> weight;
//            if ( weight )
//                graph->addEdge( i, j, weight );
//            graph_m->addEdge( i, j, weight );
//        }
//    }

//    int solution[size];
//    BestInsertion best( graph, graph_m, size );
//    best.build( 0, solution);

    //std::cout << evaluation( graph_m, solution, size );

//    for (int j = 0; j < size; ++j)
//        std::cout << solution[j] << " ";

}

int evaluation( GraphAdjacencyMatrix *graph_m, const int *solution, int size )
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