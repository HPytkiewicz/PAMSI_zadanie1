#define TAB_ROZMIAR 100
#define EmptyStackException -1
#define FullStackException 1            

#include <iostream>

// Stos przechowujący zmienne type double

class Stos_tablica {
    private:
    double *tab;
    int currentSize;
    int elemCount;

public:
Stos_tablica(int size = TAB_ROZMIAR);  // Konstruktor stosu
~Stos_tablica();    // Destruktor stosu
double& top();   
int size();
bool isEmpty();
void push(const double& elem);
double pop();
void displayAll();
//void info();
};

Stos_tablica::Stos_tablica(int size)
{
    this->tab = new double[size];
    this->elemCount = -1;
    this->currentSize = size;
}

Stos_tablica::~Stos_tablica()
{
    delete [] tab;
}

double& Stos_tablica::top()
{
    try
    {
        if(this->isEmpty())
            throw EmptyStackException;
        return this->tab[elemCount];
    }
    catch(int ex)
    {
        std::cout << "Error: Empty stack" << std::endl;
    }
    //return this->tab[elemCount];
}

int Stos_tablica::size()
{
    return this->elemCount+1;
}

bool Stos_tablica::isEmpty()
{
    return this->elemCount==-1;
}

void Stos_tablica::push(const double& elem)
{
    if(this->elemCount==this->currentSize-1)
    {
        double* temp = new double[this->currentSize*2];

        for(int i = 0; i<this->elemCount+1; i++)
            temp[i] = this->tab[i];
        this->currentSize *= 2;
        this->tab = temp;
    }
        this->elemCount++;
        this->tab[elemCount]=elem;
}

double Stos_tablica::pop()
{
    try
    {
        if(this->isEmpty())
            throw EmptyStackException;
        this->elemCount--;
        return tab[this->elemCount+1];
    }
    catch(int ex)
    {
        std::cout << "Error: Empty stack" << std::endl;
    }
    //this->elemCount--;
    //return tab[this->elemCount+1];
}

void Stos_tablica::displayAll()
{
    try
    {
        if(this->isEmpty())
            throw EmptyStackException;
        for (int i = 0; i< this->size(); i++)
        std::cout << i << ". " << this->tab[i] << std::endl;
    }
    catch(int ex)
    {
        std::cout << "Error: Empty stack" << std::endl;
    }
    //for (int i = 0; i< this->size(); i++)
    //std::cout << i << ". " << this->tab[i] << std::endl;
}

/*
void Stos_tablica::info()
{
    std::cout << "currentSize: " << this->currentSize << std::endl;
    std::cout << "elemCount: " << this->elemCount << std::endl;
}
*/