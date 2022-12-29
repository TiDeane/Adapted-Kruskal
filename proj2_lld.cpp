#include <stdio.h>
#include <algorithm>
#include <vector> 

/* Structures */

typedef struct vertice {
    long long unsigned parent;
    long long unsigned rank;
} Vertice;

typedef struct edge {
    long long unsigned vertice1;
    long long unsigned vertice2;
    long long unsigned weight;
} Edge;

/* Global vectors */

std::vector<Vertice> vertices;
std::vector<Edge> edges;

/* Functions*/

void makeSet(long long unsigned V) {
    vertices[V].parent = V;
    vertices[V].rank = 0;
}

long long unsigned findSet(long long unsigned V) {
    if (vertices[V].parent != V)
        vertices[V].parent = findSet(vertices[V].parent);
    return vertices[V].parent;
}

void link(long long unsigned v1, long long unsigned v2) {
    if (vertices[v1].rank > vertices[v2].rank)
        vertices[v2].parent = v1;
    else {
        vertices[v1].parent = v2;
        if (vertices[v1].rank == vertices[v2].rank)
            vertices[v2].rank += 1;
    }
}

void treeUnion(long long unsigned v1, long long unsigned v2) {
    link(findSet(v1), findSet(v2));
}

bool weightComparator(Edge e1, Edge e2) {
    return e1.weight > e2.weight;
}

// Performs Kruskal's algorithm but from heavist to lightest, and instead of
// adding edges to the MST, it simply adds their weight to "sum"
long long unsigned adaptedKruskal() {
    long long unsigned sum = 0;
   
    // Sorts all edges from heaviest to lightest
    std::sort(edges.begin(), edges.end(), weightComparator);
    
    for (Edge e : edges)
        if (findSet(e.vertice1) != findSet(e.vertice2)) {
            sum += e.weight;
            treeUnion(e.vertice1, e.vertice2);
        }

    return sum;
}

int main() {
    long long unsigned numVertices, numEdges, v1, v2, weight;
    scanf("%lld %lld", &numVertices, &numEdges);

    vertices.resize(numVertices);
    edges.resize(numEdges);

    // Performs "makeSet" on every vertice.
    // The vertice "1" is on vertices[0], "2" is on vertices[1], etc.
    for (long long unsigned i = 0; i < numVertices; i++)
        makeSet(i);

    for (long long unsigned i = 0; i < numEdges; i++) {
        scanf("%lld %lld %lld", &v1, &v2, &weight);
        Edge e;
        e.vertice1 = v1;
        e.vertice2 = v2;
        e.weight = weight;
        edges[i] = e;
    }

    printf("%lld\n", adaptedKruskal());

    return 0;
}