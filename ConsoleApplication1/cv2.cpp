#include "ucet.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    locale::global(locale("czech"));
    Ucet ucet = (argc > 1) ? Ucet::nacistZeSouboru(argv[1]) : [&] {
        int cislo, maxOp;
        string jmeno;
        cout << "Zadej číslo účtu (100001–109999): "; cin >> cislo;
        cin.ignore();
        cout << "Zadej jméno majitele: "; getline(cin, jmeno);
        cout << "Zadej maximální počet operací: "; cin >> maxOp;
        return Ucet(cislo, jmeno, maxOp);
        }();

    int volba;
    do {
        cout << "\n--- Menu ---\n"
            << "1. Výpis detailního stavu účtu\n"
            << "2. Výpis souhrnu\n"
            << "3. Vklad\n"
            << "4. Výběr\n"
            << "0. Konec\n"
            << "Zadejte volbu: ";
        cin >> volba;

        double castka;
        switch (volba) {
        case 1: ucet.vypisDetailni(); break;
        case 2: ucet.vypisSouhrn(); break;
        case 3:
            cout << "Zadejte částku k vkladu: "; cin >> castka;
            cout << (ucet.vlozit(castka) ? "Vklad proběhl úspěšně." : "Vklad se nezdařil.") << "\n";
            break;
        case 4:
            cout << "Zadejte částku k výběru: "; cin >> castka;
            cout << (ucet.vybrat(castka) ? "Výběr proběhl úspěšně." : "Výběr se nezdařil.") << "\n";
            break;
        case 0:
            if (argc > 1) ucet.ulozDoSouboru(argv[1]);
            else {
                string soubor;
                cout << "Zadej jméno souboru pro uložení: ";
                cin >> soubor;
                ucet.ulozDoSouboru(soubor);
            }
            cout << "Program ukončen.\n";
            break;
        default:
            cout << "Neplatná volba!\n";
        }
    } while (volba != 0);

    return 0;
}
