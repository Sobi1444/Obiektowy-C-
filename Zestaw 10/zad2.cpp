#include <vector>
#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <mutex>
#include <chrono>

int main()
{
    std::vector<int> vec(10'000'000);
    std::iota(vec.begin(), vec.end(), 0);

    std::vector<int> output;
    std::mutex mtx;

    auto t1 = std::chrono::high_resolution_clock::now();
    std::for_each(std::execution::par, vec.begin(), vec.end(),
                  [&output, &mtx](int &elem)
                  {
                      if (elem % 2 == 0)
                      {
                          std::lock_guard<std::mutex> lock(mtx);
                          output.push_back(elem);
                      }
                  });

    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "par: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " ms\n";
    std::cout << "rozmiar wektora wyjsciowego: " << output.size() << "\n";

    output.clear();
    auto t3 = std::chrono::high_resolution_clock::now();
    std::for_each(std::execution::seq, vec.begin(), vec.end(),
                  [&output](int &elem)
                  {
                      if (elem % 2 == 0)
                      {
                          output.push_back(elem);
                      }
                  });

    auto t4 = std::chrono::high_resolution_clock::now();
    std::cout << "seq: " << std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3).count() << " ms\n";
    std::cout << "rozmiar wektora wyjsciowego: " << output.size() << "\n";
    return 0;
}