#include "Node.h"

#ifndef TEMA_1_DYNAMICSET_H
#define TEMA_1_DYNAMICSET_H

class DynamicSet{
    const Node *first = nullptr;
    Node *current = nullptr;

public:
    DynamicSet();

    explicit DynamicSet(int value);

    DynamicSet(DynamicSet &m);
    DynamicSet(int v[], int size);
    ~DynamicSet();
    Node* getFirst();
    Node* getCurrent();
    void resetCurrent();
    void addNode(int value);
    int getNextValue();
    void operator = (DynamicSet m);
    void printSet();

private:
    static void removeSet(Node* n);
};

DynamicSet operator + (DynamicSet m1, DynamicSet m2);
DynamicSet operator * (DynamicSet m1, DynamicSet m2);
DynamicSet operator - (DynamicSet m1, DynamicSet m2);

#endif //TEMA_1_DYNAMICSET_H

