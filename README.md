# Anthology of Algorithms and Data structures
 Common Code for Competitive Programming in C++
 
## Contents
 1. [Data Structures](Data-Structures)
   - [Union Find Disjoint Sets](Data-Structures/UnionFindDisjointSets.cpp)
   - [Segment Tree](Data-Structures/Segment-Tree)
     - [Range Minimum Query](Data-Structures/Segment-Tree/RMQ[Lazy-Propagation].cpp)
     - [Range Sum Query](Data-Structures/Segment-Tree/RSQ[Lazy-Propagation].cpp)
   - [Sparse Table](Data-Structures/Sparse-Table)
     - [Range Maximum Query on Static Array](Data-Structures/Sparse-Table/RMAXQ[static-array].cpp)
     - [Range Minimum Query on Static Array](Data-Structures/Sparse-Table/RMINQ[static-array].cpp)

---

 2. [Graph Theory](Graph-Theory)
   - [Graph Traversal](Graph-Theory/Graph-Traversal)
     - [AdjacencyList using linked list implementation](Graph-Theory/Graph-Traversal/AdjacencyList[LinkedLlist].cpp)
     - [Graph Traversal using bfs](Graph-Theory/Graph-Traversal/GraphTraversal[BFS].cpp)
     - [Graph Traversal using dfs](Graph-Theory/Graph-Traversal/GraphTraversal[DFS].cpp)
     - [Bipartite Graph Check](Graph-Theory/Graph-Traversal/BipartiteGraph.cpp)
     - [Cycle Detection in Directed Graph using dfs](Graph-Theory/Graph-Traversal/CycleDetection[DirectedGraph_dfs].cpp)
     - [Cycle Detection in Undirected Graph using dfs](Graph-Theory/Graph-Traversal/CycleDetection[UndirectedGraph_dfs].cpp)
     - [Edge Classification](Graph-Theory/Graph-Traversal/EdgeClassification.cpp)
     - [Flood Fill](Graph-Theory/Graph-Traversal/FloodFill.cpp)
     - [Minimum Vertex Cover](Graph-Theory/Graph-Traversal/MinimumVertexCover[Tree].cpp)
     - [Number Of CCs in Forest Tree](Graph-Theory/Graph-Traversal/NumberOfCCs[ForestTree].cpp)
     - [Number Of CCs in Undirected Graph](Graph-Theory/Graph-Traversal/NumberOfCCs[UndirectedGraph].cpp)
     - [Topological Sort using dfs](Graph-Theory/Graph-Traversal/TopologicalSort[DFS].cpp)
     - [Topological Sort using Kahn's Algorithm](Graph-Theory/Graph-Traversal/TopologicalSort[KahnsAlgorithm].cpp)
     - [Tree Diameter](Graph-Theory/Graph-Traversal/TreeDiameter.cpp)
     - [Tree Diameter in Weighted Tree [BFS]](Graph-Theory/Graph-Traversal/TreeDiameter[Weighted-BFS].cpp)
     - [Tree Diameter in Weighted Tree [DFS]](Graph-Theory/Graph-Traversal/TreeDiameter[Weighted-DFS].cpp)
   - [Single-Source Shortest Paths (SSSP)](Graph-Theory/Single-Source-Shortest-Paths-(SSSP))
     - [BFS](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/BFS)
       - [Single Source Shortest Path](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/BFS/SSSP.cpp)
       - [Single Destination Shortest Path](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/BFS/SDSP[DirectedGraph].cpp)
       - [Single Pair Shortest Path Finding and Printing](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/BFS/SPSP-FindingAndPrinting.cpp)
       - [Multi Source Shortest Path](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/BFS/MSSP.cpp)
       - [Multi Source Shortest Path on Grids](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/BFS/MSSP[Grid].cpp)
       - [Single Source Shortest Even path](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/BFS/Shortest-Even-path.cpp)
       - [Shortest Cycle](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/BFS/Shortest-Cycle.cpp)
       - [Practice Problem [Almost-SP]](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/BFS/Practice-Problem[Almost-SP].cpp)
     - [Dijkstra](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/Dijkstra)
       - [Dijkstra on dense graphs](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/Dijkstra/Dijkstra[dense-graphs].cpp)
       - [Dijkstra on sparse graphs](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/Dijkstra/Dijkstra[sparse-graphs].cpp)
       - [Dijkstra on Grids](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/Dijkstra/Dijkstra[Grid].cpp)
       - [Modified Dijkstra on -ve weight edges](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/Dijkstra/Dijkstra[Negative-Weight-Edges].cpp)
       - [Special Case (0-1 BFS)](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/Dijkstra/Special-Case(0-1-BFS))
         - [Single Pair Shortest Path](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/Dijkstra/Special-Case(0-1-BFS)/SPSP[0-1-BFS].cpp)
         - [Single Pair Shortest Path via Edge Splitting](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/Dijkstra/Special-Case(0-1-BFS)/SPSP[0-1-BFS-via-EdgeSplitting].cpp)
     - [Bellman-Ford](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/Bellman-Ford)
       - [Bellman-Ford's Algorithm](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/Bellman-Ford/Bellman-Ford[Negative-Cycle-Detection].cpp)
       - [Shortest Path Faster Algorithm (SPFA)](Graph-Theory/Single-Source-Shortest-Paths-(SSSP)/Bellman-Ford/SPFA[Modified-Bellman].cpp)
   - [All Pairs Shortest Paths (APSP)](Graph-Theory/All-Pairs-Shortest-Paths(APSP))
     - [Floyd-Warshall's Algorithm](Graph-Theory/All-Pairs-Shortest-Paths(APSP)/Floyd-Warshall[dp-APSP].cpp)

---

 3. [Mathematics](Mathematics)
   - [Number Theory](Mathematics/Number-Theory)
     - [Prime Generation](Mathematics/Number-Theory/Prime-Generation)
       - [Simple Sieve of Eratosthenes](Mathematics/Number-Theory/Prime-Generation/Simple-Sieve-Eratosthenes.cpp)
       - [Segmented Sieve](Mathematics/Number-Theory/Prime-Generation/Segmented-Sieve.cpp)
       - [Enhancement Segmented Sieve](Mathematics/Number-Theory/Prime-Generation/Enhancement_Segmented_sieve.cpp)
       - [Wheel Sieve](Mathematics/Number-Theory/Prime-Generation/Wheel-Sieve.cpp)
     - [Integer Factorization](Mathematics/Number-Theory/Integer-Factorization)
       - [Extended Wheel-Factorization](Mathematics/Number-Theory/Integer-Factorization/Extended-Wheel-Factorization.cpp)
     - [Primality Tests](Mathematics/Number-Theory/Primality-Tests)
       - [Miller-Rabin Test](Mathematics/Number-Theory/Primality-Tests/Miller-Rabin-Test.cpp)
       - [Practice Problem](Mathematics/Number-Theory/Primality-Tests/GCPC'15[Divisions-F].cpp)
     - [Fibonacci Numbers](Mathematics/Number-Theory/Fibonacci-Numbers)
       - [Pisano Periodic Sequence](Mathematics/Number-Theory/Fibonacci-Numbers/pisano-periodic-sequence.cpp)
       - [Pisano Periodic Sequence using Factorization](Mathematics/Number-Theory/Fibonacci-Numbers/pisano-periodic-sequence[Factorization].cpp)
       
   - [Stable Matching](Mathematics/Stable-Matching)
     - [The Stable Marriage Problem](Mathematics/Stable-Matching/ICPC-Live-Archive-3837-The-Stable-Marriage-Problem.cpp)
     - [CodeChef problem STABLEMP](Mathematics/Stable-Matching/CodeChef[STABLEMP].cpp)
     - [Ladies' Optimal Matching](Mathematics/Stable-Matching/UVa-1175-Ladies'-Choice.cpp)

---

 4. [String Processing](String-Processing)
   - [Trie](String-Processing/Trie.cpp)

---

 5. [Miscellaneous](Miscellaneous)
   - [Next/Prev Greater/Smaller Element](Miscellaneous/Next-Prev-Greater-Smaller-Element[using_stack].cpp)
   - [Modular Calculations](Miscellaneous/Modular-Calculations.cpp)
   - [The Minimal Excluded element of subarray of Permutation](Miscellaneous/The-MEX-of-subarray-of-Permutation.cpp)
   - [Double Comparison](Miscellaneous/Double-Comparison.cpp)
   
   
