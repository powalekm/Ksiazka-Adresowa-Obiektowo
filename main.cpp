#include <iostream>
#include <cstdio>

#include "KsiazkaAdresowa.h"

using namespace std;

int main() {
    char wybor = '0';

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    do {
        if(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika() == 0) {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();
            switch(wybor) {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                system("cls");
                break;
            case '2':
                ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
                ksiazkaAdresowa.logowanieUzytkownika();
                system("cls");
                break;
            }
        } else {
            if (ksiazkaAdresowa.czyAdresaciZostaliWczytani() == false) {
                ksiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika());
            }

            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch (wybor) {
            case '1':
                ksiazkaAdresowa.dodajAdresata(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika());
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                break;
            case '6':
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                break;
            }


        }
    } while(wybor != '9');
    cout << "Program zostaje Wylaczony." << endl;
    return 0;
}
