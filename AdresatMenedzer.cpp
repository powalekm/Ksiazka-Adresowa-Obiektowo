#include "AdresatMenedzer.h"

void AdresatMenedzer::czyszczenieListyAdresatow() {
    adresaci.clear();
}


Adresat AdresatMenedzer::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (unsigned int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

void AdresatMenedzer::dodajAdresata() {
    Adresat adresat;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();
    adresaci.push_back(adresat);
    if(plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << endl << "Nowy adresat zostal dodany." << endl;
    else
        cout << endl << "Wystapil blad w trakcie dodatwania nowego adresata." << endl;
    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata() {
    Adresat adresat;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1);

    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    adresat.ustawImie(zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    adresat.ustawNazwisko(zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

string AdresatMenedzer::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst) {
    if (!tekst.empty()) {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow() {
    system("cls");
    if (!adresaci.empty()) {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------";
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            wyswietlDaneAdresata(*itr);
        }
        cout << "-----------------------------------------------";
        cout << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat) {
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku() {
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
}

void AdresatMenedzer::usunAdresata() {
    int idUsuwanegoAdresata = 0;
    bool czyIstniejeAdresat = false;
    char znak;

    system("cls");
    wyswietlWszystkichAdresatow();
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl;
    cout << "Podaj ID uzytkownka ktorego chcesz usunac: ";
    idUsuwanegoAdresata = MetodyPomocnicze::wczytajLiczbeCalkowita();

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
        if (itr -> pobierzId() == idUsuwanegoAdresata) {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't') {
                adresaci.erase(itr);
                plikZAdresatami.usunWybranaLinieWPliku(idUsuwanegoAdresata);
                cout << endl << "Wybrany adresat zostal prawidlowo usuniety." << endl << endl;
                break;
                system("pause");
            } else {
                cout << endl << "Wybrany adresat nie zostal usuniety." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej." << endl << endl;
        system("pause");
    }
}

void AdresatMenedzer::edytujAdresata() {
    int idEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";
    char wybor;
    Adresat edytowanyAdresat;
    bool czyIstniejeAdresat = false;

    system("cls");
    wyswietlWszystkichAdresatow();
    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl;
    cout << "Podaj ID uzytkownka ktorego chcesz edytowac: ";
    idEdytowanegoAdresata = MetodyPomocnicze::wczytajLiczbeCalkowita();

    for (unsigned int i = 0; i < adresaci.size(); i++) {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata) {
            czyIstniejeAdresat = true;

            wybor = wybierzOpcjeZMenuEdycja(i);
            switch (wybor) {
            case '1':
                cout << "Podaj nowe imie: ";
                adresaci[i].ustawImie(zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));
                edytowanyAdresat = adresaci[i];
                plikZAdresatami.edytujWybranaLinieWPliku(edytowanyAdresat);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko(zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));
                edytowanyAdresat = adresaci[i];
                plikZAdresatami.edytujWybranaLinieWPliku(edytowanyAdresat);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu(zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));
                edytowanyAdresat = adresaci[i];
                plikZAdresatami.edytujWybranaLinieWPliku(edytowanyAdresat);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail(zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));
                edytowanyAdresat = adresaci[i];
                plikZAdresatami.edytujWybranaLinieWPliku(edytowanyAdresat);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres(zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));
                edytowanyAdresat = adresaci[i];
                plikZAdresatami.edytujWybranaLinieWPliku(edytowanyAdresat);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

char AdresatMenedzer::wybierzOpcjeZMenuEdycja(int iteratorEdytowanegoAdresata){
    char wybor;
    system("cls");
    cout << ">>> MENU EDYCJA ADRESATA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1 - Imie:               " << adresaci[iteratorEdytowanegoAdresata].pobierzImie() << endl;
    cout << "2 - Nazwisko:           " << adresaci[iteratorEdytowanegoAdresata].pobierzNazwisko() << endl;
    cout << "3 - Numer telefonu:     " << adresaci[iteratorEdytowanegoAdresata].pobierzNumerTelefonu() << endl;
    cout << "4 - Email:              " << adresaci[iteratorEdytowanegoAdresata].pobierzEmail() << endl;
    cout << "5 - Adres:              " << adresaci[iteratorEdytowanegoAdresata].pobierzAdres() << endl << endl;
    cout << "6 - Powrot " << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane chcesz zaktualizowac: ";
    wybor = MetodyPomocnicze::wczytajZnak();
    return wybor;
}


void AdresatMenedzer::wyszukajAdresatowPoImieniu() {
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata) {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    } else    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku() {
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata) {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow) {
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}
