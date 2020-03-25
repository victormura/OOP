#include "DynamicSet.h"
#include <iostream>
#include <algorithm>

DynamicSet :: DynamicSet() = default;

DynamicSet :: DynamicSet(int value){
    first = new Node(value);
    resetCurrent();
}

DynamicSet :: DynamicSet(DynamicSet &set){
    this->first = new Node(*set.first);
    this->resetCurrent();
    set.resetCurrent();
    set.getNextValue();
    while (set.getCurrent()) {
        this->addNode(set.getNextValue());
    }
    set.resetCurrent();
    this->resetCurrent();
}

DynamicSet :: DynamicSet(int v[], int size){
    resetCurrent();
    std :: sort(v, v+size);
    int last = v[0];
    first = new Node(v[0]);
    current = const_cast<Node *>(first);
    for(int i = 1; i < size; i++){
        if(v[i] != last)
            addNode(v[i]);
        last = v[i];
    }
    resetCurrent();
}

DynamicSet :: ~DynamicSet(){
    resetCurrent();
    removeSet(current);
    first = nullptr;
    current = nullptr;
}

Node* DynamicSet:: getFirst(){
    return const_cast<Node *>(first);
}
Node* DynamicSet:: getCurrent(){
    return current;
}
void DynamicSet:: resetCurrent(){
    current = const_cast<Node *>(first);
}
void DynamicSet:: addNode(int value){
    Node *nou = new Node(value);
    current->setNext(nou);
    current = current->getNext();
}
int DynamicSet:: getNextValue(){
    int rez = current->getValue();
    current = current->getNext();
    return rez;
}

void DynamicSet:: operator = (DynamicSet set) {
    this->first = new Node(*set.first);
    this->resetCurrent();
    set.resetCurrent();
    set.getNextValue();
    while (set.getCurrent()) {
        this->addNode(set.getNextValue());
    }
    set.resetCurrent();
    this->resetCurrent();
}

void DynamicSet:: printSet() {
    resetCurrent();
    while(true){
        std :: cout << current->getValue() << ' ';
        if(current->getNext() == nullptr)
            break;
        current = current->getNext();
    }
    std :: cout << std :: endl;
    resetCurrent();
}

void DynamicSet:: removeSet(Node* n){
    if(n->getNext() != nullptr){
        removeSet(n->getNext());
    }
    delete n;
}

DynamicSet operator + (DynamicSet set1, DynamicSet(set2)) {
    int last;
    int x1, x2;
    DynamicSet reunion;
    x1 = set1.getFirst()->getValue();
    x2 = set2.getFirst()->getValue();
    if (x1 < x2){
        last = x1;
        reunion = DynamicSet(last);
    } else {
        last = x2;
        reunion = DynamicSet(last);
    }

    while((set1.getCurrent() != nullptr) || (set2.getCurrent() != nullptr)){
        if(x1 == last && set1.getCurrent())
            x1 = set1.getNextValue();
        if(x2 == last && set2.getCurrent())
            x2 = set2.getNextValue();
        if(x1 != last && x2 != last){
            if(x1 <= x2 && set1.getCurrent()){
                reunion.addNode(x1);
                last = x1;
                x1 = set1.getNextValue();
            } else if(set2.getCurrent()){
                reunion.addNode(x2);
                last = x2;
                x2 = set2.getNextValue();
            }
        }
    }
    if(x1 < x2){
        if(x1 != last)
            reunion.addNode(x1);
        reunion.addNode(x2);
    } else if(x1 > x2){
        if(x2 != last)
            reunion.addNode(x2);
        reunion.addNode(x1);
    } else if(x1 != last){
        reunion.addNode(x1);
    }
    reunion.resetCurrent();
    return DynamicSet(reunion);
}

DynamicSet operator * (DynamicSet set1, DynamicSet(set2)) {
    bool initialized = false;
    int x1, x2;
    DynamicSet intersection;
    x1 = set1.getNextValue();
    x2 = set2.getNextValue();

    while((set1.getCurrent() != nullptr ) && (set2.getCurrent() != nullptr)){
        if(x1 == x2){
            if(!initialized) {
                intersection = DynamicSet(x1);
                initialized = true;
            }
            else {
                intersection.addNode(x1);
            }
            x1 = set1.getNextValue();
            x2 = set2.getNextValue();
        } else if(x1 < x2){
            x1 = set1.getNextValue();
        } else if(x1 > x2){
            x2 = set2.getNextValue();
        }
    }

    if(set1.getCurrent())
        x1 = set1.getNextValue();
    if(set2.getCurrent())
        x2 = set2.getNextValue();

    if(x1 == x2)
        intersection.addNode(x1);

    intersection.resetCurrent();
    return intersection;
}

DynamicSet operator - (DynamicSet set1, DynamicSet(set2)) {
    bool initialized = false;
    int x1, x2;

    DynamicSet difference;
    DynamicSet set = set1;
    DynamicSet intersection = set1 * set2;
    x1 = set.getNextValue();
    x2 = intersection.getNextValue();

    while(set.getCurrent() != nullptr){
        if (x1 == x2) {
            x1 = set.getNextValue();
            if(intersection.getCurrent())
                x2 = intersection.getNextValue();
        } else if (x1 < x2) {
            if (!initialized) {
                difference = DynamicSet(x1);
                initialized = true;
            } else {
                difference.addNode(x1);
            }
            x1 = set.getNextValue();
        } else if (x1 > x2) {
            if (!initialized) {
                difference = DynamicSet(x2);
                initialized = true;
            } else {
                if(intersection.getCurrent())
                    difference.addNode(x2);
                else
                    difference.addNode(x1);
            }
            if(intersection.getCurrent())
                x2 = intersection.getNextValue();
        }
    }
    difference.resetCurrent();
    return difference;
}
