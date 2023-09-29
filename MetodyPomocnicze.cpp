#include "MetodyPomocnicze.h"

string MetodyPomocnicze::wczytajLinie() {

    cin.clear();
    cin.sync();
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

string MetodyPomocnicze::konwerjsaIntNaString(int liczba) {
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

bool MetodyPomocnicze::porownanieZnakow(string pierwszyCiagZnakow, string drugiCiagZnakow) {
    if(pierwszyCiagZnakow.length() == drugiCiagZnakow.length()) {
        transform(pierwszyCiagZnakow.begin(), pierwszyCiagZnakow.end(), pierwszyCiagZnakow.begin(), ::tolower);
        transform(drugiCiagZnakow.begin(), drugiCiagZnakow.end(), drugiCiagZnakow.begin(), ::tolower);
        if (pierwszyCiagZnakow == drugiCiagZnakow) {
            return true;
        }
    }
    return false;
}

char MetodyPomocnicze::wczytajZnak() {

    cin.clear();
    cin.sync();
    string wejscie = "";
    char znak  = {0};
    while (true) {
        getline(cin, wejscie);
        if (wejscie.length() == 1) {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}


string MetodyPomocnicze::pobierzLiczbe(string tekst, int pozycjaZnaku) {

    cin.clear();
    cin.sync();
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true) {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}


int MetodyPomocnicze::konwersjaStringNaInt(string liczba) {
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}
