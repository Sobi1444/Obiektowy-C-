// Zadanie 5 - shared_ptr wywoluje destruktor dopiero przy ostatnim wlascicielu

#include <iostream>
#include <memory>
#include <string>

struct Song
{
    std::wstring artist;
    std::wstring title;

    Song(const std::wstring &a, const std::wstring &t)
        : artist(a), title(t)
    {
        std::wcout << L"[konstruktor] " << artist << L" - " << title << L"\n";
    }

    ~Song()
    {
        std::wcout << L"[destruktor]  " << artist << L" - " << title << L"\n";
    }
};

int main()
{
    std::shared_ptr<Song> sp1;

    {
        // shared_ptr licznik ref = 1
        auto sp2 = std::make_shared<Song>(L"The Beatles", L"Let It Be");
        std::wcout << L"use_count po sp2:       " << sp2.use_count() << L"\n"; // 1

        // kopiowanie licznik ref = 2
        sp1 = sp2;
        std::wcout << L"use_count po sp1 = sp2: " << sp2.use_count() << L"\n"; // 2

        // sp2 wychodzi z zakresu, licznik spada do 1, destruktor niewywolany
        std::wcout << L"[koniec bloku - sp2 znika, sp1 nadal zyje]\n";
    }

    std::wcout << L"use_count sp1 po bloku: " << sp1.use_count() << L"\n"; // 1

    // sp1 wychodzi z zakresu na koncu main licznik = 0 destruktor wywolany
    std::wcout << L"[koniec main - destruktor:]\n";

    return 0;
}