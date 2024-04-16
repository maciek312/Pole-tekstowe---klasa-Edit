#include "pole_tekstowe.hpp" 
PoleTekstowe::PoleTekstowe() : pozycja({ 0, 0 }), dlugosc(0), tekstKolor(Kolor::Bialy), tloKolor(Kolor::Czarny) {}

void PoleTekstowe::ustawPozycje(int x, int y) {
    pozycja = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pozycja);
}

void PoleTekstowe::ustawDlugosc(int len) {
    dlugosc = len;
}

void PoleTekstowe::ustawTekst(const std::string& txt) {
    tekst = txt;
}

void PoleTekstowe::ustawKolorTekstu(Kolor kolor) {
    tekstKolor = kolor;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<int>(tekstKolor) | (static_cast<int>(tloKolor) << 4));
}

void PoleTekstowe::ustawKolorTla(Kolor kolor) {
    tloKolor = kolor;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<int>(tekstKolor) | (static_cast<int>(tloKolor) << 4));
}

std::string PoleTekstowe::pobierzTekst() const {
    return tekst;
}

void PoleTekstowe::wprowadzTekst() {
    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == '\r') {
                break;
            }
            else if (ch == '\b') {
                if (!tekst.empty()) {
                    tekst.pop_back();
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pozycja);
                    std::cout << tekst << ' ';
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pozycja);
                }
            }
            else {
                tekst += ch;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pozycja);
                std::cout << tekst;
            }
        }
    }
}

std::ostream& ustawKolor(std::ostream& os, Kolor tekstKolor, Kolor tloKolor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<int>(tekstKolor) | (static_cast<int>(tloKolor) << 4));
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::tuple<Kolor, Kolor>& kolory) {
    Kolor tekstKolor = std::get<0>(kolory);
    Kolor tloKolor = std::get<1>(kolory);
    return ustawKolor(os, tekstKolor, tloKolor);
}

std::ostream& zolty(std::ostream& os) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    return os;
}

std::ostream& czerwony(std::ostream& os) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    return os;
}

std::ostream& niebieski(std::ostream& os) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    return os;
}

std::ostream& zielony(std::ostream& os) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    return os;
}

std::ostream& szary(std::ostream& os) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return os;
}

std::ostream& jasnoniebieski(std::ostream& os) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    return os;
}

std::ostream& jasnozolty(std::ostream& os) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
    return os;
}

std::ostream& cyjan(std::ostream& os) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    return os;
}

std::ostream& magenta(std::ostream& os) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    return os;
}

std::ostream& domyslnyKolor(std::ostream& os) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return os;
}
