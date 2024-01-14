#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami {
    int idOstatniegoAdresata;
    const string nazwaPlikuZAdresatami;
    bool czyPlikJestPusty(fstream &plikTekstowy);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);

    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI) {
    idOstatniegoAdresata = 0;
    };

    void dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void zapiszWszystkichAdresatowDoPliku(vector <Adresat> uzytkownicy);
    Adresat pobierzDaneAdresata(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

    void ustawIdOstatniegoAdresata(int NoweIdOstatniegoAdresata);
    int pobierzIdOstatniegoAdresata();
};
#endif
