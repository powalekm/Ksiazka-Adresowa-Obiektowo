#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {
        //(string nazwaPlikuZAdresatami) : adresatMenedzer(nazwaPlikuZAdresatami) {
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
        uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(0);
    };

    void rejestracjaUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();

    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();

    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    bool czyAdresaciZostaliWczytani();
    void dodajAdresata(int IdZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();


};
