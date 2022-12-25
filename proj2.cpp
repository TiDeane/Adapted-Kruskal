#include <iostream>

using namespace std;

/* Estruturas */

typedef struct vertice {
    int id;
    struct vertice *parent;
    int rank;
} Vertice;

typedef struct edge {
    Vertice vertice1;
    Vertice vertice2;
    int weight;
} Edge;

/*
typedef struct graph {
    vector<Vertice> vertices;
    vector<Edge> edges;
    int rank;
} Graph;
*/

void initializeGraph(int numEdges, Edge graph[]) {
    for (int i = 0; i < numEdges; i++)
        cin >> graph[i].vertice1 >> graph[i].vertice2 >> graph[i].weight;
}

void makeSet(Vertice *V) {
    V->parent = V;
    V->rank = 0;
}

Vertice* findSet(Vertice *V) {
    if (V->parent != V)
        V->parent = findSet(V->parent);
    return V;
}

void link(Vertice *v1, Vertice *v2) {
    if (v1->rank > v2->rank)
        v2->parent = v1;
    else {
        v1->parent = v2;
        if (v1->rank == v2->rank)
            v2->rank += 1;
    }
}

void treeUnion(Vertice *v1, Vertice *v2) {
    link(findSet(v1), findSet(v2));
}

bool weightBigger(Edge e1, Edge e2) {
    return e1.weight > e2.weight;
}

int adaptedKruskal(Edge graph[], int numVertices, int numEdges) {
    int sum = 0;
    /* Performs "makeSet" on every vertice */
    for (Edge e : graph) {
        makeSet(e.vertice1);
        makeSet(e.vertice2);
    }

    std::sort(graph, graph + numEdges, weightBigger);
    for (Edge e : graph)
        if (findSet(e.vertice1) != findSet(e.vertice2)) {
            sum += e.weight;
            treeUnion(e.vertice1, e.vertice2);
        }
        
    return sum;
}

int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    Edge graph[numEdges];
    initializeGraph(numEdges, graph);

    cout << "teste 4 :)" << endl;
    return 0;
}