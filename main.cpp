#include "stos_tablica.hh"
#include "stos_lista.hh"
#include <cstdlib>
#include <ctime>

void menu()
{
    std::cout << "Podaj swoj wybor" << std::endl;
    std::cout << "1. Dodaj element na stos" << std::endl;
    std::cout << "2. Zdejmij element ze stosu" << std::endl;
    std::cout << "3. Wyswietl element na szczycie stosu" << std::endl;
    std::cout << "4. Wyswietl caly stos" << std::endl;
    std::cout << "5. Dodaj do stosu x losowych elementow" << std::endl;
    std::cout << "6. Zmien stos" << std::endl;
    std::cout << "7. Wyjdz z programu" << std::endl;
}

int main() {
    int menuChoice;
    bool quit = false;
    bool isTable = true;
    Stos_tablica stosT;
    Stos_lista stosL;


    while (!quit){
    menu();
    if(isTable){
    std::cout << "Aktualny stos jest oparty na tablicy" << std::endl;
    std::cin >> menuChoice;
    switch(menuChoice){
        case 1:
        int x;
        std::cout << "Podaj dodawany element: ";
        std::cin >> x;
        stosT.push(x);
        break;
        case 2:
        std::cout << "Zpopowany element: " <<  stosT.pop() << std::endl;
        break;
        case 3:
        std::cout << "Element na szczycie stosu: " << stosT.top() << std::endl;
        break;
        case 4:
        stosT.displayAll();
        break;
        case 5:
        std::cout << "Podaj ilosc losowo dodanych elementow: " << std::endl;
        int quantity;
        std::cin >> quantity;
        clock_t t;
        t = clock();
        for(int i =0; i<quantity;i++)
        {
            stosT.push((rand()%200000)-100000);
        }
        t = clock() -t;
        std::cout << "Dodanie do stosu " << quantity <<" elemetow zajmuje: " << 1000*((float)t)/CLOCKS_PER_SEC << " milisekund." << std::endl;
        break;
        case 6:
        isTable = !isTable;
        break;
        case 7:
        quit = true;
        break;
        default:
        std::cout << "Niepoprawna komenda.";
        break;
    }
    }
    else
    {
    std::cout << "Aktualny stos jest oparty na liscie jednokierunkowej" << std::endl;
    std::cin >> menuChoice;
        switch(menuChoice){
        case 1:
        int x;
        std::cout << "Podaj dodawany element: ";
        std::cin >> x;
        stosL.push(x);
        break;
        case 2:
        std::cout << "Zpopowany element: " <<  stosL.pop() << std::endl;
        break;
        case 3:
        std::cout << "Element na szczycie stosu: " << stosL.top() << std::endl;
        break;
        case 4:
        stosL.displayAll();
        break;
        case 5:
        std::cout << "Podaj ilosc losowo dodanych elementow: " << std::endl;
        int quantity;
        std::cin >> quantity;
        clock_t t;
        t = clock();
        for(int i =0; i<quantity;i++)
        {
            stosL.push((rand()%200000)-100000);
        }
        t = clock() -t;
        std::cout << "Dodanie do stosu " << quantity <<" elemetow zajmuje: " << 1000*((float)t)/CLOCKS_PER_SEC << " milisekund." << std::endl;
        break;
        case 6:
        isTable = !isTable;
        break;
        case 7:
        quit = true;
        break;
        default:
        std::cout << "Niepoprawna komenda.";
        break;
    }
    }
    }
    return 0;
}