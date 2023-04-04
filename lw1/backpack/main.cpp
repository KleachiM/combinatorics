#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Subject
{
    int weight;
    int price;
};


int GetPriceOfCurrentSet(vector<int> &currentSet, vector<Subject> &subjects, int maxWeight) {
    int currWeight = 0;
    int priceOfCurrSet = 0;
    for (const auto item: currentSet)
    {
        currWeight += subjects[item].weight;
        if (currWeight > maxWeight)
        {
            return 0;
        }
        priceOfCurrSet += subjects[item].price;
    }
    return priceOfCurrSet;
}

vector<int> GetTakenSubjects(vector<int> &currentSet, int subjectsSize) {
    vector<int> takenSubjects(subjectsSize, 0);
    for (const auto item: currentSet)
    {
        takenSubjects[item] = 1;
    }
    return takenSubjects;
}

int GetSettedWeight(const vector<Subject> &subjects, const vector<int> &takenSubjects) {
    int settedWeight = 0;
    for (auto const item: takenSubjects)
    {
        settedWeight += subjects[item].weight;
    }
    return settedWeight;
}

int main()
{
    ifstream inp("input.txt");
    if (inp.is_open())
    {
        string line;
        int rowsCount, maxWeight, minPrice;
        if (getline(inp, line))
        {
            istringstream strm(line);
            strm >> rowsCount >> maxWeight >> minPrice;
        }
        else
        {
            cout << "Невозможно прочитать из файла" << endl;
            return EXIT_FAILURE;
        }
        vector<Subject> subjects;
        while(getline(inp, line))
        {
            istringstream strm(line);
            Subject item;
            strm >> item.weight >> item.price;
            subjects.push_back(item);
        }
        int maxSettedPrice = 0;
        vector<int> takenSubjects(rowsCount, 0);
        for (int k = 1; k <= subjects.size(); k++)
        {
            vector<int> v;
            v.push_back(-1);
            for (int i = 1; i <= k; i++) v.push_back(i);
            int m = 1;
            while (m != 0)
            {
                vector<int> currentSet;
                copy(v.begin() + 1, v.end(), back_inserter(currentSet));
                int priceOfCurrSet = GetPriceOfCurrentSet(currentSet, subjects, maxWeight);
                if (priceOfCurrSet >= minPrice)
                {
                    maxSettedPrice = priceOfCurrSet;
                    takenSubjects = GetTakenSubjects(currentSet, subjects.size());
                }
                m = k;
                while (v[m] == subjects.size() - k + m) m--;
                v[m]++;
                for (int i = m + 1; i < v.size(); i++) v[i] = v[i - 1] + 1;
            }
        }
        int settedWeight = GetSettedWeight(subjects, takenSubjects);
        cout << "weight: " << settedWeight << endl;
        copy(takenSubjects.begin(), takenSubjects.end(), ostream_iterator<int>(cout, " "));
        return EXIT_SUCCESS;
    }
    cout << "Невозможно открыть файл" << endl;
    return EXIT_FAILURE;
}