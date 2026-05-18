#include <iostream>
#include <memory>
#include <vector>
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

// szablon funkcji SongFactory - zwraca unique_ptr<T>
template <typename T>
std::unique_ptr<T> SongFactory(const std::wstring &artist, const std::wstring &title)
{
    return std::make_unique<T>(artist, title);
}

int main()
{
    auto song = SongFactory<Song>(L"Michael Jackson", L"Billie Jean");
    std::wcout << L"Utworzono: " << song->artist << L" - " << song->title << L"\n";

    // wypelnienie wektora unique_ptr<Song>
    std::vector<std::unique_ptr<Song>> songs;
    songs.push_back(SongFactory<Song>(L"B'z", L"Juice"));
    songs.push_back(SongFactory<Song>(L"Namie Amuro", L"Funky Town"));
    songs.push_back(SongFactory<Song>(L"Miki Matsubara", L"Mayonaka no Door (Stay With Me)"));

    std::wcout << L"\nLista utworow:\n";

    // petla musi byc po referencji unique ptr nie mozna kopiowac
    for (const auto &s : songs)
    {
        std::wcout << L"  " << s->artist << L" - " << s->title << L"\n";
    }

    // destruktory wywolaja sie automatycznie przy wyjsciu z main
    std::wcout << L"\n[koniec main - destruktory:]\n";

    return 0;
}