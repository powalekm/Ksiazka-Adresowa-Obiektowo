#include "UzytkownikMenedzer.h"


void UzytkownikMenedzer::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zostalo zalozone pomyslnie!" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    do {
        cout << "Podaj login: ";
        uzytkownik.ustawLogin(MetodyPomocnicze::wczytajLinie());
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    uzytkownik.ustawHaslo(MetodyPomocnicze::wczytajLinie());

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login) {
    for(unsigned int i = 0; i <uzytkownicy.size(); i++) {
        if(uzytkownicy[i].pobierzLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow() {
    if (uzytkownicy.empty()) {
        cout << endl << "Brak uzytkownikow w systemie." << endl << endl;

    } else {
        for(unsigned int i = 0; i <uzytkownicy.size(); i++) {
            cout << uzytkownicy[i].pobierzId() << endl;
            cout << uzytkownicy[i].pobierzLogin() << endl;
            cout << uzytkownicy[i].pobierzHaslo() << endl;
        }
    }
}

void UzytkownikMenedzer::wczytajUzytkownikowZPliku() {
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

int UzytkownikMenedzer::logowanieUzytkownika() {
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    uzytkownik.ustawLogin(MetodyPomocnicze::wczytajLinie());

    unsigned int i = 0;
    while (i < uzytkownicy.size()) {
        if (MetodyPomocnicze::porownanieZnakow(uzytkownik.pobierzLogin(), uzytkownicy[i].pobierzLogin())) {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo: " << endl;
                uzytkownik.ustawHaslo(MetodyPomocnicze::wczytajLinie());

                if (uzytkownik.pobierzHaslo() == uzytkownicy[i].pobierzHaslo()) {
                    cout << "Uzytkownik zostal zalogowany pomyslnie." << endl;
                    system("pause");
                    return uzytkownicy[i].pobierzId();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        i++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UzytkownikMenedzer::ustawIdZalogowanegoUzytkownika(int noweId) {
    if (noweId >= 0) {
        idZalogowanegoUzytkownika = noweId;
    }
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika(int idZalogowanegoUzytkownika)
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (unsigned int i = 0; i < uzytkownicy.size(); i++){
        if (idZalogowanegoUzytkownika == uzytkownicy[i].pobierzId())
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
