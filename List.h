#pragma once
#include <Node.h>

class List {
    private:
        Node* start;
    public:
        List();

        void insert(int value, int index);
        void insertFirst(int value);
        void insertLast(int value);

        int get(int index);
        int getFirst();
        int getLast();
};