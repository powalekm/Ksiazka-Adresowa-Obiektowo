#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(uzytkownikMenedzer.logowanieUzytkownika());
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(0);
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika()
{
    return uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
     return uzytkownikMenedzer.wybierzOpcjeZMenuGlownego();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
     return uzytkownikMenedzer.wybierzOpcjeZMenuUzytkownika();
}
