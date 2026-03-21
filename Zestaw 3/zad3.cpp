#include <iostream>

// szkielet
template <typename T, int N = 100>
class Stack
{
public:
    void info() { std::cout << "Stack podstawowy" << std::endl; }
};

// specka czesciowa
template <typename T>
class Stack<T, 666>
{
public:
    void info() { std::cout << "Stack<T,666>" << std::endl; }
};

// specjalizacja czesciowa dla wskaznikow
template <typename T, int N>
class Stack<T *, N>
{
public:
    void info() { std::cout << "Stack<T*,N>" << std::endl; }
};

// specjalizacja czesciowa dla double
template <int N>
class Stack<double, N>
{
public:
    void info() { std::cout << "Stack<double,N>" << std::endl; }
};

// specka czesciowa dla int*
template <int N>
class Stack<int *, N>
{
public:
    void info() { std::cout << "Stack<int*,N>" << std::endl; }
};

// specka pelna dla double
template <>
class Stack<double, 666>
{
public:
    void info() { std::cout << "Stack<double,666>" << std::endl; }
};

// specka pelna dla double*
template <>
class Stack<double *, 44>
{
public:
    void info() { std::cout << "Stack<double*,44>" << std::endl; }
};

int main()
{
    Stack<int, 100> s1;
    s1.info();
    Stack<int, 666> s2;
    s2.info();
    Stack<int *, 10> s3;
    s3.info();
    Stack<double, 10> s4;
    s4.info();
    Stack<int *, 10> s5;
    s5.info();
    Stack<double, 666> s6;
    s6.info();
    Stack<double *, 44> s7;
    s7.info();

    return 0;
}