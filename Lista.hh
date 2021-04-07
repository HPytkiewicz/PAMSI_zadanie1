#include <iostream>
#include <cstdlib>
#include <node.hh>

class Lista {
    private:
    Node* head;
    public:
    Lista();
    ~Lista();
    bool empty() const;
    const double& front() const;
    void addFront(const double& newElem);
    void removeFront();
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

const double& Lista::front() const
{
    if(this->empty())
        return 0;   //tymczasowe
    return this->head->getElement();
}

void Lista::addFront(const double& newElem)
{
    Node* temp = new Node(newElem, this->head);
    this->head = temp;
}

void Lista::removeFront()
{
    Node* temp = this->head;
    this->head=this->head->getNext();
    delete temp;
}