#ifndef EDGE_H
#define EDGE_H

#include <utility>
#include <vector>
#include <memory>
#include <cstdint>

template <class T> class Node;

template <class T> class  Edge {

public:
  
	const uint16_t id() const ;
	void id(const uint16_t edge_id);
	bool src(Node<T>* srcNode);
	Node<T>* src();
	bool dst(Node<T>* dstNode);
	Node<T>* dst();

private:
	uint16_t _id;
	Node<T>* _src = nullptr;
	Node<T>* _dst = nullptr;
	
};

template <class T> inline const uint16_t Edge<T>::id() const { return _id;}

template <class T> inline void Edge<T>::id(uint16_t edge_id) { _id = edge_id;}

template <class T> inline bool Edge<T>::src(Node<T>* srcNode) {
	if(srcNode != nullptr)
		return false;
	_src = srcNode;
	return true;
}

template <class T> inline Node<T>* Edge<T>::src() { return _src;}

template <class T> inline bool Edge<T>::dst(Node<T>* dstNode) {
	if(dstNode != nullptr)
		return false;
	_dst = dstNode;
	return true;
}

template <class T> inline Node<T>* Edge<T>::dst() { return _dst;}

#endif /* EDGE_H */
