#define TAB_ROZMIAR 100
#define EmptyStackException false
#define FullStackException false            

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
double top();   
int size();
bool isEmpty();
bool push(const double& elem);
double pop();
bool displayAll();
void info();
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

double Stos_tablica::top()
{
    if (this->isEmpty())
        return -1;//EmptyStackExecption;
    else 
        return this->tab[elemCount];
}

int Stos_tablica::size()
{
    return this->elemCount+1;
}

bool Stos_tablica::isEmpty()
{
    return this->elemCount==-1;
}

bool Stos_tablica::push(const double& elem)
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
        return true;
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
            for (int i = 0; i< this->size(); i++)
            std::cout << i << ". " << this->tab[i] << std::endl;
        }
}

void Stos_tablica::info()
{
    std::cout << "currentSize: " << this->currentSize << std::endl;
    std::cout << "elemCount: " << this->elemCount << std::endl;
}