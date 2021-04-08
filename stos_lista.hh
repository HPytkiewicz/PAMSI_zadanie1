#include "Lista.hh"

class Stos_lista
{
    private:
    Lista* lista;
    int elemCount;

    public: 
    Stos_lista();
    ~Stos_lista();
    int size();
    bool isEmpty();
    double top();
    void push(double newElem);
    double pop();
    void displayAll();
    void removeAll();
};

Stos_lista::Stos_lista()
{
    this->lista = new Lista();
    this->elemCount = -1;
}

Stos_lista::~Stos_lista()
{
    delete this->lista;
}

int Stos_lista::size()
{
    return this->elemCount;
}

bool Stos_lista::isEmpty()
{
    return (elemCount==-1);
}

double Stos_lista::top()
{
    return this->lista->front();
}

void Stos_lista::push(double newElem)
{
    this->lista->addFront(newElem);
    this->elemCount++;
}

double Stos_lista::pop()
{
    double temp = this->lista->front();
    this->lista->removeFront();
    this->elemCount--;
    return temp;

}

void Stos_lista::displayAll()
{
    Node* temp = this->lista->getHead();
    int i= this->elemCount;
    while(temp != NULL)
    {
        std::cout << this->elemCount-i << ". " << temp->getElement() << std::endl;
        temp = temp->getNext();
        i--;
    }

}

void Stos_lista::removeAll()
{
    for(int i=0; i<this->size(); i++)
        this->pop();
    this->lista->setHead(NULL);
}