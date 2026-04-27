#include <iostream>
#include <stdexcept>
#include <string>
#include <map>

struct Color
{
    int r, g, b;
    Color(int r, int g, int b) : r(r), g(g), b(b) {}
};

// rzuca wyjatkiem gdy kolor nieznany
struct ThrowOnUnknown
{
    static Color handle_unknown(const std::string &name)
    {
        throw std::runtime_error("nieznany kolor: " + name);
    }
};

// zwraca ustalony kolor domyslny zamiast wyjatku
template <int R = 0, int G = 0, int B = 0>
struct DefaultColorOnUnknown
{
    static Color handle_unknown(const std::string & /*name*/)
    {
        return Color(R, G, B);
    }
};

template <typename UnknownPolicy = ThrowOnUnknown>
class ColorFactory
{
    std::map<std::string, Color> _colors;

public:
    ColorFactory()
    {
        _colors.insert({"czarny", Color(0, 0, 0)});
        _colors.insert({"bialy", Color(255, 255, 255)});
        _colors.insert({"czerwony", Color(255, 0, 0)});
        _colors.insert({"zielony", Color(0, 255, 0)});
        _colors.insert({"niebieski", Color(0, 0, 255)});
    }

    Color get(const std::string &name)
    {
        auto it = _colors.find(name);
        if (it != _colors.end())
            return it->second;
        return UnknownPolicy::handle_unknown(name);
    }
};

int main()
{
    // domyslna wytyczna - rzuca wyjatkiem
    ColorFactory<> f1;

    Color c = f1.get("zielony");
    std::cout << "zielony: " << c.r << " " << c.g << " " << c.b << std::endl;

    try
    {
        f1.get("fioletowy");
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "wyjatek: " << e.what() << std::endl;
    }

    // zwraca szary dla nieznanych
    ColorFactory<DefaultColorOnUnknown<128, 128, 128>> f2;

    Color c2 = f2.get("fioletowy");
    std::cout << "fioletowy (domyslny szary): " << c2.r << " " << c2.g << " " << c2.b << std::endl;

    return 0;
}
