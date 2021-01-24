#ifndef NODE_H
#define NODE_H

#include <utility>
#include <vector>
#include <memory>
#include "edge.h"

template <class T> class  Node {

public:
	Node() = default;
  Node(const T& value);
  Node(const T&& value);
  void value(const T &value);
  void value(const T &&value);
  T &value();
  const T &value() const;
  Node *predecessor();
  void predecessor(Node* pred);
	std::vector<std::shared_ptr<Edge<T>>>& edgesIn();
	std::vector<std::shared_ptr<Edge<T>>>& edgesOut();
	void addEdge(std::shared_ptr<Edge<T>>& edge);

private:
	T _value;
	Node *_pred = nullptr;
	std::vector<std::shared_ptr<Edge<T>>> _edgesIn;
	std::vector<std::shared_ptr<Edge<T>>> _edgesOut;
};

template <class T> inline Node<T>::Node(const T& value)
	:_value{value}{}

template <class T> inline Node<T>::Node(const T&& value)
	:_value{std::move(value)}{}

template <class T> inline void Node<T>::value(const T &value) {
  _value = value;
}

template <class T> inline void Node<T>::value(const T &&value) {
  _value = std::move(value);
}

template <class T> inline T &Node<T>::value() { return _value; }

template <class T> inline const T &Node<T>::value() const { return _value; }

template <class T> inline Node<T> *Node<T>::predecessor() { return _pred; }

template <class T> inline void Node<T>::predecessor(Node* pred) {
  _pred = pred;
}

template <class T> inline std::vector<std::shared_ptr<Edge<T>>>& Node<T>::edgesIn() {
	return _edgesIn;
}

template <class T> inline std::vector<std::shared_ptr<Edge<T>>>& Node<T>::edgesOut() {
	return _edgesOut;
}

template <class T> inline void Node<T>::addEdge(std::shared_ptr<Edge<T>>& edge) {
	if(edge->src() == this)
		_edgesIn.push_back(edge);
	if(edge->dest() == this)
		_edgesOut.push_back(edge);
	}

#endif /* NODE_H */
