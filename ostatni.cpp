#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));

    int wygraneGracz = 0;
    int wygraneKomputer = 0;
    int remisy = 0;
    char kolejnaGra = 'T';



    while (kolejnaGra == 'T' || kolejnaGra == 't')

    {
        int talia[52] = {
          2,2,2,2,3,3,3,3,4,4,4,4,
          5,5,5,5,6,6,6,6,7,7,7,7,
          8,8,8,8,9,9,9,9,
          10,10,10,10,10,10,10,10,
          10,10,10,10,10,10,10,10,
          11,11,11,11
        };

        bool uzyta[52] = { false };
        int sumaGracz = 0;
        int sumaKomputer = 0;
        char decyzja;

        cout << "NOWA GRA" << endl;

        auto losujKarte = [&]() {
            int index;
            do {

                index = rand() % 52;

            } while (uzyta[index]);

            uzyta[index] = true;
            return talia[index];

            };
        cout << "Twoje poczatkowe karty:" << endl;
        for (int i = 0; i < 2; i++)

        {
            int karta = losujKarte();
            sumaGracz += karta;
            cout << "Karta " << i + 1 << ": " << karta << endl;
        }
        cout << "Suma gracza: " << sumaGracz << endl;
        while (sumaGracz <= 21)
        {
            cout << "Czy dobierasz kolejna karte? (T/N): ";
            cin >> decyzja;

            if (decyzja != 'T' && decyzja != 't')

                break;
            int karta = losujKarte();
            sumaGracz += karta;
            cout << "Wylosowana karta: " << karta << endl;
            cout << "Suma gracza: " << sumaGracz << endl;
        }
        if (sumaGracz > 21)
        {
            cout << "Przekroczyles 21! Przegrywasz." << endl;
            wygraneKomputer++;
        }
        else
        {
            cout << "Tura komputera" << endl;
            for (int i = 0; i < 3; i++)
            {
                int karta = losujKarte();
                sumaKomputer += karta;
            }
            cout << "Suma komputera: " << sumaKomputer << endl;
            if (sumaKomputer > 21 || sumaGracz > sumaKomputer)
            {
                cout << "Wygrales!" << endl;
                wygraneGracz++;
            }
            else if (sumaKomputer > sumaGracz)
            {
                cout << "Wygral komputer." << endl;
                wygraneKomputer++;
            }
            else
            {
                cout << "Remis." << endl;
                remisy++;
            }
        }
        cout << "Czy chcesz zagrac ponownie? (T/N): ";
        cin >> kolejnaGra;
    }
    cout << "STATYSTYKI" << endl;
    cout << "Wygrane gracza: " << wygraneGracz << endl;
    cout << "Wygrane komputera: " << wygraneKomputer << endl;
    cout << "Remisy: " << remisy << endl;
    cout << "Liczba gier: "
        << wygraneGracz + wygraneKomputer + remisy << endl;
    return 0;

}