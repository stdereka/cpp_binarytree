#include <iostream>


#ifndef PROJECT_NODE_HPP
#define PROJECT_NODE_HPP


template <class T>
class Node {
private:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
public:
    Node()= default;
    explicit Node(T data);
    Node(Node<T>* parent, T data);
    Node(const Node<T>& other, Node<T>* par);
    ~Node();
    void setdata(T data);
    void setright(Node<T>* right);
    void setleft(Node<T>* left);
    void setparent(Node<T>* parent);
    T getdata();
    Node<T>* getright();
    Node<T>* getleft();
    Node<T>* getparent();
};


template <class T>
std::ostream &operator<<(std::ostream &stream, Node<T>& n);


template <class T>
class TreeIterator {
private:
    Node<T>* current;
public:
    explicit TreeIterator(Node<T>* start);
    ~TreeIterator()= default;
    void setcurrent(Node<T>* current);
    void toright();
    void toleft();
    void up();
    Node<T>* getcurrent();
};


#endif //PROJECT_NODE_HPP
