#include "Tree.hpp"


template <class T>
Tree<T>::Tree(){
    root = new Node<T>();
    iter = new TreeIterator<T>(root);
    empty = true;
}


template <class T>
Tree<T>::~Tree(){
    delete root;
    delete iter;
}


template <class T>
Tree<T>::Tree(const Tree<T>& other){
    root = new Node<T>(*other.root, nullptr);
    iter = new TreeIterator<T>(root);
    empty = other.empty;
}


template <class T>
bool Tree<T>::isempty(){
    return this->empty;
}


template <class T>
TreeIterator<T>* Tree<T>::it(){
    return iter;
}


template <class T>
void Tree<T>::addvalue(T value){
    while (true){
        if (empty){
            iter->getcurrent()->setdata(value);
            empty = false;
            return;
        }
        if (iter->getcurrent()->getdata() == value){
            iter->setcurrent(root);
            return;
        }
        if (value < iter->getcurrent()->getdata()){
            if (iter->getcurrent()->getleft() == nullptr){
                auto* p = new Node<T>(iter->getcurrent(), value);
                iter->getcurrent()->setleft(p);
                iter->setcurrent(root);
                return;
            }
            iter->toleft();
        }else{
            if (iter->getcurrent()->getright() == nullptr){
                auto* p = new Node<T>(iter->getcurrent(), value);
                iter->getcurrent()->setright(p);
                iter->setcurrent(root);
                return;
            }
            iter->toright();
        }
    }
}


template <class T>
void operator<<(std::ostream &stream, Tree<T>& tree){
    if (tree.it()->getcurrent()->getleft()){
        tree.it()->toleft();
        stream << tree;
        tree.it()->up();
    }
    stream << *tree.it()->getcurrent();
    if (tree.it()->getcurrent()->getright()){
        tree.it()->toright();
        stream << tree;
        tree.it()->up();
    }
}


template <class T>
Node<T>* Tree<T>::getnodebydata(T data){
    if (empty){
        return nullptr;
    }
    while (true){
        if (iter->getcurrent() == nullptr){
            iter->setcurrent(root);
            return nullptr;
        }
        if (iter->getcurrent()->getdata() == data){
            Node<T>* p = iter->getcurrent();
            iter->setcurrent(root);
            return p;
        }
        if (data < iter->getcurrent()->getdata()){
            iter->toleft();
            continue;
        }
        if (data > iter->getcurrent()->getdata()){
            iter->toright();
            continue;
        }
    }
}


template <class T>
bool Tree<T>::isin(T data){
    return getnodebydata(data) != nullptr;
}


template <class T>
void Tree<T>::removesubtree(T data){
    Node<T>* p = getnodebydata(data);
    if (!p){
        return;
    }
    if (p == root){
        delete root;
        root = new Node<T>();
        empty = true;
        return;
    }
    if (p->getparent()->getleft() == p) {
        p->getparent()->setleft(nullptr);
    }
    if (p->getparent()->getright() == p) {
        p->getparent()->setright(nullptr);
    }
    delete p;
}


template <class T>
Tree<T>& Tree<T>::operator=(const Tree<T> &other){
    delete root;
    root = new Node<T>(*other.root, nullptr);
    empty = other.empty;
}
