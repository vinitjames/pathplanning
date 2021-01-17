#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#include "edge.h"
template <class T> class Graph {
public:
	void addNode(const T& value);
	void addNode(const T&& value);
	void addNode(Node<T>* node);
	void removeNode(Node<T>* node);
	void addEdge(Node<T>* src, Node<T>* dst);
	void removeNode(Edge<T>* edge);
private:
	std::vector<Node<T>*> _nodes;
	std::vector<Edge<T>*> _edges;
		
};

#endif /* GRAPH_H */
