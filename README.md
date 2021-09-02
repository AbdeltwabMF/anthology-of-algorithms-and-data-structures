
# Contents

## 1. [data structures](data_structures)
  _ [union find disjoint sets](data_structures/union_find_disjoint_sets.cpp)
  _ [segment tree](data_structures/segment_tree)
    _ [range minimum query](data_structures/segment_tree/segment_tree_rmq.cpp)
    _ [merge sort tree](data_structures/segment_tree/merge_sort_tree.cpp)
  _ [fenwick tree](data_structures/fenwick_tree)
  _ [sparse table](data_structures/sparse_table)
    _ [range min/max query](data_structures/sparse_table/sparse_table_rmq.cpp)
    _ [range sum query](data_structures/sparse_table/sparse_table_rsq.cpp)
  _ [sorting](data_structures/sorting)
    _ [merge sort](data_structures/sorting/merge_sort.cpp)
    _ [selection sort](data_structures/sorting/selection_sort.cpp)
    _ [bubble sort](data_structures/sorting/bubble_sort.cpp)

___

## 2. [problem solving paradigms](problem_solving_paradigms)

___

## 3. [mathematics](mathematics)
  _ [combinatorics](mathematics/combinatorics)
    _ [fibonacci numbers](mathematics/combinatorics/fibonacci_numbers)
      _ [pisano periodic sequence](mathematics/combinatorics/fibonacci_numbers/pisano_periodic_sequence.cpp)
  _ [number theory](mathematics/number_theory)
    _ [prime generation](mathematics/number_theory/prime_generation)
      _ [simple sieve of eratosthenes](mathematics/number_theory/prime_generation/simple_sieve_eratosthenes.cpp)
      _ [wheel sieve](mathematics/number_theory/prime_generation/wheel_sieve.cpp)
      _ [segmented sieve](mathematics/number_theory/prime_generation/segmented_sieve.cpp)
      _ [linear sieve](mathematics/number_theory/prime_generation/linear_sieve.cpp)
    _ [integer factorization](mathematics/number_theory/integer_factorization)
      _ [extended wheel_factorization](mathematics/number_theory/integer_factorization/extended_wheel_factorization.cpp)
      _ [least prime factorization](mathematics/number_theory/integer_factorization/leastprime_factorization.cpp)
    _ [extended euclid: solving linear diophantine equation](mathematics/number_theory/extended_euclidean_algorithm)
    _ [modified sieve](mathematics/number_theory/modified_sieve)
      _ [euler phi](mathematics/number_theory/modified_sieve/euler_phi_sieve.cpp)
      _ [mobius](mathematics/number_theory/modified_sieve/mobius_sieve.cpp)
    _ [primality tests](mathematics/number_theory/primality_tests)
      _ [miller_rabin test](mathematics/number_theory/primality_tests/miller_rabin_test.cpp)
    _ [functions involving prime factors](mathematics/number_theory/functions_involving_prime_factors)
      _ [euler totient function](mathematics/number_theory/functions_involving_prime_factors/euler_totient_function.cpp)
      _ [mobius function](mathematics/number_theory/functions_involving_prime_factors/mobius_function.cpp)
      _ [phi factorial](mathematics/number_theory/functions_involving_prime_factors/phi_factorial.cpp)
  _ [probability theory](mathematics/probability_theory)
  _ [game theory](mathematics/game_theory)
  _ [cycle finding](mathematics/cycle_finding)
  _ [big integer class](mathematics/biginteger_class)
  _ [ad_hoc mathematics problems](mathematics/ad_hoc_mathematics_problems)
    _ [stable matching](mathematics/ad_hoc_mathematics_problems/stable_matching)
      _ [the stable marriage problem](mathematics/ad_hoc_mathematics_problems/stable_matching/the_stable_marriage_problem.cpp)

___

