#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include "node.h"
#include "edge.h"

template <class T> class Graph {
public:
	void addNode(const T& value);
	void addNode(const T&& value);
	void addNode(Node<T>* node);
	void removeNode(Node<T>* node);
	void addEdge(Node<T>* src, Node<T>* dst);
	void removeEdge(Edge<T>* edge);
private:
	std::vector<Node<T>*> _nodes;
	std::vector<Edge<T>*> _edges;
};

template<class T> inline void Graph<T>::addNode(const T& value){
	Node<T>* node = new Node<T>{value};
	_nodes.push_back(node);
}

template<class T> inline void Graph<T>::addNode(const T&& value){
	Node<T>* node = new Node<T>{std::move(value)};
	_nodes.push_back(node);
}

template<class T> inline void Graph<T>::addNode(Node<T>* node){
	_nodes.push_back(node);
}

template<class T> inline void Graph<T>::removeNode(Node<T>* node){
	auto pos = std::find(_nodes.begin(), _nodes.end(), node);
	if(pos == _nodes.end)
		return;
	_nodes.erase(pos);
}

template<class T> inline void Graph<T>::addEdge(Node<T>* src, Node<T>* dst){
    Edge<T>* edge = new Edge<T>{src, dst};
	_edges.push_back(edge);
}

template<class T> inline void Graph<T>::removeEdge(Edge<T>* edge){
	auto pos = std::find(_edges.begin(), _edges.end(), edge);
	if(pos == _edges.end)
		return;
	_edges.erase(pos);
}

#endif /* GRAPH_H */
