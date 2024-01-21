#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zostalo zalozone pomyslnie!" << endl << endl;
    system("pause");
    system("cls");
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

void UzytkownikMenedzer::logowanieUzytkownika() {
    bool odnalezionyUzytkownik = false;
    Uzytkownik uzytkownik;
    string login = "", haslo = "";
    cout << endl << "Podaj login: " << endl;
    uzytkownik.ustawLogin(MetodyPomocnicze::wczytajLinie());

    unsigned int i = 0;
    while (i < uzytkownicy.size()) {
        if (MetodyPomocnicze::porownanieZnakow(uzytkownik.pobierzLogin(), uzytkownicy[i].pobierzLogin())) {
            odnalezionyUzytkownik = true;
            for (int iloscProb = 2; iloscProb >= 0; iloscProb--) {
                cout << "Podaj haslo: " << endl;
                uzytkownik.ustawHaslo(MetodyPomocnicze::wczytajLinie());
                if (uzytkownik.pobierzHaslo() == uzytkownicy[i].pobierzHaslo()) {
                    cout << "Uzytkownik zostal zalogowany pomyslnie." << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                    break;
                }
                cout << "Wprowadzone haslo jest nie prawidlowe. Pozostala liczba prob: " << iloscProb << endl;
                if ( iloscProb == 0) {
                    cout << "Nieprawidlowe logowanie." << endl;
                    system("pause");
                }
            }
        }
        i++;
    }
    if (odnalezionyUzytkownik == false) {
        cout << "Nie odnaleziono uzytkownika z podanym loginem." << endl << endl;
        system("pause");
    }
}

void UzytkownikMenedzer::ustawIdZalogowanegoUzytkownika(int noweId) {
    if (noweId >= 0) {
        idZalogowanegoUzytkownika = noweId;
    }
}

void UzytkownikMenedzer::wylogowanieUzytkownika() {
    idZalogowanegoUzytkownika = 0;
}

string UzytkownikMenedzer::pobierzLoginZalogowanegoUzytkownika() {
    unsigned int i = 0;
    while (i < uzytkownicy.size()) {
        if (idZalogowanegoUzytkownika == uzytkownicy[i].pobierzId()) {
            return uzytkownicy[i].pobierzLogin();
        }
        i++;
    }
    return 0;
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika() {
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (unsigned int i = 0; i < uzytkownicy.size(); i++) {
        if (idZalogowanegoUzytkownika == uzytkownicy[i].pobierzId()) {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

char UzytkownikMenedzer::wybierzOpcjeZMenuGlownego() {
    char wybor;
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();
    return wybor;
}

char UzytkownikMenedzer::wybierzOpcjeZMenuUzytkownika() {
    char wybor;
    system("cls");
    cout << "Zalogowany uzytkownik: " << pobierzLoginZalogowanegoUzytkownika() << endl;
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();
    return wybor;
}

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany() {
    if (idZalogowanegoUzytkownika > 0) {
        return true;
    } else {
        return false;
    }

}
