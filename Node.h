#pragma once

template <class T>
class Node{
    private:
        T value;
        Node* next;
    public:
        Node (T value);

        T getValue();
        Node<T>* getNext();

        void setValue(T value);
        void setNext(Node<T>* next);

        ~Node();
};