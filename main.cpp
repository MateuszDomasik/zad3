/*Zadanie 3./ Wczytaj z pliku liczby, sprawdŸ,
czy nale¿¹ do ci¹gu fibonacciego,
je¿eli dana liczba nale¿y  zapisz do innego pliku tekstowego TAK,
je¿eli nie nale¿y to NIE,
 nastêpnie wczytaj ten plik i policz ile jest s³ów TAK, a ile NIE*/
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int ciag_fibonacciego(int n)
{
    if(n<3) return 1;
    else return ciag_fibonacciego(n-2) + ciag_fibonacciego(n-1);
}

int main()
{
    fstream plik, plik2;
    string linia;
    int nr_lini=1, liczba_wczytana[11], liczby_fib[100], a=1, czy_nalezy[11], zlicz_tak=0, zlicz_nie=0;;

    plik.open ("liczby.txt", ios::in);

    while(getline(plik, linia))
    {
        liczba_wczytana[nr_lini-1] = atoi(linia.c_str());
        nr_lini++;
    }

    plik.close();

    for(int i=0; i<nr_lini;i++)
    {
        for(;;)
        {
            if(liczba_wczytana[i]==ciag_fibonacciego(a))
            {
                cout << "Liczba: " << liczba_wczytana[i] << " Nalezy do ciagu Fibbonaciego." << endl;
                liczba_wczytana[i]=czy_nalezy[i]=1;
                break;
            }

            else
            {
                if(liczba_wczytana[i]<ciag_fibonacciego(a)) break;
                else a++;
            }
        }
    }

    plik2.open("Zad3.txt", ios::out | ios::app);

    for(int i=0; i<nr_lini; i++)
    {
        if(czy_nalezy[i]==1)
        {
            plik2 << "TAK" << endl;
            zlicz_tak++;
        }
        else
        {
            plik2 << "nie" << endl;
            zlicz_nie++;
        }
    }

    plik2.close();

    cout << "Wystapilo: " << zlicz_tak << " Odpowiedzi TAK." << endl;
    cout << "Wystapilo: " << zlicz_nie << " Odpowiedzi NIE." << endl;



    return 0;
}
