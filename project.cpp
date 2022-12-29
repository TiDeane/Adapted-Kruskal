#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

/* Structures */

typedef struct vertice
{
    int parent;
    int rank;
} Vertice;

typedef struct edge
{
    int vertice1;
    int vertice2;
    int weight;
} Edge;

/* Functions*/

void makeSet(int V, Vertice vertices[])
{
    vertices[V].parent = V;
    vertices[V].rank = 0;
}

int findSet(int V, Vertice vertices[])
{
    if (vertices[V].parent != V)
        vertices[V]
            .parent = findSet(vertices[V].parent, vertices);
    return vertices[V].parent;
}

void link(int v1, int v2, Vertice vertices[])
{
    if (vertices[v1].rank > vertices[v2].rank)
        vertices[v2].parent = v1;
    else
    {
        vertices[v1].parent = v2;
        if (vertices[v1].rank == vertices[v2].rank)
            vertices[v2].rank += 1;
    }
}

void treeUnion(int v1, int v2, Vertice vertices[])
{
    link(findSet(v1, vertices), findSet(v2, vertices), vertices);
}

bool weightComparator(Edge e1, Edge e2)
{
    return e1.weight > e2.weight;
}

// Performs Kruskal's algorithm but from heavist to lightest, and instead of
// adding edges to the MST, it simply adds their weight to "sum"
int adaptedKruskal(Edge edges[], Vertice vertices[], int numEdges)
{
    int sum = 0;

    // Sorts all edges from heaviest to lightest
    std::sort(edges, edges + numEdges, weightComparator);

    for (int i = 0; i < numEdges; i++)
    {
        Edge edge = edges[i];
        if (findSet(edge.vertice1, vertices) != findSet(edge.vertice2, vertices))
        {
            sum += edge.weight;
            treeUnion(edge.vertice1, edge.vertice2, vertices);
        }
    }
    return sum;
}

int main()
{
    int numVertices, numEdges, v1, v2, weight;
    if (scanf("%d %d", &numVertices, &numEdges) != 2)
    {
        exit(1);
    }
    Vertice vertices[numVertices];
    Edge edges[numEdges];

    // Performs "makeSet" on every vertice.
    // The vertice "1" is on vertices[0], "2" is on vertices[1], etc.
    for (int i = 0; i <= numVertices; i++)
        makeSet(i, vertices);

    for (int i = 0; i < numEdges; i++)
    {
        if (scanf("%d %d %d", &v1, &v2, &weight) != 3)
        {
            exit(1);
        }
        Edge e;
        e.vertice1 = v1;
        e.vertice2 = v2;
        e.weight = weight;
        edges[i] = e;
    }

    printf("%d\n", adaptedKruskal(edges, vertices, numEdges));

    return 0;
}