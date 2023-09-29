#ifndef ADRESATKMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer {
    vector <Adresat> adresaci;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    PlikZAdresatami plikZAdresatami;

    void ustawIdOstatniegoAdresata(int noweId);
    int pobierzIdOstatniegoAdresata();
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    void wyswietlDaneAdresata(Adresat adresat);

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {};

    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika); // do obslugi pliku?
    bool czyAdresaciZostaliWczytani(); // do obslugi pliku?
    void dodajAdresata(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();
    void czyszczenieListyAdresatow();
};

#endif
