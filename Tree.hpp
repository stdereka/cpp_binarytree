#include "Node.hpp"


#ifndef PROJECT_TREE_HPP
#define PROJECT_TREE_HPP


template <class T>
class Tree {
private:
    Node<T>* root;
    bool empty;
    TreeIterator<T>* iter;
public:
    Tree();
    ~Tree();
    Tree(const Tree<T>& other);
    TreeIterator<T>* it();
    void addvalue(T value);
    bool isempty();
    Node<T>* getnodebydata(T data);
    bool isin(T data);
    void removesubtree(T data);
    Tree<T>& operator=(const Tree<T>& other);
};


template <class T>
void operator<<(std::ostream &stream, Tree<T>& tree);


#endif //PROJECT_TREE_HPP
