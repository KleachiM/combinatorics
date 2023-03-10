#include <iostream>
#include <vector>
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

int main()
{
    PRNG generator;
    initGenerator(generator);

    int n = 10;
    std::vector<size_t> v(n);

    std::cout << "Input vector: \t";
    for(int i = 0; i < n; i++)
    {
        v.at(i) = i;
        std::cout << v.at(i) << " ";
    }
    std::cout << "\n";

    // random permutation
    for(int i = 0; i < n; i++)
    {
        std::swap(v.at(i), v.at(random(generator, 0, n - 1)));
    }

    std::cout << "After permutation: \t";

    for(int i = 0; i < n; i++)
    {
        std::cout << v.at(i) << " ";
    }
    std::cout << "\n";
}