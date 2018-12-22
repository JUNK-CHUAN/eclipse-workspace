/*
 * Graphl.h
 *
 *  Created on: Dec 22, 2018
 *      Author: junk_chuan
 */

#ifndef GRAPHL_H_
#define GRAPHL_H_

#include <Graph.h>
#include <List>

class Edge {
	int vert, wt;
public:
	Edge() { vert = -1; wt = -1; }
	Edge(int v, int w) { vert = v; wt = w; }
	int vertex() { return vert; }
	int weight() { return wt; }
};


class Graphl : public Graph {
private:
	List<Edge>** vertex;
};


#endif /* GRAPHL_H_ */
