#ifndef POLE_TEKSTOWE_HPP
#define POLE_TEKSTOWE_HPP

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <tuple>

enum class Kolor {
    Czarny = 0,
    Niebieski = 1,
    Zielony = 2,
    Cyjan = 3,
    Czerwony = 4,
    Magenta = 5,
    Zolty = 6,
    Bialy = 7,
    Szary = 8,
    JasnoNiebieski = 9,
    JasnoZielony = 10,
    JasnoCyjan = 11,
    JasnoCzerwony = 12,
    JasnoMagenta = 13,
    JasnoZolty = 14,
    JasnoBialy = 15
};

class PoleTekstowe {
private:
    COORD pozycja;
    int dlugosc;
    std::string tekst;
    Kolor tekstKolor;
    Kolor tloKolor;

public:
    PoleTekstowe();

    void ustawPozycje(int x, int y);

    void ustawDlugosc(int len);

    void ustawTekst(const std::string& txt);

    void ustawKolorTekstu(Kolor kolor);

    void ustawKolorTla(Kolor kolor);

    std::string pobierzTekst() const;

    void wprowadzTekst();
};

std::ostream& ustawKolor(std::ostream& os, Kolor tekstKolor, Kolor tloKolor);

std::ostream& operator<<(std::ostream& os, const std::tuple<Kolor, Kolor>& kolory);

std::ostream& zolty(std::ostream& os);
std::ostream& czerwony(std::ostream& os);
std::ostream& niebieski(std::ostream& os);
std::ostream& zielony(std::ostream& os);
std::ostream& szary(std::ostream& os);
std::ostream& jasnoniebieski(std::ostream& os);
std::ostream& jasnozolty(std::ostream& os);
std::ostream& cyjan(std::ostream& os);
std::ostream& magenta(std::ostream& os);
std::ostream& domyslnyKolor(std::ostream& os);

#endif 
