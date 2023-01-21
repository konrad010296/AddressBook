#include <iostream>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
struct Dane {
    string imie;
    string nazwisko;
    string nrTel;
    string adresEmail;
    string korespondecja;
    int numerIdUzytkownika;
};

string pobierzLinie() {
    string linia;
    cin.sync();
    getline(cin,linia);

    return linia;
}

int ostatniNrIdUzytkownika(vector <Dane> uzytkownicy) {
    vector <Dane> :: iterator it;
    int wynik = 0;

    for(it = uzytkownicy.begin() ; it != uzytkownicy.end() ; ++it)
        wynik = (*it).numerIdUzytkownika;

    return wynik;
}

void dodajUzytkownika(vector <Dane> &uzytkownicy) {

    system("CLS");
    Dane osoba;
    fstream plik;
    plik.open("adresacja.txt", ios::out | ios::app);

    cout << "Podaj imie nowego Uzytkownika : " << endl;
    osoba.imie = pobierzLinie();

    cout << "Podaj nazwisko nowego Uzytkownika : " << endl;
    osoba.nazwisko = pobierzLinie();

    cout << "Podaj nr Tel nowego Uzytkownika : " << endl;
    osoba.nrTel = pobierzLinie();

    cout << "Podaj adres Email nowego Uzytkownika : " << endl;
    osoba.adresEmail = pobierzLinie();

    cout << "Podaj adres zamieszkania nowego Uzytkownika : " << endl;
    osoba.korespondecja = pobierzLinie();

    osoba.numerIdUzytkownika = ostatniNrIdUzytkownika(uzytkownicy) + 1;

    plik << osoba.numerIdUzytkownika << "|" ;
    plik << osoba.imie << "|" ;
    plik << osoba.nazwisko << "|" ;
    plik << osoba.nrTel << "|" ;
    plik << osoba.adresEmail << "|" ;
    plik << osoba.korespondecja << "|" << endl;
    plik.close();

    uzytkownicy.push_back(osoba);
    cout << "Uzytkownik zostal dodany pomyslnie !" << endl;
    Sleep(1500);

}

void wyswietlWszystkichUzytkownikow(vector <Dane> uzytkownicy) {

    system("CLS");
    vector <Dane> :: iterator it;

    if(uzytkownicy.begin() < uzytkownicy.end()) {
        for( it = uzytkownicy.begin() ; it != uzytkownicy.end() ; ++it) {
            cout << endl;

            cout << "Id: " << (*it).numerIdUzytkownika << endl;
            cout << "Imie: " << (*it).imie << endl;
            cout << "Nazwisko: " << (*it).nazwisko << endl;
            cout << "Nr Tel: " << (*it).nrTel << endl;
            cout << "Adres Email: " << (*it).adresEmail << endl;
            cout << "Adres Zam: " << (*it).korespondecja << endl;
        }
        cout << endl;
    } else
        cout << "Brak uzytkownikow w ksiazce adresowej !!" << endl;
    system("PAUSE");
}

void wyszukajUzytkownikaPoImieniu(vector <Dane> uzytkownicy) {

    system("CLS");
    string szukaneImie;
    vector <Dane> :: iterator it;
    bool wystapienieDanej = false;

    cout << "Podaj Imie ktore chcesz wyszukac :" << endl;
    cin >> szukaneImie;
    system("CLS");

    for( it = uzytkownicy.begin() ; it != uzytkownicy.end() ; ++it) {

        if((*it).imie == szukaneImie) {
            wystapienieDanej = true;
            cout << "Id: " << (*it).numerIdUzytkownika << endl;
            cout << "Imie: " << (*it).imie << endl;
            cout << "Nazwisko: " << (*it).nazwisko << endl;
            cout << "Nr Tel: " << (*it).nrTel << endl;
            cout << "Adres Email: " << (*it).adresEmail << endl;
            cout << "Adres Zam: " << (*it).korespondecja << endl;
            cout << endl;
        }
    }
    if(wystapienieDanej == false) {
        system("CLS");
        cout << "Niestety nie ma uzytkownika o takim imieniu !!" << endl;
    }

    system("PAUSE");
}

