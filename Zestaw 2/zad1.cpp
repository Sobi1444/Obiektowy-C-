// Polimorfizm dynamiczny - mechanizm umozliwiajacy wybor odpowiedniej
// implementacji funkcji wirtualnej w czasie wykonania programu (runtime).
// Realizowany poprzez wskazniki lub referencje do klasy bazowej
// oraz funkcje wirtualne (virtual).

// Polimorfizm statyczny - mechanizm umozliwiajacy wybor odpowiedniej
// implementacji w czasie kompilacji (compile time).
// Realizowany poprzez szablony (templates) oraz przeciazanie funkcji.

// Klasa abstrakcyjna - klasa zawierajaca co najmniej jedna czysto wirtualna
// funkcje (pure virtual function, np. virtual void f() = 0).
// NIE MOZNA tworzyc obiektow klasy abstrakcyjnej, sluzy tylko jako
// interfejs dla klas pochodnych.

// Funkcja wirtualna - funkcja skladowa klasy, ktorej wywolanie jest
// rozwiazywane w czasie wykonania programu na podstawie rzeczywistego
// typu obiektu, a nie typu wskaznika/referencji.
// Deklarowana za pomoca slowa kluczowego virtual.