## 4. [graph theory](graph_theory)
  _ [graph traversal](graph_theory/graph_traversal)
    _ [depth first search](graph_theory/graph_traversal/depth_first_search.cpp)
    _ [breadth first search](graph_theory/graph_traversal/breadth_first_search.cpp)
    _ [finding articulation points and bridges](graph_theory/graph_traversal/finding_articulation_points_and_bridges)
      _ [articulation points and bridges](graph_theory/graph_traversal/finding_articulation_points_and_bridges/articulation_points_and_bridges.cpp)
      _ [bi_connected components](graph_theory/graph_traversal/finding_articulation_points_and_bridges/bi_connected_components.cpp)
    _ [finding strongly connected components](graph_theory/graph_traversal/finding_strongly_connected_components)
      _ [tarjan](graph_theory/graph_traversal/finding_strongly_connected_components/tarjan.cpp)
      _ [directed cyclic graph into dag](graph_theory/graph_traversal/finding_strongly_connected_components/directed_cycle_graph_into_directed_acycle_graph.cpp)
    _ [topological sort](graph_theory/graph_traversal/topological_sort)
      _ [topological sort](graph_theory/graph_traversal/topological_sort/topological_sort[dfs].cpp)
      _ [kahn's algorithm](graph_theory/graph_traversal/topological_sort/topological_sort[kahnsalgorithm].cpp)
    _ [applications](graph_theory/graph_traversal/applications)
      _ [connected components](graph_theory/graph_traversal/applications/connected_components.cpp)
      _ [flood fill](graph_theory/graph_traversal/applications/flood_fill.cpp)
      _ [bi partite graph check](graph_theory/graph_traversal/applications/bi_partite_graph.cpp)
      _ [edge classification](graph_theory/graph_traversal/applications/edge_classification.cpp)
      _ [adjacency list](graph_theory/graph_traversal/applications/adjacency_list.cpp)
      _ [cycle detection directed graph](graph_theory/graph_traversal/applications/cycle_detection[directedg].cpp)
      _ [cycle detection undirected graph](graph_theory/graph_traversal/applications/cycle_detection[undirectedg].cpp)
      _ [minimum vertex cover](graph_theory/graph_traversal/applications/minimum_vertex_cover.cpp)
  _ [minimum spanning tree](graph_theory/minimum_spanning_tree)
    _ [kruskal's algorithm](graph_theory/minimum_spanning_tree/kruskal_algorithm)
      _ [kruskal](graph_theory/minimum_spanning_tree/kruskal_algorithm/kruskal.cpp)
    _ [prim's algorithm](graph_theory/minimum_spanning_tree/prim_algorithm)
  _ [single_source shortest paths](graph_theory/single_source_shortest_paths)
    _ [unweighted graph](graph_theory/single_source_shortest_paths/unweighted_graph)
      _ [single source shortest path](graph_theory/single_source_shortest_paths/unweighted_graph/single_source_shortest_path.cpp)
      _ [single source shortest path on grids](graph_theory/single_source_shortest_paths/unweighted_graph/single_source_shortest_path[grid].cpp)
      _ [shortest cycle](graph_theory/single_source_shortest_paths/unweighted_graph/shortest_cycle.cpp)
      _ [restoring the path](graph_theory/single_source_shortest_paths/unweighted_graph/restoring_the_path.cpp)
    _ [weighted graph](graph_theory/single_source_shortest_paths/weighted_graph)
      _ [dijkstra on sparse graphs](graph_theory/single_source_shortest_paths/weighted_graph/dijkstra[sparsegraph].cpp)
      _ [dijkstra on dense graphs](graph_theory/single_source_shortest_paths/weighted_graph/dijkstra[densegraph].cpp)
      _ [dijkstra on grids](graph_theory/single_source_shortest_paths/weighted_graph/dijkstra[grid].cpp)
      _ [dijkstra on _ve weight edges](graph_theory/single_source_shortest_paths/weighted_graph/dijkstra[negativeweightedges].cpp)
      _ [special case (0_1 bfs)](graph_theory/single_source_shortest_paths/weighted_graph/special_case(0_1_bfs))
        _ [single pair shortest path](graph_theory/single_source_shortest_paths/weighted_graph/special_case(0_1_bfs)/zsingle_pair_shortest_path.cpp)
        _ [single pair shortest path on grids](graph_theory/single_source_shortest_paths/weighted_graph/special_case(0_1_bfs)/zsingle_pair_shortest_path.cpp)
    _ [graph with negative weight cycle](graph_theory/single_source_shortest_paths/graph_with_negativ_weight_cycle)
      _ [bellman_ford's algorithm](graph_theory/single_source_shortest_paths/graph_with_negativ_weight_cycle/bellman_ford.cpp)
      _ [shortest path faster algorithm (spfa)](graph_theory/single_source_shortest_paths/graph_with_negativ_weight_cycle/shortest_path_faster_algorithm.cpp)
  _ [all pairs shortest paths (apsp)](graph_theory/all_pairs_shortest_paths)
    _ [floyd_warshall's algorithm](graph_theory/all_pairs_shortest_paths/floyd_warshall.cpp)
  _ [special graphs](graph_theory/special_graphs)
    _ [directed acyclic graph](graph_theory/special_graphs/directed_acyclic_graph)
    _ [tree](graph_theory/special_graphs/tree)
      _ [tree diameter](graph_theory/special_graphs/tree/tree_diameter.cpp)
      _ [lowest common ancestor](graph_theory/special_graphs/tree/lca)
        _ [lca _ eulerian tour and rmq method](graph_theory/special_graphs/tree/lca/lca[euleriantourandrmq].cpp)
        _ [kth ancestor and lca _ binary lifting](graph_theory/special_graphs/tree/lca/kth_ancestor_and_lca[binarylifting].cpp)
    _ [eulerian graph](graph_theory/special_graphs/eulerian_graph)
      _ [eulerian tour of tree](graph_theory/special_graphs/eulerian_graph/eulerian_tour_tree.cpp)
    _ [bipartite graph](graph_theory/special_graphs/bipartite_graph)
  _ [network flow](graph_theory/network_flow)

___

## 5. [string processing](string_processing)
  _ [trie](string_processing/trie.cpp)
  _ [knuth_morris_pratt algorithm](string_processing/knuth_morris_pratt.cpp)

___

## 6. [geometry](geometry)
  _ [point](geometry/point.cpp)

___

## 7. [more advanced topics](more_advanced_topics)
  _ [advanced search techniques](more_advanced_topics/more_advanced_search_techniques)
    _ [informed search: a* algorithm](more_advanced_topics/more_advanced_search_techniques/a*_algorithm.cpp)
  _ [range queries](more_advanced_topics/range_queries)
    _ [mo's algorithm](more_advanced_topics/range_queries/mo's_algorithm.cpp)
    _ [square root decomposition](more_advanced_topics/range_queries/square_root_decomposition.cpp)

___

## 8. [rare topics](rare_topics)

___

## 9. [miscellaneous](miscellaneous)
  _ [pseudo_random number generator](miscellaneous/pseudo_random_number_generator.cpp)
  _ [code stress test](miscellaneous/stress_test.cpp)
  _ [fast input/output methods for c++](miscellaneous/fast_io.cpp)
  _ [modular calculations](miscellaneous/modular_calculations.cpp)
  _ [double comparison](miscellaneous/double_comparison.cpp)
  _ [overloaded operators << and >> to accept an 128_bit integer](miscellaneous/overloaded_operators_to_accept_128bit_integer.cpp)
  _ [policy based data structures](miscellaneous/policy_based_data_structures.cpp)
  _ [contest template _ c++](miscellaneous/cpp_template.cpp)
  _ [my debugging tools](miscellaneous/my_debugger.cpp)
