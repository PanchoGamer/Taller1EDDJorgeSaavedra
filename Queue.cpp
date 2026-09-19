#pragma once
#include "Queue.h"

template <class T>
Queue<T>::Queue(){ 
    this->start = nullptr;
}

template <class T>
bool Queue<T>::empty(){
    return this->start == nullptr;
}

template <class T>
void Queue<T>::push(T value){
    if(this->start==nullptr){
        start = new Node<T>(value);
        return;
    }

    Node<T>* cursor = this->start;
    while (cursor->getNext() != nullptr){
        cursor = cursor->getNext();
    }
    cursor->setNext(new Node<T>(value));
}

template <class T>
void Queue<T>::pop(){
    if(this->start == nullptr) throw 0;

    Node<T>* temp = this->start->getNext();
    delete this->start;
    start = temp;
}

template <class T>
T Queue<T>::front(){
    if(this->start == nullptr) throw 0;
    return this->start->getValue();
}

template <class T>
void Queue<T>::clear(){
    while (this->start != nullptr){
        Node<T>* temp = this->start->getNext();
        delete this->start;
        this->start = temp;
    }
}

template <class T>
int Queue<T>::size(){
    int contador = 0;
    Node<T>* actual = this->start;
    while(actual!=nullptr){
        contador++;
        actual = actual->getNext();
    }
    return contador;
}

template <class T>
Queue<T>::~Queue(){
    clear();
}