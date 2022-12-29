#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

/* Structures */

typedef struct vertice
{
    long parent;
    long rank;
} Vertice;

typedef struct edge
{
    long vertice1;
    long vertice2;
    long weight;
} Edge;

/* Global vectors */

vector<Vertice> vertices;
vector<Edge> edges;

/* Functions*/

void makeSet(long V)
{
    vertices[V].parent = V;
    vertices[V].rank = 0;
}

long findSet(long V)
{
    if (vertices[V].parent != V)
        vertices[V].parent = findSet(vertices[V].parent);
    return vertices[V].parent;
}

void link(long v1, long v2)
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

void treeUnion(long v1, long v2)
{
    link(findSet(v1), findSet(v2));
}

bool weightComparator(Edge e1, Edge e2)
{
    return e1.weight > e2.weight;
}

// Performs Kruskal's algorithm but from heavist to lightest, and instead of
// adding edges to the MST, it simply adds their weight to "sum"
long adaptedKruskal()
{
    long sum = 0;

    // Sorts all edges from heaviest to lightest
    std::sort(edges.begin(), edges.end(), weightComparator);

    for (Edge e : edges)
        if (findSet(e.vertice1) != findSet(e.vertice2))
        {
            sum += e.weight;
            treeUnion(e.vertice1, e.vertice2);
        }

    return sum;
}

int main()
{
    long numVertices, numEdges, v1, v2, weight;
    if (scanf("%ld %ld", &numVertices, &numEdges) != 2)
    {
        exit(1);
    }

    vertices.resize(numVertices);
    edges.resize(numEdges);

    // Performs "makeSet" on every vertice.
    // The vertice "1" is on vertices[0], "2" is on vertices[1], etc.
    for (long i = 0; i < numVertices; i++)
        makeSet(i);

    for (long i = 0; i < numEdges; i++)
    {
        if (scanf("%ld %ld %ld", &v1, &v2, &weight) != 3)
        {
            exit(1);
        }
        Edge e;
        e.vertice1 = v1;
        e.vertice2 = v2;
        e.weight = weight;
        edges[i] = e;
    }

    printf("%ld\n", adaptedKruskal());

    return 0;
}