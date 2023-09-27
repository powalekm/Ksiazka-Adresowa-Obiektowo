#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(uzytkownikMenedzer.logowanieUzytkownika());
}

void KsiazkaAdresowa::wylogowanieUzytkownika() {
    uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(0);
    adresatMenedzer.czyszczenieListyAdresatow();
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika() {
    return uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {
    return uzytkownikMenedzer.wybierzOpcjeZMenuGlownego();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
    return uzytkownikMenedzer.wybierzOpcjeZMenuUzytkownika();
}

void KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}

bool KsiazkaAdresowa::czyAdresaciZostaliWczytani() {
    return adresatMenedzer.czyAdresaciZostaliWczytani();
}
void KsiazkaAdresowa::dodajAdresata(int IdZalogowanegoUzytkownika) {
    adresatMenedzer.dodajAdresata(IdZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    adresatMenedzer.wyswietlWszystkichAdresatow();
}
