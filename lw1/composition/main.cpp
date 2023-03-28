#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

vector<int> GetVector(const int count)
{
    vector<int> vec;
    if (count < 1) return vec;
    vec[0] = -1;
    for (int i = 1; i < count + 1; i++)
    {
        vec[i] = i;
    }
    return vec;
}

int main()
{
   /* int n;
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
            if (n - 1 == accumulate(v.begin(), v.end(), 0))
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
   int n = 3,k = 2;
   vector<int> v(k + 1);
   for(int i = 0; i < k + 1; i++)
   {
       v[i] = i;
   }
   while(v[k] != 1)
   {
       copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
       cout << endl;
       int i = 0;
       while (v[i] == n - 1)
       {
           v[i] = 0;
           i++;
       }
       v[i]++;
   }
}