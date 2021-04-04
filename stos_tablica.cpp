#include "stos_tablica.hh"

Stos_tablica::Stos_tablica()
{
    this->currentSize = TAB_ROZMIAR;
    this->elemCount = -1;
}

Stos_tablica::~Stos_tablica()
{

}

double Stos_tablica::top()
{
    if (this->isEmpty())
        return this->tab[elemCount];
    else 
        return 0;//EmptyStackExecption;
}

int Stos_tablica::size()
{
    return this->elemCount;
}

bool Stos_tablica::isEmpty()
{
    return this->elemCount==-1;
}

bool Stos_tablica::push(const double& elem)
{
    if(this->elemCount>=this->currentSize-1)
    {
        return false;
    }
    else 
    {
        this->elemCount++;
        this->tab[elemCount]=elem;
        return true;
    }
}

double Stos_tablica::pop()
{
    if(this->isEmpty())
        return 0;
    else
    {
        this->elemCount--;
        return tab[this->elemCount+1];
    }
}