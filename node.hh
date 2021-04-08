#include <iostream>
#include <cstdlib>

class Node {
    private:
    double elem;
    Node* next;
    friend class stos_lista;

    public:
    Node(double newElem, Node* newNext);
    Node(const Node& newNode);
    ~Node();
    double getElement() {return this->elem;}
    Node* getNext() {return this->next;}
    void setElement(double newElem) {this->elem=newElem;}
    void setNext(Node*  newNext) {this->next=newNext;}
};

Node::Node(double newElem, Node* newNext)
{
    this->elem = newElem;
    this->next = newNext;
}

Node::Node(const Node& newNode)
{
    this->elem = newNode.elem;
    this->next = newNode.next;
}

Node::~Node()
{
    delete this->next;
}

