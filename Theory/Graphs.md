# Types of graphs - https://www.youtube.com/watch?v=eQA-m22wjTQ

## Undirected
- graph in which edges have no orientation. Edge (u, v) == (v, u)
- problem example: cities and bidirectional roads

## Directed
- "digraph" - edges are directed (u, v) != (v, u), you can only go u -> v
- problem example: people who bought each other gifts

## Weighted
- can be both digraphs and undirected graphs.
- edges have values (u, v, w)

## Special graphs
### Trees
- undirected graph with no cycles
- has N nodes and N-1 edges

### Rooted trees
- has a designated ROOT node
- ROOT - every edge either points away (arborescence/out-tree) or to (anti-arboresence/in-tree) the ROOT node

### Directed Acyclic Graphs (DAGs)
- digraphs wo/ cycles
- represent structures w/ dependencies
- all out-trees are DAGs

### Bipartite Graphs
- vertices can be spilt into U and V, so that every edge ONLY connects between U and V
- example problem: how many machings can we create on a graph

### Complete Graphs
- there is a unique edge between every pair of nodes
- such a complete graphs is denoted as graph Kn (n -number of vertices)
- often known as a worst case graphs

# Representing graphs
## Adjecency matrix

        A B C D
    A [[0 4 1 9]
    B  [3 0 6 8]
    C  [4 1 0 2]
    D  [6 5 2 0]]

- m[i][j] represents the edge weight of going from node i to node j
- it's assumed that the weight of going from a node to itself is 0
- PROS:
    - space efficient for representing dense (a lot of edges) graphs
    - edge weight lookup is O(1) time
    - simplest graph representation
- CONS:
    - requires O(V**2) space
    - iterating over all edges takes O(V**2) time
    - this is fine for dense but not for sparse (a lot of empty places) graphs

## Adjecency list

    A -> [(B,4), (C,1)]
    B -> [(C,6)]
    C -> [(A,4), (B,1), (D,2)]
    D -> []

- a map from nodes to list of edges
- PROS:
    - space efficient for representing sparse graphs
    - iterating over all edges is eff.
- CONS:
    - less space eff. for denser graphs
    - edge weight lookup is O(E)
    - slightly more complex graph representation

## Edge list

    [(C,A,4), (A,C,1),
     (B,C,6), (A,B,4),
     (C,B,1), (C,D,2)]

- unordered list of edges
- notation of a triplet (u,v,w) means "the cost from node u to node v is w"
- seldomly used because of lack of structure, but simple ande practical is some algos
- PROS:
    - space eff. for sparse graphs
    - iterating over all edges is eff.
    - very simple structure
- CONS:
    - less space eff. for dense graphs
    - edge weight lookup is O(E)