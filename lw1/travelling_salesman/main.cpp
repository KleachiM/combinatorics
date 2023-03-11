#include <iostream>
#include <vector>
#include <boost/timer.hpp>
#include <algorithm>
#include <random>
#include <cassert>

struct PRNG
{
    std::mt19937 engine;
};

void initGenerator(PRNG& generator)
{
    // Создаём псевдо-устройство для получения случайного зерна.
    std::random_device device;
    // Получаем случайное зерно последовательности
    generator.engine.seed(device());
}

// Генерирует целое число в диапазоне [minValue, maxValue)
unsigned random(PRNG& generator, unsigned minValue, unsigned maxValue)
{
    // Проверяем корректность аргументов
    assert(minValue < maxValue);

    // Создаём распределение
    std::uniform_int_distribution<unsigned> distribution(minValue, maxValue);

    // Вычисляем псевдослучайное число: вызовем распределение как функцию,
    //  передав генератор произвольных целых чисел как аргумент.
    return distribution(generator.engine);
}

using namespace std;

vector<vector<size_t>> initSquareMatrixWithRandomValues(const int dimension, const int maxRandomValue)
{
    PRNG generator;
    initGenerator(generator);

    vector<vector<size_t>> matrix(dimension, vector<size_t> (dimension, 0));
    for(int row = 0; row < dimension; row++)
    {
        for(int col = 0; col < dimension; col++)
        {
            if (row == col) matrix.at(row).at(col) = 0;
            else matrix.at(row).at(col) = random(generator, 1, maxRandomValue);
        }
    }

    return matrix;
}

struct TravSalesManSolution
{
    vector<size_t> points;
    int minDistance;
};

TravSalesManSolution getMinDistance(const vector<vector<size_t>>& matrix)
{
    TravSalesManSolution retStruct;
    int vertexCount = matrix.size();
    vector<size_t> points(vertexCount);
    for(int i = 0; i < vertexCount; i++) points.at(i) = i;
    int minDistance = INT_MAX;
    do
    {
        int currDistance = 0;
        for(int i = 1; i < points.size(); i++)
        {
            currDistance += matrix.at(points.at(i - 1)).at(points.at(i));
        }
        if (currDistance < minDistance)
        {
            minDistance = currDistance;
            retStruct.points = points;
            retStruct.minDistance = currDistance;
        }
    } while (next_permutation(points.begin(), points.end()));
    return retStruct;
}

void printMatrix(const vector<vector<size_t>>& matrix)
{
    cout << " \t\t";
    for(int i = 0; i < matrix.size(); i++)
    {
        cout.width(3);
        cout << i + 1 << " ";
    }
    cout << "\n\n";
    for(int row = 0; row < matrix.size(); row ++)
    {
        cout.width(3);
        cout << row + 1 << "\t\t";
        for(int col = 0; col < matrix.at(row).size(); col++)
        {
            cout.width(3);
            cout << matrix.at(row).at(col) << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n = 10;
    const int MAX_DISTANCE = 50;

    vector<vector<size_t>> squareMatrix = initSquareMatrixWithRandomValues(n, MAX_DISTANCE);

    boost::timer t;

    TravSalesManSolution solution = getMinDistance(squareMatrix);
    double duration = t.elapsed();


    cout << "Matrix: \n\n";
    printMatrix(squareMatrix);

    cout << "\nBest way: \n";
    for(int i = 0; i < squareMatrix.size(); i++)
        cout << solution.points.at(i) + 1 << " ";
    cout << "\n";

    cout << "Min distance = " << solution.minDistance << "\n";

    cout << "\nN = " << n << " duration = " << duration * 1000 << " ms\n";

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