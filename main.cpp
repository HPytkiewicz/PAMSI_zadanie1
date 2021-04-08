#include "stos_tablica.hh"
#include "stos_lista.hh"
#include <cstdlib>

void menu()
{
    std::cout << "Podaj swoj wybor" << std::endl;
    std::cout << "1. Dodaj element do stosu" << std::endl;
    std::cout << "2. Zdejmij element ze stosu" << std::endl;
    std::cout << "3. Wyswietl element na szczycie stosu" << std::endl;
    std::cout << "4. Wyswietl caly stos" << std::endl;
    std::cout << "5. Wyjdz z programu" << std::endl;
}

int main() {
    int menuChoice;
    bool quit = false;
    Stos_lista stos;

    
    for(int i =0; i<100;i++)
    {
        stos.push(i); //stos.push((rand()%2000)-1000);
    }
    

    while (!quit){
    menu();
    std::cin >> menuChoice;
    switch(menuChoice){
        case 1:
        int x;
        std::cout << "Podaj dodawany element: ";
        std::cin >> x;
        stos.push(x);
        break;
        case 2:
        std::cout << "Zpopowany element: " <<  stos.pop();
        break;
        case 3:
        std::cout << "Element na szczycie stosu: " << stos.top();
        break;
        case 4:
        stos.displayAll();
        break;
        case 5:
        quit = true;
        default:
        std::cout << "Niepoprawna komenda.";
        break;
    }
    }
    return 0;
}