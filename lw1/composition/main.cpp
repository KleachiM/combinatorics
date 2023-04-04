#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

void PrintComposition(const int number, const vector<int>& composition)
{
    cout << number << " = ";
    copy(composition.begin(), composition.end() - 1, ostream_iterator<int>(cout, " + "));
    copy(composition.end() - 1, composition.end(), ostream_iterator<int>(cout, "\n"));
}

vector<int> GetComposition(const vector<int>& delimiters, int elemsCount, int delimitersCount)
{
    vector<int> compositionsVec;
    if (delimitersCount == 0)
    {
        compositionsVec.push_back(elemsCount); // для случая 3 = 3
        return compositionsVec;
    }
    if (delimiters[delimitersCount - 1] > elemsCount - 2)
    {
        return compositionsVec;
    }
    for (int i = 0; i < delimitersCount; i++)
    {
        if (i == 0)
        {
            compositionsVec.push_back(delimiters[i]);
            continue;
        }
        int n = delimiters[i] - delimiters[i - 1] - 1;
        if (n > 0)
        {
            compositionsVec.push_back(n);
        }
        else
        {
            compositionsVec.clear();
            break;
        }
    }
    if (compositionsVec.size() > 0)
    {
        int lastN = elemsCount - delimiters[delimitersCount - 1] - 1;
        if (lastN > 0)
        {
            compositionsVec.push_back(lastN);
            return compositionsVec;
        }
        compositionsVec.clear();
    }
    return compositionsVec;
}

int main()
{
    cout << "Введите целое положительное число: ";
    int n;
    cin >> n;
    for (int k = 0; k < n; k++)
    {
        int elemsCount = n + k, delimitersCount = k;
        vector<int> v(delimitersCount + 1);
        v[0] = 0;
        for(int i = 1; i < v.size(); i++)
        {
            v[i] = i;
        }

        int m = 1;
        while (m != 0)
        {
            vector<int> delimitersPositions;
            copy(v.begin() + 1, v.end(), back_inserter(delimitersPositions));
            vector<int> composition = GetComposition(delimitersPositions, elemsCount, delimitersCount);
            if (composition.size() > 0)
            {
                PrintComposition(n, composition);
            }
            m = delimitersCount;
            while (v[m] == elemsCount - delimitersCount + m) m--;
            v[m]++;
            for(int i = m + 1; i < v.size(); i++) v[i] = v[i - 1] + 1;
        }
    }

}