void wyszukajUzytkownikaPoNazwisku(vector <Dane> uzytkownicy) {

    system("CLS");
    string szukaneNazwisko;
    vector <Dane> :: iterator it;
    bool wystapienieDanej = false;

    cout << "Podaj Nazwisko ktore chcesz wyszukac :" << endl;
    cin >> szukaneNazwisko;
    system("CLS");

    for( it = uzytkownicy.begin() ; it != uzytkownicy.end() ; ++it) {

        if((*it).nazwisko == szukaneNazwisko) {
            wystapienieDanej = true;
            cout << "Id: " << (*it).numerIdUzytkownika << endl;
            cout << "Imie: " << (*it).imie << endl;
            cout << "Nazwisko: " << (*it).nazwisko << endl;
            cout << "Nr Tel: " << (*it).nrTel << endl;
            cout << "Adres Email: " << (*it).adresEmail << endl;
            cout << "Adres Zam: " << (*it).korespondecja << endl;
            cout << endl;
        }
    }
    if(wystapienieDanej == false) {
        system("CLS");
        cout << "Niestety nie ma uzytkownika o takim nazwisku !!" << endl;
    }

    system("PAUSE");
}

void zaladowaniePlikuTekstowego(vector <Dane> &uzytkownicy) {

    Dane osoba;
    int nr_linii = 1;
    string linia;
    string zmiennaPomocnicza = "";
    fstream plik;

    plik.open("adresacja.txt", ios::in);
    if(plik.good() == false) {
        cout << "Plik nie istnieje !!" << endl;
        system("PAUSE");
    } else {
        while(getline(plik,linia)) {
            for (unsigned int i = 0 ; i < linia.length(); i++) {

                if (linia[i] != '|')
                    zmiennaPomocnicza += linia[i];

                else {
                    switch(nr_linii) {
                    case 1:
                        osoba.numerIdUzytkownika = atoi(zmiennaPomocnicza.c_str());
                        break;
                    case 2:
                        osoba.imie = zmiennaPomocnicza;
                        break;
                    case 3:
                        osoba.nazwisko = zmiennaPomocnicza;
                        break;
                    case 4:
                        osoba.nrTel = zmiennaPomocnicza;
                        break;
                    case 5:
                        osoba.adresEmail = zmiennaPomocnicza;
                        break;
                    case 6:
                        osoba.korespondecja = zmiennaPomocnicza;
                        break;
                    }
                    zmiennaPomocnicza = "";
                    nr_linii++;
                }
                if(nr_linii == 7) {
                    nr_linii = 1;
                }
            }
            uzytkownicy.push_back(osoba);
        }
    }
    plik.close();
}
bool czyUsunacUzytkownika() {

    bool potwierdzenie = false;
    string wybor;

    cout << "Czy na pewno usunac uzytkownika? y/n" << endl;

    cin >> wybor;
    system("CLS");

    if(wybor == "y") {
        potwierdzenie = true;
        cout << "Uzytkownik zostal usuniety !" << endl;
    } else if (wybor == "n") {
        potwierdzenie = false;
        cout << "Uzytkownik nie zostal usuniety !" << endl;
    }

    return potwierdzenie;
}

void dodanieVektoraDoPliku(vector <Dane> &uzytkownicy) {
    fstream plik;
    vector <Dane> :: iterator it;
    plik.open("adresacja.txt", ios::out | ios::app);

    for(it = uzytkownicy.begin() ; it != uzytkownicy.end() ; ++it) {
        plik << (*it).numerIdUzytkownika << "|" << (*it).imie << "|" << (*it).nazwisko << "|" << (*it).nrTel << "|" << (*it).adresEmail << "|" << (*it).korespondecja << "|" << endl;

    }
    plik.close();
}

void usunUzytkownika(vector <Dane> &uzytkownicy) {

    vector <Dane> :: iterator it;
    int szukaneId;
    bool wystapienieDanej = false;

    system("CLS");
    cout << "Podaj numer ID uzytkownika ktorego chcesz usunac : " << endl;
    cin >> szukaneId;

    for( it = uzytkownicy.begin() ; it < uzytkownicy.end() ; ++it) {

        if((*it).numerIdUzytkownika == szukaneId) {

            wystapienieDanej = true;
            cout << "Id: " << (*it).numerIdUzytkownika << endl;
            cout << "Imie: " << (*it).imie << endl;
            cout << "Nazwisko: " << (*it).nazwisko << endl;
            cout << "Nr Tel: " << (*it).nrTel << endl;
            cout << "Adres Email: " << (*it).adresEmail << endl;
            cout << "Adres Zam: " << (*it).korespondecja << endl;
            cout << endl;
            if (czyUsunacUzytkownika() == true)
                uzytkownicy.erase(it);

            remove("adresacja.txt");
            dodanieVektoraDoPliku(uzytkownicy);
        }
    }
    if(wystapienieDanej == false) {
        system("CLS");
        cout << "Podany numer ID nie istnieje!!" << endl;
    }
    system("PAUSE");
}

