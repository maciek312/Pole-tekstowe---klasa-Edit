#include <iostream>
#include <conio.h>
#include <windows.h>
#include "pole_tekstowe.hpp" 
int main() {
   
    PoleTekstowe p;
    p.ustawPozycje(7, 3); 
    p.ustawDlugosc(25); 
    p.ustawTekst("Ala ma kota"); 
    p.ustawKolorTekstu(Kolor::Niebieski); 
    p.ustawKolorTla(Kolor::Zielony);
    std::string s = p.pobierzTekst(); 
    std::cout << "Pole tekstowe nr. 1" << std::endl;
    std::cout << "Zawartosc pola tekstowego: " << s;
    _getch();
    p.wprowadzTekst(); 
    system("cls");
    s = p.pobierzTekst(); 
    std::cout << "Zawartoœæ pola tekstowego: " << s;
    _getch();
    system("cls");
    std::cout << "Pole tekstowe nr. 2" << std::endl;
    PoleTekstowe p2(p); 
    p2.ustawPozycje(10, 15); 
    p2.ustawKolorTla(Kolor::Bialy);
    s = p2.pobierzTekst(); 
    std::cout << "Zawartosc pola tekstowego: " << s;
    _getch();
    p2.wprowadzTekst(); 
    system("cls");
    s = p2.pobierzTekst(); 
    std::cout << "Zawartosc pola tekstowego: " << s;
    _getch();

    
    system("cls");
    std::cout << "Druga czesc programu" << std::endl;
    std::cout << zolty << "A" << czerwony << "l" << niebieski << "a" << zielony << "m" << szary << "a"
        << jasnoniebieski << "k" << jasnozolty << "o" << cyjan << "t" << magenta << "a";
    std::cout << std::make_tuple(Kolor::Zolty, Kolor::Czerwony) << "Miauu" << std::endl; // Zmieniona nazwa enumeratora
    _getch();
    return 0;
}
