#include <algorithm>
#include <iostream>
#include <vector>
#include <boost/timer.hpp>

int main()
{
    std::vector<size_t> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    boost::timer t;
    t.restart();
    do
    {
    } while (std::next_permutation(v.begin(), v.end()));
    double duration = t.elapsed();

    std::cout << "N = " << v.size() << " duration: " << duration * 1000<< " ms\n";
    std::vector<size_t> sizes = { 15, 20, 50, 100};

    size_t currSize = v.size();
    for (size_t size : sizes)
    {
        for (size_t j = currSize + 1; j <= size; j++)
        {
            currSize *= j;
        }
        duration *= currSize;

        if (duration < 0.001) std::cout << "N = " << size << " duration is " << duration * 1000000 << " μs\n";
        else if (duration < 1) std::cout << "N = " << size << " duration is " << duration * 1000 << " ms\n";
        else if (duration < 60) std::cout << "N = " << size << " duration is " << duration << " s\n";
        else if (duration < 3600) std::cout << "N = " << size << " duration is " << duration / 60 << " m\n";
        else if (duration < 86400) std::cout << "N = " << size << " duration is " << duration / 3600 << " h\n";
        else if (duration < 2592000) std::cout << "N = " << size << " duration is " << duration / 86400 << " d\n";
        else if (duration < 31536000) std::cout << "N = " << size << " duration is " << duration / 2592000 << " month\n";
        else std::cout << "N = " << size << " duration is " << duration / 31536000 << " years\n";
    }
}