# Contents

## 1. [data structures](data_structures)

- [union find disjoint sets](data_structures/union_find_disjoint_sets.cpp)
- [segment tree](data_structures/segment_tree)
  - [range minimum query](data_structures/segment_tree/segment_tree_rmq.cpp)
  - [merge sort tree](data_structures/segment_tree/merge_sort_tree.cpp)
- [fenwick tree](data_structures/fenwick_tree)
- [sparse table](data_structures/sparse_table)
  - [range min/max query](data_structures/sparse_table/sparse_table_rmq.cpp)
  - [range sum query](data_structures/sparse_table/sparse_table_rsq.cpp)
- [sorting](data_structures/sorting)
  - [merge sort](data_structures/sorting/merge_sort.cpp)
  - [selection sort](data_structures/sorting/selection_sort.cpp)
  - [bubble sort](data_structures/sorting/bubble_sort.cpp)

---

## 2. [problem solving paradigms](problem_solving_paradigms)

---

## 3. [mathematics](mathematics)

- [combinatorics](mathematics/combinatorics)
  - [fibonacci numbers](mathematics/combinatorics/fibonacci_numbers)
    - [pisano periodic sequence](mathematics/combinatorics/fibonacci_numbers/pisano_periodic_sequence.cpp)
- [number theory](mathematics/number_theory)
  - [prime generation](mathematics/number_theory/prime_generation)
    - [simple sieve of eratosthenes](mathematics/number_theory/prime_generation/simple_sieve_eratosthenes.cpp)
    - [wheel sieve](mathematics/number_theory/prime_generation/wheel_sieve.cpp)
    - [segmented sieve](mathematics/number_theory/prime_generation/segmented_sieve.cpp)
    - [linear sieve](mathematics/number_theory/prime_generation/linear_sieve.cpp)
  - [integer factorization](mathematics/number_theory/integer_factorization)
    - [extended wheel factorization](mathematics/number_theory/integer_factorization/extended_wheel_factorization.cpp)
    - [least prime factorization](mathematics/number_theory/integer_factorization/leastprime_factorization.cpp)
  - [extended euclid: solving linear diophantine equation](mathematics/number_theory/extended_euclidean_algorithm)
  - [modified sieve](mathematics/number_theory/modified_sieve)
    - [euler phi](mathematics/number_theory/modified_sieve/euler_phi_sieve.cpp)
    - [mobius](mathematics/number_theory/modified_sieve/mobius_sieve.cpp)
  - [primality tests](mathematics/number_theory/primality_tests)
    - [miller-rabin test](mathematics/number_theory/primality_tests/miller_rabin_test.cpp)
  - [functions involving prime factors](mathematics/number_theory/functions_involving_prime_factors)
    - [euler totient function](mathematics/number_theory/functions_involving_prime_factors/euler_totient_function.cpp)
    - [mobius function](mathematics/number_theory/functions_involving_prime_factors/mobius_function.cpp)
    - [phi factorial](mathematics/number_theory/functions_involving_prime_factors/phi_factorial.cpp)
- [probability theory](mathematics/probability_theory)
- [game theory](mathematics/game_theory)
- [cycle finding](mathematics/cycle_finding)
- [big integer class](mathematics/biginteger_class)
- [ad-hoc mathematics problems](mathematics/ad_hoc_mathematics_problems)
  - [stable matching](mathematics/ad_hoc_mathematics_problems/stable_matching)
    - [the stable marriage problem](mathematics/ad_hoc_mathematics_problems/stable_matching/the_stable_marriage_problem.cpp)

---

## 4. [graph theory](graph_theory)

