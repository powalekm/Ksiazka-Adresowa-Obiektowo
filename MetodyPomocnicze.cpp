#include "MetodyPomocnicze.h"

string MetodyPomocnicze::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
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

char MetodyPomocnicze::wczytajZnak()
{
    string wejscie = "";
    char znak  = {0};
    while (true)
    {
        getline(cin, wejscie);
        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}
