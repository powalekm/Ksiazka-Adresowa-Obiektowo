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
    vector <Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    PlikZUzytkownikami plikZUzytkownikami;

public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {};
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();

    //Nowe funkcjionalnosci
    void ustawIdZalogowanegoUzytkownika(int noweId);
    int pobierzIdZalogowanegoUzytkownika();
    string pobierzLoginZalogowanegoUzytkownika();

    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);

    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
};

#endif