- [graph traversal](graph_theory/graph_traversal)
  - [depth first search](graph_theory/graph_traversal/depth_first_search.cpp)
  - [breadth first search](graph_theory/graph_traversal/breadth_first_search.cpp)
  - [finding articulation points and bridges](graph_theory/graph_traversal/finding_articulation_points_and_bridges)
    - [articulation points and bridges](graph_theory/graph_traversal/finding_articulation_points_and_bridges/articulation_points_and_bridges.cpp)
    - [bi-connected components](graph_theory/graph_traversal/finding_articulation_points_and_bridges/bi_connected_components.cpp)
  - [finding strongly connected components](graph_theory/graph_traversal/finding_strongly_connected_components)
    - [tarjan](graph_theory/graph_traversal/finding_strongly_connected_components/tarjan.cpp)
    - [directed cyclic graph into dag](graph_theory/graph_traversal/finding_strongly_connected_components/directed_cycle_graph_into_directed_acycle_graph.cpp)
  - [topological sort](graph_theory/graph_traversal/topological_sort)
    - [topological sort](graph_theory/graph_traversal/topological_sort/topological_sort[dfs].cpp)
    - [kahn's algorithm](graph_theory/graph_traversal/topological_sort/topological_sort[kahnsalgorithm].cpp)
  - [applications](graph_theory/graph_traversal/applications)
    - [connected components](graph_theory/graph_traversal/applications/connected_components.cpp)
    - [flood fill](graph_theory/graph_traversal/applications/flood_fill.cpp)
    - [bi-partite graph check](graph_theory/graph_traversal/applications/bi_partite_graph.cpp)
    - [edge classification](graph_theory/graph_traversal/applications/edge_classification.cpp)
    - [adjacency list](graph_theory/graph_traversal/applications/adjacency_list.cpp)
    - [cycle detection (directed graph)](graph_theory/graph_traversal/applications/cycle_detection[directedg].cpp)
    - [cycle detection (undirected graph)](graph_theory/graph_traversal/applications/cycle_detection[undirectedg].cpp)
    - [minimum vertex cover](graph_theory/graph_traversal/applications/minimum_vertex_cover.cpp)
- [minimum spanning tree (mst)](graph_theory/minimum_spanning_tree)
  - [kruskal's algorithm](graph_theory/minimum_spanning_tree/kruskal_algorithm)
    - [kruskal](graph_theory/minimum_spanning_tree/kruskal_algorithm/kruskal.cpp)
  - [prim's algorithm](graph_theory/minimum_spanning_tree/prim_algorithm)
- [single_source shortest paths (sssp)](graph_theory/single_source_shortest_paths)
  - [unweighted graph](graph_theory/single_source_shortest_paths/unweighted_graph)
    - [single source shortest path](graph_theory/single_source_shortest_paths/unweighted_graph/single_source_shortest_path.cpp)
    - [single source shortest path on grids](graph_theory/single_source_shortest_paths/unweighted_graph/single_source_shortest_path[grid].cpp)
    - [shortest cycle](graph_theory/single_source_shortest_paths/unweighted_graph/shortest_cycle.cpp)
    - [restoring the path](graph_theory/single_source_shortest_paths/unweighted_graph/restoring_the_path.cpp)
  - [weighted graph](graph_theory/single_source_shortest_paths/weighted_graph)
    - [dijkstra on sparse graphs](graph_theory/single_source_shortest_paths/weighted_graph/dijkstra[sparsegraph].cpp)
    - [dijkstra on dense graphs](graph_theory/single_source_shortest_paths/weighted_graph/dijkstra[densegraph].cpp)
    - [dijkstra on grids](graph_theory/single_source_shortest_paths/weighted_graph/dijkstra[grid].cpp)
    - [dijkstra on -ve weight edges](graph_theory/single_source_shortest_paths/weighted_graph/dijkstra[negativeweightedges].cpp)
    - [special case (0-1 bfs)](graph_theory/single_source_shortest_paths/weighted_graph/special_case(0_1_bfs))
      - [single pair shortest path](graph_theory/single_source_shortest_paths/weighted_graph/special_case/zsingle_pair_shortest_path.cpp)
      - [single pair shortest path on grids](graph_theory/single_source_shortest_paths/weighted_graph/special_case/zsingle_pair_shortest_path.cpp)
  - [graph with negative weight cycle](graph_theory/single_source_shortest_paths/graph_with_negativ_weight_cycle)
    - [bellman_ford's algorithm](graph_theory/single_source_shortest_paths/graph_with_negativ_weight_cycle/bellman_ford.cpp)
    - [shortest path faster algorithm (spfa)](graph_theory/single_source_shortest_paths/graph_with_negativ_weight_cycle/shortest_path_faster_algorithm.cpp)
- [all pairs shortest paths (apsp)](graph_theory/all_pairs_shortest_paths)
  - [floyd_warshall's algorithm](graph_theory/all_pairs_shortest_paths/floyd_warshall.cpp)
- [special graphs](graph_theory/special_graphs)
  - [directed acyclic graph (dag)](graph_theory/special_graphs/directed_acyclic_graph)
  - [tree](graph_theory/special_graphs/tree)
    - [tree diameter](graph_theory/special_graphs/tree/tree_diameter.cpp)
    - [lowest common ancestor (lca)](graph_theory/special_graphs/tree/lca)
      - [lca (eulerian tour and rmq)](graph_theory/special_graphs/tree/lca/lca[euleriantourandrmq].cpp)
      - [kth ancestor and lca (binary lifting)](graph_theory/special_graphs/tree/lca/kth_ancestor_and_lca[binarylifting].cpp)
  - [eulerian graph](graph_theory/special_graphs/eulerian_graph)
    - [eulerian tour of tree](graph_theory/special_graphs/eulerian_graph/eulerian_tour_tree.cpp)
  - [bipartite graph](graph_theory/special_graphs/bipartite_graph)
- [network flow](graph_theory/network_flow)

---

## 5. [string processing](string_processing)

- [trie](string_processing/trie.cpp)
- [knuth morris pratt algorithm (kmp)](string_processing/knuth_morris_pratt.cpp)
- [rabin karp](string_processing/rabin_karp.cpp)
- [manacher](string_processing/manacher.cpp)

---

## 6. [geometry](geometry)

- [types](geometry/types.h)
- [convex hull](geometry/convex_hull.h)

---

## 7. [more advanced topics](more_advanced_topics)

- [advanced search techniques](more_advanced_topics/more_advanced_search_techniques)
  - [informed search: a star algorithm](more_advanced_topics/more_advanced_search_techniques/astar_algorithm.cpp)
- [range queries](more_advanced_topics/range_queries)
  - [mo's algorithm](more_advanced_topics/range_queries/mo's_algorithm.cpp)
  - [square root decomposition](more_advanced_topics/range_queries/square_root_decomposition.cpp)

---

## 8. [rare topics](rare_topics)

---

## 9. [miscellaneous](miscellaneous)

- [pseudo random number generator](miscellaneous/pseudo_random_number_generator.cpp)
- [stress test](miscellaneous/stress_test.cpp)
- [fast input/output](miscellaneous/fast_io.cpp)
- [modular calculations](miscellaneous/modular_calculations.cpp)
- [double comparison](miscellaneous/double_comparison.cpp)
- [overloaded operators << and >> to accept an 128bit integer (i/o)](miscellaneous/overloaded_operators_to_accept_128bit_integer.cpp)
- [policy based data structures](miscellaneous/policy_based_data_structures.cpp)
- [contest template - c++](miscellaneous/cpp_template.cpp)
- [my debugging tools](miscellaneous/my_debugger.cpp)
- [binary gcd & lcm](miscellaneous/binary_gcd.cpp)
