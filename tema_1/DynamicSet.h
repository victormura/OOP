#include <iostream>
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
    friend std::istream& operator >> (std::istream& flux_in, DynamicSet& set){
        set.removeSet(set.getFirst());
        set.current = set.getFirst();
        int n;
        flux_in >> n;
        for(int i = 1; i <= n; i++){
            int x;
            flux_in >> x;
            set.addNode(x);
        }
        return flux_in;
    }
    void printSet();

private:
    static void removeSet(Node* n);
};

DynamicSet operator + (DynamicSet m1, DynamicSet m2);
DynamicSet operator * (DynamicSet m1, DynamicSet m2);
DynamicSet operator - (DynamicSet m1, DynamicSet m2);

#endif //TEMA_1_DYNAMICSET_H

