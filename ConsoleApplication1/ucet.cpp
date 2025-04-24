#include "ucet.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

Ucet::Ucet(int cislo, const std::string& jmeno, int maxOp)
    : cisloUctu(cislo), majitel(jmeno), zustatek(0), pocetVkladu(0),
    pocetVyberu(0), soucetVkladu(0), soucetVyberu(0), maxOperaci(maxOp) {
}

bool Ucet::vlozit(double castka) {
    if (castka <= 0 || castka > 1000000) return false;
    if (pocetVkladu >= maxOperaci) return false;
    zustatek += castka;
    soucetVkladu += castka;
    historieVkladu.push_back(castka);
    ++pocetVkladu;
    return true;
}

bool Ucet::vybrat(double castka) {
    if (castka <= 0 || castka > MAX_VYBER || castka > zustatek) return false;
    if (pocetVyberu >= maxOperaci) return false;
    zustatek -= castka;
    soucetVyberu += castka;
    historieVyberu.push_back(castka);
    ++pocetVyberu;
    return true;
}

void Ucet::vypisDetailni() const {
    std::cout << "\n--- Detailn� v�pis ��tu ---\n";
    std::cout << "��slo ��tu: " << cisloUctu << "\n";
    std::cout << "Majitel: " << majitel << "\n";
    std::cout << "Z�statek: " << std::fixed << std::setprecision(2) << zustatek << " K�\n";
    std::cout << "Po�et vklad�: " << pocetVkladu << ", v�b�r�: " << pocetVyberu << "\n";
    std::cout << "Sou�et vklad�: " << soucetVkladu << " K�, v�b�r�: " << soucetVyberu << " K�\n";
    std::cout << "Historie vklad�: ";
    for (double v : historieVkladu) std::cout << v << "; ";
    std::cout << "\nHistorie v�b�r�: ";
    for (double v : historieVyberu) std::cout << v << "; ";
    std::cout << "\n";
}

void Ucet::vypisSouhrn() const {
    std::cout << "��et: " << cisloUctu << ", Majitel: " << majitel
        << ", Z�statek: " << std::fixed << std::setprecision(2) << zustatek
        << ", Vklady: " << pocetVkladu << ", V�b�ry: " << pocetVyberu
        << ", Vlo�eno: " << soucetVkladu << ", Vybr�no: " << soucetVyberu << "\n";
}

void Ucet::ulozDoSouboru(const std::string& jmenoSouboru) const {
    std::ofstream out(jmenoSouboru);
    out << cisloUctu << "\n" << majitel << "\n" << zustatek << "\n"
        << pocetVkladu << "\n" << pocetVyberu << "\n" << soucetVkladu << "\n"
        << soucetVyberu << "\n" << maxOperaci << "\n";

    for (double v : historieVkladu) out << v << ";";
    out << "\n";
    for (double v : historieVyberu) out << v << ";";
    out << "\n";
}

Ucet Ucet::nacistZeSouboru(const std::string& jmenoSouboru) {
    std::ifstream in(jmenoSouboru);
    int cislo, pocVkl, pocVyb, maxOp;
    std::string jmeno, radek;
    double zust, soucetVkl, soucetVyb;

    std::getline(in, radek); cislo = std::stoi(radek);
    std::getline(in, jmeno);
    std::getline(in, radek); zust = std::stod(radek);
    std::getline(in, radek); pocVkl = std::stoi(radek);
    std::getline(in, radek); pocVyb = std::stoi(radek);
    std::getline(in, radek); soucetVkl = std::stod(radek);
    std::getline(in, radek); soucetVyb = std::stod(radek);
    std::getline(in, radek); maxOp = std::stoi(radek);

    Ucet ucet(cislo, jmeno, maxOp);
    ucet.zustatek = zust;
    ucet.pocetVkladu = pocVkl;
    ucet.pocetVyberu = pocVyb;
    ucet.soucetVkladu = soucetVkl;
    ucet.soucetVyberu = soucetVyb;

    std::getline(in, radek);
    std::stringstream ss1(radek);
    std::string hodnota;
    while (std::getline(ss1, hodnota, ';')) {
        if (!hodnota.empty()) ucet.historieVkladu.push_back(std::stod(hodnota));
    }

    std::getline(in, radek);
    std::stringstream ss2(radek);
    while (std::getline(ss2, hodnota, ';')) {
        if (!hodnota.empty()) ucet.historieVyberu.push_back(std::stod(hodnota));
    }

    return ucet;
}
