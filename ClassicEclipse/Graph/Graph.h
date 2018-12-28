//
// Created by 杨小川 on 2018/11/26.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H


// Graph abstract class. This ADT assumes that the number
// of vertices is fixed when the graph is created.
class Graph {
 private:
  void operator = (const Graph&) {}  // Project assignment
  Graph(const Graph&) {}             // Project copy constructor
 public:
  Graph() {}          // Default constructor
  virtual ~Graph() {} // Based destructor

  // Initialize a graph of n vertices
  virtual void Init(int n) = 0;

  // Return: the number of vertices and edges
  virtual int n() = 0;
  virtual int e() = 0;

  // Return v's first neighbour
  virtual int first(int v) = 0;

  // Return v's next neighbour
  virtual int next(int v, int w) = 0;

  // Set the weight for an edge
  // i, j: The vertices
  // weight: the weight of edge
  virtual void setEdge(int i, int j, int weight) = 0;

  // Delete an edge
  // i, j: The vertices
  virtual void delEdge(int v1, int v2) = 0;

  virtual bool isEdge(int i, int j) = 0;

  virtual int weight(int v1, int v2) = 0;

  virtual int getMark(int v) = 0;
  virtual void setMark(int v, int val) = 0;
};


#endif //GRAPH_GRAPH_H
