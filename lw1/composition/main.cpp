#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

vector<int> GetVector(const int count)
{
    vector<int> vec(count);
    if (count < 1) return vec;
    vec[0] = -1;
    for (int i = 1; i < count + 1; i++)
    {
        vec[i] = i;
    }
    return vec;
}

/*
int main()
{
    int n;
    cout << "Введите целое положительное число больше 0" << endl;
    cin >> n;

    if (n == 1)
    {
        cout << "1 = 1" << endl;
    }

    for (int k = 1; k < n; k++)
    {
        vector<int> v = GetVector(k);
        int m = 1;
        while (m != 0)
        {
            if (n == accumulate(v.begin() + 1, v.end(), 0))
            {
                cout << n << " = ";
                copy(v.begin() + 1, v.end() - 1, ostream_iterator<int>(cout, " + "));
                copy(v.end() - 1, v.end(), ostream_iterator<int>(cout));
                cout << endl;
            }
            m = k;
            while (v[m] == n - k + m) m--;
            v[m]++;
            for(int i = m + 1; i < v.size(); i++)
            {
                v[i] = v[i - 1] + 1;
            }
        }
    }
  */
/* int n = 3,k = 3;
   vector<int> v(k);
   for(int i = 0; i < k; i++)
   {
       v[i] = 1;
   }
   while(v[k] != 1)
   {
       reverse_copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
       cout << endl;
       int i = 0;
       while (v[i] == n)
       {
           v[i] = 1;
           i++;
       }
       v[i]++;
   }*//*


}*/

vector<int> GetCompositions(const vector<int>& delimiters, int elemsCount, int delimitersCount)
{
    vector<int> compositionsVec(delimitersCount + 1);

    return vector<int>;
}

int main()
{
    int n = 5, k = 2;
    vector<int> v(k + 1);
    v[0] = 0;
    for(int i = 1; i < v.size(); i++)
    {
        v[i] = i;
    }

    int m = 1;
    while (m != 0)
    {
        vector<int> delimiters;
        copy(v.begin() + 1, v.end(), back_inserter(delimiters));
        vector<int> compositions = GetCompositions(delimiters, n, k);
        if (compositions.size() > 0)
        {
            copy(compositions.begin(), compositions.end(), ostream_iterator<int>(cout, " "));
            cout << endl;
        }
        m = k;
        while (v[m] == n - k + m) m--;
        v[m]++;
        for(int i = m + 1; i < v.size(); i++) v[i] = v[i - 1] + 1;
    }
}