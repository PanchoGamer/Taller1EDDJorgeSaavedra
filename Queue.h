#pragma once
#include "Node.h"

template <class T>
class Queue {
    private:
        Node<T>* start;
    public:
        Queue();

        bool empty();
        void push(T value);
        void pop();
        T front();
        Node<T>* getStart();
        void clear();
        int size();

        ~Queue();
};
#include "Queue.cpp"