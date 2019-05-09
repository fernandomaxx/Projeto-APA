cmake_minimum_required(VERSION 3.14)
project(projetofinalapa)

set(CMAKE_CXX_STANDARD 14)

add_executable( projetofinalapa
                main.cpp
        Graph/graph_adjacency_list.cpp
        Graph/graph_adjacency_list.h
        Graph/graph_adjacency_matrix.cpp
        Graph/graph_adjacency_matrix.h "ConstructionHeuristic/greedy_construction.cpp" "ConstructionHeuristic/greedy_construction.h" "ConstructionHeuristic/best_insertion.cpp" "ConstructionHeuristic/best_insertion.h" "PermutationHeuristic/two_opt.cpp" "PermutationHeuristic/two_opt.h" "PermutationHeuristic/swap.cpp" "PermutationHeuristic/swap.h" "PermutationHeuristic/neighbor_struct.cpp" "PermutationHeuristic/neighbor_struct.h" main.h "PermutationHeuristic/vnd.cpp" "PermutationHeuristic/vnd.h" FileReader/file_reader.cpp FileReader/file_reader.h grasp.cpp grasp.h)