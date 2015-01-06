/*  Wprowadzenie danych.
Login:
Has³o:
Poka¿, ¿e nie jesteœ robotem: (przepisz tekst) -
Do zrobienia:
wprowadzenie danych (funkcja, 2 argumenty string)
anty robot: funkcja losuj¹ca znaki, lub liczby (dajmy na to 6 znaków)  */
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

struct TUczen
{
    int Nr_z_dziennika;
    char Imie[20];
    char Nazwisko[20];
    struct
    {
        int Rok;
        unsigned short Miesiac;
        unsigned short Dzien;
    }Data_urodzin;
    struct
    {
        int Rocznik;
        char Grupa;
    }Klasa;
    int Oceny;

};
struct TUczen Uczen;

struct TWylosowane
{
    int cyfry_losowane[6];
    char litera[6];

};
struct TWylosowane Wylosowane;

void kod_losowany()
{
    int ile_cyfr, ile_liter, liczba_litera, licznik_cyfr=0, licznik_liter=0;
    int litery_losowane[6];

    srand(time(NULL));

    ile_cyfr=rand()%7; //ile cyfr bedzie w kodzie
    ile_liter=6-ile_cyfr;

    for(int i=0; i<ile_cyfr; i++) //losuje liczby
    {
        Wylosowane.cyfry_losowane[i]=rand()% 10;
    }

    for(int i=0; i<ile_liter; i++) //losuje litery
    {
        litery_losowane[i]=rand()% 25+98;
    }

    for(int i=0; i<30; i++)
    {
        liczba_litera=rand()% 2;
        if(liczba_litera==1)
        {
            if(ile_cyfr>licznik_cyfr)
            {
                cout << Wylosowane.cyfry_losowane[licznik_cyfr];
                licznik_cyfr++;
            }
        }
        else
        {
            if(ile_liter>licznik_liter)
            {
                Wylosowane.litera[licznik_liter] = litery_losowane[licznik_liter];
                cout << Wylosowane.litera[licznik_liter];
                licznik_liter++;
            }
        }
    }
}

void wprowadzanie_danych()
{
    string kod_wpisany, login, haslo;
    int poprawnosc=0, a=0, b=0;
    cout << "Wpisz login: ";
    cin >> login;
    cout << "Wpisz haslo: ";
    cin >> haslo;
    cout << "Przepisz podany kod: ";
    kod_losowany();
    cout << " Tutaj -> ";
    cin >> kod_wpisany;
    if(kod_wpisany==Wylosowane) cout << "Udalo sie!";

    for(int i=0; i<6; i++)
    {
        //cout << litera[a];
        if(kod_wpisany[i]==Wylosowane.litera[a])
        {
            cout << Wylosowane.litera[a];
            poprawnosc++;
            a++;
        }
        if(kod_wpisany[i]== Wylosowane.cyfry_losowane[b])
        {
            cout << Wylosowane.cyfry_losowane[b];
            poprawnosc++;
            b++;
        }
    //cout << poprawnosc << endl;
    }
    if(poprawnosc==6) cout << "Kod poprawny" << endl;
        else{ cout << "Kod przepisany blednie!" << endl;}
}

int main()
{
    wprowadzanie_danych();
    return 0;
}
