//
// Created by 杨小川 on 2018/11/26.
//

#ifndef GRAPH_GRAPHM_H
#define GRAPH_GRAPHM_H

#include <iostream>
#include <assert.h>
#include "Graph.h"
#include "AQueue.h"

#define UNVISITED 0
#define VISITED 1
#define INFINITY 999999

using namespace std;


// Implementation for the adjacency matrix representation
class Graphm : public Graph {
private:
    int numVertex, numEdge; // Store number of vertices, edges
    int **matrix;           // Pointer to adjacency matrix
    int *mark;              // Pointer to mark array
public:
    Graphm(int numVert)     // Constructor
    { Init(numVert); }

    ~Graphm() {       // Destructor
        delete [] mark; // Return dynamically allocated memory
        for (int i=0; i<numVertex; i++)
            delete [] matrix[i];
        delete [] matrix;
    }

    void Init(int n) { // Initialize the graph
        int i;
        numVertex = n;
        numEdge = 0;
        mark = new int[n];     // Initialize mark array
        for (i=0; i<numVertex; i++)
            mark[i] = UNVISITED;
        matrix = (int**) new int*[numVertex]; // Make matrix
        for (i=0; i<numVertex; i++)
            matrix[i] = new int[numVertex];
        for (i=0; i< numVertex; i++) // Initialize to 0 weights
            for (int j=0; j<numVertex; j++)
                matrix[i][j] = 0;
    }

    int n() { return numVertex; } // Number of vertices
    int e() { return numEdge; }   // Number of edges

    // Return first neighbor of "v"
    int first(int v) {
        for (int i=0; i<numVertex; i++){
            if (matrix[v][i] != 0) return i;
        }
        return numVertex;           // Return n if none
    }

    // Return v's next neighbor after w
    int next(int v, int w) {
        for(int i=w+1; i<numVertex; i++)
            if (matrix[v][i] != 0)
                return i;
        return numVertex;           // Return n if none
    }

    // Set edge (v1, v2) to "wt"
    void setEdge(int v1, int v2, int wt) {
        //Assert(wt>0, "Illegal weight value");
        if (matrix[v1][v2] == 0) numEdge++;
        matrix[v1][v2] = wt;
        matrix[v2][v1] = wt;
    }

    void delEdge(int v1, int v2) { // Delete edge (v1, v2)
        if (matrix[v1][v2] != 0) numEdge--;
        matrix[v1][v2] = 0;
        matrix[v2][v1] = 0;
    }

    bool isEdge(int i, int j) // Is (i, j) an edge?
    { return matrix[i][j] != 0; }

    int weight(int v1, int v2) { return matrix[v1][v2]; }
    int getMark(int v) { return mark[v]; }
    void setMark(int v, int val) { mark[v] = val; }


    int getdegree(int* p, int len) {
        int degree = 0;
        for (int i = 0; i < len; ++i) {
            if (p[i] != 0) degree++;
        }
        return degree;
    }

    void delvert(int v, int len) {
        int v2 = 0;
        for (int i = 0; i < len; ++i) {
            if (matrix[v][i] != 0) break;
            v2++;
        }
        matrix[v][v2] = 0;
        matrix[v2][v] = 0;
    }

    bool ifCircle() {
        int vertex = n();
        int flag = 1;
        while (flag) {
            flag = 0;
            for (int i = 0; i < vertex; ++i) {
                if (getdegree(matrix[i], vertex) == 1) {
                    delvert(i, vertex);
                    flag = 1;
                }
            }
        }
        for (int j = 0; j < vertex; ++j) {
            if (getdegree(matrix[j], vertex) >= 2)
                return true;
        }
        return false;
    }
};


#endif //GRAPH_GRAPHM_H
