#include "Graphm.h"
#include "Method.h"

#define UNVISITED 0
#define VISITED 1
#define INFINITY 999999

using namespace std;


bool judgeall(Graph *G);
void init(Graph* G);

int main() {
    int vertex, edge;
    cin >> vertex >> edge;
    Graphm* G = new Graphm(vertex);
    int v1, v2, wt;
    for (int i = 0; i < edge; ++i) {
        cin >> v1 >> v2 >> wt;
        G->setEdge(v1, v2, wt);
    }
    int v = 0;
    do{
        v = 0;
        for (int i = 0; i < G->n(); ++i) {
            if (G->getMark(i) == VISITED)
                v++;
            else
                break;
        }
        BFS(G, v);
    }while (!judgeall(G));

    init(G);
    cout << endl;

    do{
        v = 0;
        for (int i = 0; i < G->n(); ++i) {
            if (G->getMark(i) == VISITED)
                v++;
            else
                break;
        }
        DFS(G, v);
    }while (!judgeall(G));

    init(G);
    cout << endl;

    int *D = new int[vertex];
    for (int i=0; i<G->n(); i++)
        D[i] = INFINITY;
    D[0] = 0;
    Dijkstra(G, D, 0);
    for (int j = 1; j < vertex; ++j) {
        if(D[j] == INFINITY) D[j] = 0;
        cout << "0 " << j << " " << D[j] << endl;
    }

    init(G);

    if (G->ifCircle())
        cout << "YES";
    else
        cout << "NO";

    return 0;
}

bool judgeall(Graph *G) {
    for (int i = 0; i < G->n(); ++i) {
        if (G->getMark(i) == UNVISITED)
            return false;
    }
    return true;
}

void init(Graph* G) {
    for (int i = 0; i < G->n(); ++i) {
        G->setMark(i, UNVISITED);
    }
}