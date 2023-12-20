IST Analysis and Synthesis of Algorithms second course project, 2022/2023. In this project, each vertice in a graph represents a region and each weight represents the value of the commercial exchanges between the 2 regions. The code uses an adapted version of Kruskal's algorithm to find the maximum value of commercial exchanges while minimizing the infrastructure costs (i.e. number of edges).

##  Input

The input file contains information relating to an undirected graph G = (V,E), defined this way:
- a line containing the number of vertices |V| (with |V| ≥ 1);
- a line containing the number of arcs |E| (with |E| ≥ 0);
- a sequence of |E| lines, where each line represents an arc (u,v) and contains 3 integers: two integers that designate the vertices u and v and an integer that represents the value w(u,v).

Vertex identifiers are integers between 1 and |V|.

## Output

The program prints out the maximum value of commercial exchanges in the output, minimizing infrastructure costs (i.e. number of edges).

### Example:

**Input 1**  \
8  \
11  \
1 2 2  \
1 5 4  \
1 8 3  \
2 6 8  \
2 5 4  \
2 8 9  \
4 3 1  \
3 7 3  \
4 7 4  \
5 6 8  \
6 8 5

**Output 1** \
36

## Testing

Two programs were provided to generate inputs:

**Dense Graph Generator: `dgg.c`** - Generates a fully connected graph, in which vertex _i_ connects to all vertices with indices greater than _i_. The correct result for any dense graph should be equal to the number of arcs (second line of the file). Arguments for execution:
- ``./dgg`` **\<number of vertices\>** > **\<test file name\>**
- `<number of vertices>`: replace with the number of vertices in the graph
- **Example:** ./dgg 10 > d10.txt

**Realistic Graph Generator: `delaunator.hpp` and `delaunay2graph.cpp`** - Generates a graph from Delaunay triangulation, with some random parameters. Arguments for execution:
- `./d2g` **\<number of vertices\> \<maximum coordinates\> \<probability\> \<seed\>** > **\<test file name\>**
- `<number of vertices>`: replace with the number of vertices of the graph |V|
- `<maximum coordinate>`: replace with M, maximum coordinate (M,M), where M >= |V|
- `<probability>`: replace with probability to create the new graph
- `<seed>`: replace with random seed (optional)
- **Example:** ./d2g 10 100 0.8 15 > v10.txt