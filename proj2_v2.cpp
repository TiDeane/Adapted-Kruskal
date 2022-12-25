#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/* Estruturas */

typedef struct vertice {
    int id;
    int parent;
    int rank;
} Vertice;

typedef struct edge {
    int vertice1;
    int vertice2;
    int weight;
} Edge;

vector<Vertice> vertices;
vector<Edge> edges;

void makeSet(int V) {
    vertices[V].parent = V;
    vertices[V].rank = 0;
}

int findSet(int V) {
    if (vertices[V].parent != V)
        vertices[V].parent = findSet(vertices[V].parent);
    return V;
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

int adaptedKruskal() {
    int sum = 0;

    for (Vertice v : vertices) {
        makeSet(v.id);
    }

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
    cin >> numVertices >> numEdges;

    for (int i = 1; i <= numVertices; i++) {
        Vertice v;
        v.id = i;
        vertices.push_back(v);
    }

    for (int i = 0; i < numEdges; i++) {
        cin >> v1 >> v2 >> weight;
        Edge e;
        e.vertice1 = v1;
        e.vertice2 = v2;
        e.weight = weight;
        edges.push_back(e);
    }

    cout << adaptedKruskal() << endl;

    return 0;
}