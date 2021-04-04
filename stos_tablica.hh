#define TAB_ROZMIAR 100
#define EmptyStackException false
#define FullStackException false            

#include <iostream>

// Stos przechowujący zmienne type double

class Stos_tablica {
    private:
    double tab[TAB_ROZMIAR];
    int currentSize;
    int elemCount;

public:
Stos_tablica();  // Konstruktor stosu
~Stos_tablica();    // Destruktor stosu
double top();   
int size();
bool isEmpty();
bool push(const double& elem);
double pop();
bool displayAll();
};

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
        return 0;//EmptyStackExecption;
    else 
        return this->tab[elemCount];
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

bool Stos_tablica::displayAll()
{
    if(this->isEmpty())
        return false;
    else
        {
            for (int i = 0; i< this->elemCount+1; i++)
            std::cout << i << ". " << this->tab[i] << std::endl;
        }
}