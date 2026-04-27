#include <iostream>
#include <stdexcept>
#include <cstdlib>

// brak sprawdzania, kompilator wyoptymalizuje puste funkcje
struct No_checking_policy
{
    static void check_push(size_t, size_t) {}
    static void check_pop(size_t) {}
    static void check_top(size_t) {}
};

// abort przy bledzie
struct Abort_on_error_policy
{
    static void check_push(size_t top, size_t size)
    {
        if (top >= size)
        {
            std::cerr << "blad: proba wlozenia na pelny stos, przerywanie" << std::endl;
            abort();
        }
    }
    static void check_pop(size_t top)
    {
        if (top == 0)
        {
            std::cerr << "blad: proba zdjecia z pustego stosu, przerywanie" << std::endl;
            abort();
        }
    }
    static void check_top(size_t top)
    {
        if (top == 0)
        {
            std::cerr << "blad: proba odczytu z pustego stosu, przerywanie" << std::endl;
            abort();
        }
    }
};

template <typename T = int, size_t N = 100,
          typename Checking_policy = No_checking_policy>
class Stack
{
private:
    T _rep[N];
    size_t _top;

public:
    Stack() : _top(0) {}

    void push(const T &val)
    {
        Checking_policy::check_push(_top, N);
        _rep[_top++] = val;
    }

    void pop()
    {
        Checking_policy::check_pop(_top);
        --_top;
    }

    // top i pop sa rozdzielone
    const T &top() const
    {
        Checking_policy::check_top(_top);
        return _rep[_top - 1];
    }

    bool is_empty() const
    {
        return _top == 0;
    }
};

int main()
{
    // stos bez sprawdzania
    Stack<int, 10> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    std::cout << "top (no check): " << s1.top() << std::endl;
    s1.pop();
    std::cout << "top po pop: " << s1.top() << std::endl;

    // stos z abort
    Stack<double, 5, Abort_on_error_policy> s2;
    s2.push(3.14);
    s2.push(2.71);
    std::cout << "top (abort policy): " << s2.top() << std::endl;

    // ponizsze spowoduje abort()
    // Stack<int, 5, Abort_on_error_policy> s3;
    // s3.pop();

    return 0;
}
