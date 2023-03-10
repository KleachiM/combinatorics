#include <iostream>
#include <vector>
#include <boost/timer.hpp>

using namespace std;

int main()
{
    int n = 10, m;
    vector<size_t> pi(n + 2), p(n + 1), d(n + 1);

    for(int i = 1; i <= n; i++)
    {
        pi.at(i) = i;
        p.at(i) = i;
        d.at(i) = -1;
    }

    d.at(1) = 0;
    pi.at(0) = pi.at(n + 1) = m = n + 1;

    boost::timer t;
    t.restart();

    while (m != 1)
    {
//        for(int i = 1; i <= n; i++)
//        {
//            cout << pi.at(i) << " ";
//        }
//        cout << endl;

        m = n;

        while (pi.at(p.at(m) + d.at(m)) > m)
        {
            d.at(m) = -d.at(m);
            m -= 1;
        }
        swap(pi.at(p.at(m)), pi.at(p.at(m) + d.at(m)));
        swap(p.at(pi.at(p.at(m))), p.at(m));
    }

    double duration = t.elapsed();
    cout << "N = " << n << " duration: " << duration * 1000<< " ms" << endl;

    vector<size_t> sizes = {15, 20, 50, 100};
    size_t currSize = n;
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