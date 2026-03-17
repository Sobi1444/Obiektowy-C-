#include <iostream>

// Polimorfizm dynamiczny
class Figura
{
public:
    virtual void rysuj() = 0; // =0 oznacza ze to czysta funkcja wirtualna - nie ma implementacji
    virtual ~Figura() {}      // wirtualny destruktor
};

class Kolo : public Figura
{
    double promien;

public:
    Kolo(double r) : promien(r) {} // inicjalizacja pola promien poprzez param r
    void rysuj() { std::cout << "Kolo o promieniu: " << promien << std::endl; }
};

class Prostokat : public Figura // prostokat dziedziczy po figura
{
    double a, b;

public:
    Prostokat(double bok_a, double bok_b) : a(bok_a), b(bok_b) {} // a(bok_a) - pole klasy a inicjalizowane wartoscia parametru
    void rysuj() { std::cout << "Prostokat " << a << "x" << b << std::endl; }
};

void rysuj_figury(Figura *tabela[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
        tabela[i]->rysuj(); // tabela to wskaznik (*) Figura, -> operator dostepu do metody rysuj
}

// Polimorfizm statyczny
template <typename T>
void rysuj_tablice(T tabela[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
        tabela[i].rysuj();
}

int main()
{
    // dynamiczny - przez wskaznik do klasy bazowej
    Figura *figury[3];
    figury[0] = new Kolo(5.0);
    figury[1] = new Prostokat(4.0, 6.0);
    figury[2] = new Kolo(3.0);
    rysuj_figury(figury, 3);
    for (size_t i = 0; i < 3; ++i)
        delete figury[i];

    // statyczny - przez szablon
    Kolo kola[2] = {Kolo(1.0), Kolo(2.0)};
    rysuj_tablice(kola, 2);

    return 0;
}