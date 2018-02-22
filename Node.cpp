#include "Node.hpp"


template <class T>
Node<T>::Node(T data):data(data), left(nullptr), right(nullptr), parent(nullptr){}


template <class T>
Node<T>::Node(Node<T>* parent, T data):data(data), parent(parent), left(nullptr), right(nullptr){}


template <class T>
Node<T>::Node(const Node<T> &other, Node<T>* par){
    data = other.data;
    parent = par;
    if (other.left){
        left = new Node<T>(*other.left, this);
    }else{
        left = nullptr;
    }
    if (other.right){
        right = new Node<T>(*other.right, this);
    }else{
        right = nullptr;
    }
}


template <class T>
Node<T>::~Node(){
    delete this->right;
    delete this->left;
}


template <class T>
void Node<T>::setdata(T data){
    this->data = data;
}


template <class T>
void Node<T>::setleft(Node<T>* left){
    this->left = left;
}


template <class T>
void Node<T>::setright(Node<T>* right){
    this->right = right;
}


template <class T>
void Node<T>::setparent(Node<T> *parent){
    this->parent = parent;
}


template <class T>
Node<T>* Node<T>::getleft(){
    return this->left;
}


template <class T>
Node<T>* Node<T>::getright(){
    return this->right;
}


template <class T>
T Node<T>::getdata() {
    return this->data;
}


template <class T>
Node<T>* Node<T>::getparent(){
    return this->parent;
}


template <class T>
std::ostream &operator<<(std::ostream &stream, Node<T>& n){
    return stream << n.getdata() << " ";
}


template <class T>
TreeIterator<T>::TreeIterator(Node<T>* start):current(start){}


template <class T>
void TreeIterator<T>::setcurrent(Node<T>* current){
    this->current = current;
}


template <class T>
void TreeIterator<T>::toleft(){
    this->current = this->current->getleft();
}


template <class T>
void TreeIterator<T>::toright(){
    this->current = this->current->getright();
}


template <class T>
void TreeIterator<T>::up(){
    this->current = this->current->getparent();
}


template <class T>
Node<T>* TreeIterator<T>::getcurrent(){
    return this->current;
}
