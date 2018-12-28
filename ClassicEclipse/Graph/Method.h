//
// Created by 杨小川 on 2018/12/16.
//

#ifndef GRAPH_METHOD_H
#define GRAPH_METHOD_H

#include <iostream>
#include "Graphm.h"

using namespace std;


void PreVisitd(Graph* G, int v) {
    cout << v << " ";
}


void DFS(Graph* G, int v) { // Depth first search
    PreVisitd(G, v);           // Take appropriate action
    G->setMark(v, VISITED);
    for (int w=G->first(v); w<G->n(); w = G->next(v,w))
        if (G->getMark(w) == UNVISITED)
            DFS(G, w);
}

void BFS(Graph *G, int start) {
    int v, w;
    AQueue* Q = new AQueue(G->n());
    Q->enqueue(start);
    G->setMark(start, VISITED);
    while(Q->length() != 0) {
        v = Q->dequeue();
        PreVisitd(G, v);

        for (w = G->first(v); w < G->n(); w = G->next(v, w)) {
            if (G->getMark(w) == UNVISITED) {
                G->setMark(w, VISITED);
                Q->enqueue(w);
            }
        }
    }
}

int minVertex(Graph* G, int* D) { // Find min cost vertex
    int i, v = -1;
    // Initialize v to some unvisited vertex
    for (i=0; i<G->n(); i++)
        if (G->getMark(i) == UNVISITED) { v = i; break; }
    for (i++; i<G->n(); i++)  // Now find smallest D value
        if ((G->getMark(i) == UNVISITED) && (D[i] < D[v]))
            v = i;
    return v;
}

void Dijkstra(Graph* G, int* D, int s) {
    int i, v, w;
    for (int m=0; m<G->n(); m++)
        G->setMark(m, UNVISITED);
    for (i=0; i<G->n(); i++) {      // Process the vertices
        v = minVertex(G, D);
        if (D[v] == INFINITY) return; // Unreachable vertices
        G->setMark(v, VISITED);
        for (w=G->first(v); w<G->n(); w = G->next(v,w)){
            if (D[w] > (D[v] + G->weight(v, w)))
                D[w] = D[v] + G->weight(v, w);
        }
    }
}


#endif //GRAPH_METHOD_H
