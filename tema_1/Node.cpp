#include "Node.h"

Node :: Node(int value){
    setValue(value);
    setNext(nullptr);
}

int Node :: getValue(){
    return this->value;
}

void Node :: setValue(int value){
    this->value = value;
}

Node* Node :: getNext(){
    return this->next;
}

void Node :: setNext(Node *next){
    this->next = next;
}
