#include <stdio.h>
#include <algorithm>
#include <vector> 

using namespace std;

/* Structures */

typedef struct vertice {
    int parent;
    int rank;
} Vertice;

typedef struct edge {
    int vertice1;
    int vertice2;
    int weight;
} Edge;

/* Global vectors */

vector<Vertice> vertices;
vector<Edge> edges;

/* Functions*/

void makeSet(int V) {
    vertices[V].parent = V;
    vertices[V].rank = 0;
}

int findSet(int V) {
    if (vertices[V].parent != V)
        vertices[V].parent = findSet(vertices[V].parent);
    return vertices[V].parent;
}

void link(int v1, int v2) {
    if (vertices[v1].rank > vertices[v2].rank)
        vertices[v2].parent = v1;
    else {
        vertices[v1].parent = v2;
        if (vertices[v1].rank == vertices[v2].rank)
            vertices[v2].rank += 1;
    }
}

void treeUnion(int v1, int v2) {
    link(findSet(v1), findSet(v2));
}

bool weightComparator(Edge e1, Edge e2) {
    return e1.weight > e2.weight;
}

// Performs Kruskal's algorithm but from heavist to lightest, and instead of
// adding edges to the MST, it simply adds their weight to "sum"
int adaptedKruskal() {
    int sum = 0;
   
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
    int numVertices, numEdges, v1, v2, weight;
    scanf("%d %d", &numVertices, &numEdges);

    vertices.resize(numVertices);
    edges.resize(numEdges);

    // Performs "makeSet" on every vertice.
    // The vertice "1" is on vertices[0], "2" is on vertices[1], etc.
    for (int i = 0; i < numVertices; i++)
        makeSet(i);

    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &v1, &v2, &weight);
        Edge e;
        e.vertice1 = v1;
        e.vertice2 = v2;
        e.weight = weight;
        edges[i] = e;
    }

    printf("%d\n", adaptedKruskal());

    return 0;
}