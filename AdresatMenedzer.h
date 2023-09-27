#ifndef ADRESATKMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenedzer
{
    vector <Adresat> adresaci;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    public:
    void ustawIdOstatniegoAdresata(int noweId);
    int pobierzIdOstatniegoAdresata();
    void czyszczenieListyAdresatow();

    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    bool czyAdresaciZostaliWczytani();

    void dodajAdresata(int idZalogowanegoUzytkownika);
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    bool czyPlikJestPusty(fstream &plikTekstowy);
    void dopiszAdresataDoPliku(Adresat adresat);

    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata(Adresat adresat);

};

#endif
