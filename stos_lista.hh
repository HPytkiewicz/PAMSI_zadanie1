#include "Lista.hh"

class Stos_lista
{
    public: 
    int size();
    bool isEmpty();
    double& top();
    void push(double newElem);
    double pop();
};