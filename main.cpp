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

                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            }
        } else {

                    //Dodać PlikZAdresatami → czyAdresaciZostaliWczytani
                //ksiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika());
                //Przerzucic do logowanie uzytkownika
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();
            switch (wybor) {
            case '1':
                //Dodac AdresatManager
                //ksiazkaAdresowa.dodajAdresata(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika());
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
