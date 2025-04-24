#ifndef UCET_H
#define UCET_H

#include <string>
#include <vector>

class Ucet {
private:
    static constexpr double MAX_VYBER = 5000.0;
    int cisloUctu;
    std::string majitel;
    double zustatek;
    int pocetVkladu;
    int pocetVyberu;
    double soucetVkladu;
    double soucetVyberu;
    int maxOperaci;
    std::vector<double> historieVkladu;
    std::vector<double> historieVyberu;

public:
    Ucet(int cislo, const std::string& jmeno, int maxOp);
    bool vlozit(double castka);
    bool vybrat(double castka);
    void vypisDetailni() const;
    void vypisSouhrn() const;
    void ulozDoSouboru(const std::string& jmenoSouboru) const;
    static Ucet nacistZeSouboru(const std::string& jmenoSouboru);
};

#endif
