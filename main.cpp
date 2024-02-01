#include <iostream>
#include <cstdio>

#include "KsiazkaAdresowa.h"

using namespace std;

int main() {
    char wybor = '0';

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    do {
        if(!ksiazkaAdresowa.czyUzytkownikJestZalogowany()) {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();
            switch(wybor) {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            }
        } else {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();
            switch (wybor) {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                system("pause");
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                ksiazkaAdresowa.edytujAdresata();
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
