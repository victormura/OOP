#ifndef HW_1_NODE_H
#define HW_1_NODE_H
class Node{
    int value{};
    Node *next{};
public:
    explicit Node(int value);

    int getValue();
    void setValue(int value);
    Node *getNext();
    void setNext(Node *next);
};
#endif // HW_1_NODE_H