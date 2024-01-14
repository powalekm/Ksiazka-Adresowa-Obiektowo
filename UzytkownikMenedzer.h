#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

    vector <Uzytkownik> uzytkownicy;
    Uzytkownik podajDaneNowegoUzytkownika();

    PlikZUzytkownikami plikZUzytkownikami;

public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
    ustawIdZalogowanegoUzytkownika(0);
    };

    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();

    void ustawIdZalogowanegoUzytkownika(int noweId);
    int pobierzIdZalogowanegoUzytkownika();
    string pobierzLoginZalogowanegoUzytkownika();

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);
};

#endif
