#define EmptyStackException -1

#include <iostream>
#include <cstdlib>
#include "node.hh"

class Lista {
    private:
    Node* head;
    public:
    Lista();
    ~Lista();
    bool empty() const;
    const double front() const;
    void addFront(const double& newElem);
    void removeFront();
    Node* getHead() const {return head;}
    void setHead(Node* newHead) {this->head = newHead;}
};

Lista::Lista()
{
    this->head = NULL;
}

Lista::~Lista()
{
    delete this->head;
}

bool Lista::empty() const
{
    return (head==NULL);
}

const double Lista::front() const
{
    try
    {    
    if(this->empty())
        throw EmptyStackException;
    return this->head->getElement();
    }
    catch(int ex)
    {
        std::cout << "Error: Stack empty.";
    }
}

void Lista::addFront(const double& newElem)
{
    Node* temp = new Node(newElem, this->head);
    this->head = temp;
}

void Lista::removeFront()
{
    try
    {    
    if(this->empty())
        throw EmptyStackException;
    Node* temp = this->head;
    this->head=this->head->getNext();
    }
    catch(int ex)
    {
        std::cout << "Error: Stack empty.";
    }
}