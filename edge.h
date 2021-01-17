#include <utility>
#include <vector>
#include <memory>


template <class T> class  Edge {

public:
  void value(const T &value);
  void value(const T &&value);
  T &value();
  const T &value() const;
  Node *predecessor();
  void predecessor(Node* pred);
	std::vector<std::shared_ptr<Edge>>& edgesIn();
	std::vector<std::shared_ptr<Edge>>& edgesOut();
	void addEdge(std::shared_ptr<Edge>& edge);

private:
	T _value;
	Node *_pred = nullptr;
	std::vector<std::shared_ptr<Edge>> _edgesIn;
	std::vector<std::shared_ptr<Edge>> _edgesOut;
};