void edytujUzytkownika(vector <Dane> &uzytkownicy) {
    char wybor;
    int id;
    bool wystapienieDanej = false;
    vector <Dane> :: iterator it;

    system("CLS");

    cout << "Podaj nr ID uzytkownika ktorego chcesz edytowac : " << endl;
    cin >>id;

    for( it = uzytkownicy.begin() ; it != uzytkownicy.end() ; ++it) {

        if((*it).numerIdUzytkownika  == id) {

            wystapienieDanej = true;
            cout << "Id: " << (*it).numerIdUzytkownika << endl;
            cout << "Imie: " << (*it).imie << endl;
            cout << "Nazwisko: " << (*it).nazwisko << endl;
            cout << "Nr Tel: " << (*it).nrTel << endl;
            cout << "Adres Email: " << (*it).adresEmail << endl;
            cout << "Adres Zam: " << (*it).korespondecja << endl;
            cout << endl;

            cout << "Ktory wariant chcialbys edytowac? " << endl;

            cout << " 1 - Imie" << endl;
            cout << " 2 - Nazwisko" << endl;
            cout << " 3 - Nr Tel" << endl;
            cout << " 4 - Adres Email" << endl;
            cout << " 5 - Adres Zam" << endl;

            wybor = getch();
            system("CLS");

            if(wybor < '6' ) {
                switch(wybor) {
                case '1' :
                    cout << "Podaj Imie:" << endl;
                    (*it).imie = pobierzLinie();
                    break;
                case '2' :
                    cout << "Podaj Nazwisko:" << endl;
                    (*it).nazwisko = pobierzLinie();
                    break;
                case '3' :
                    cout << "Podaj Nr Tel:" << endl;
                    (*it).nrTel = pobierzLinie();
                    break;
                case '4' :
                    cout << "Podaj Adres Email:" << endl;
                    (*it).adresEmail = pobierzLinie();
                    break;
                case '5' :
                    cout << "Podaj Adres Zamieszkania:" << endl;
                    (*it).korespondecja = pobierzLinie();
                    break;
                }
                remove("adresacja.txt");
                dodanieVektoraDoPliku(uzytkownicy);
                system("CLS");
                cout << "Dane zostaly poprawnie zmienione !!" << endl;
            } else
                cout << "Nie ma takiej opcji !!" << endl;
        }
    }
    if(wystapienieDanej == false) {
        system("CLS");
        cout << "Podany numer ID nie istnieje!!" << endl;
    }
    system("PAUSE");
}



int main() {
    Dane osoba;
    vector <Dane> uzytkownicy;
    char wyborOpcji;

    zaladowaniePlikuTekstowego(uzytkownicy);

    do {
        system("CLS");
        cout << "Witaj w ksiazce Adresowej !" << endl;

        cout << "1 - Dodaj nowego Uzytkownika" << endl;
        cout << "2 - Wyszukaj po Imieniu" << endl;
        cout << "3 - Wyszukaj po Nazwisku" << endl;
        cout << "4 - Wyswietl wszystkie osoby" << endl;
        cout << "5 - Usun adresata" << endl;
        cout << "6 - Edytuj adresata" << endl;
        cout << "9 - Opusc program" << endl;

        wyborOpcji = getch();

        switch(wyborOpcji) {
        case '1' :
            dodajUzytkownika(uzytkownicy);
            break;
        case '2' :
            wyszukajUzytkownikaPoImieniu(uzytkownicy);
            break;
        case '3' :
            wyszukajUzytkownikaPoNazwisku(uzytkownicy);
            break;
        case '4' :
            wyswietlWszystkichUzytkownikow(uzytkownicy);
            break;
        case '5' :
            usunUzytkownika(uzytkownicy);
            break;
        case '6' :
            edytujUzytkownika(uzytkownicy);
            break;
        case '9' :
            exit(0);
            break;
        }
    } while(wyborOpcji != '9');
    return 0;
}

