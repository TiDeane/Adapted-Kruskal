#include <iostream>
#include <vector>

using namespace std;

/* Estruturas */

typedef struct vertice {
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

/*bool weightComparator(Edge e1, Edge e2) {
    return e1.weight > e2.weight;
}*/

//int adaptedKruskal(Edge graph[], int numVertices, int numEdges) {
//    int sum = 0;
//    /* Performs "makeSet" on every vertice */
//    for (Edge e : graph) {
//        makeSet(e.vertice1);
//        makeSet(e.vertice2);
//    }

//    /*std::sort(graph, graph + numEdges, weightBigger); */
//    for (Edge e : graph)
//        if (findSet(e.vertice1) != findSet(e.vertice2)) {
//            sum += e.weight;
//            treeUnion(e.vertice1, e.vertice2);
//        }

//    return sum;
//}

int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    Edge graph[numEdges];
    for (int i = 0; i < numEdges; i++)
        cin >> graph[i].vertice1 >> graph[i].vertice2 >> graph[i].weight;

    cout << "teste 4 :)" << endl;
    return 0;
}