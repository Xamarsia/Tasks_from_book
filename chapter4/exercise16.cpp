// 16. В заданиях вам было предложено написать программу. которая для
// определенного ряда чисел определяла бы наибольшее и наименьшее
// числа в нем. Число, которое повторяется в последовательности наи­
// большее количество раз, называется модой. Напишите программу.
// определяющую модy множества положительных чисел.

#include <iostream>
#include <vector>
#include <map>
#include <limits>

int getNumber()
{
    while (true)
    {
        int number;
        std::cout << "Enter a positive number: " << std::endl;
        if (std::cin >> number && number >= 0)
        {
            return number;
        }
        std::cout << "\tIncorrect input. Please, try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

bool runAgainMessage()
{
    while (true)
    {
        std::cout << "Run again(y/n):" << std::endl;
        char runAgain;
        std::cin >> runAgain;
        if (runAgain == 'n')
        {
            return false;
        }
        else if (runAgain != 'y')
        {
            continue;
        }
        return true;
    }
}

std::map<int, int> getNumbersMap()
{
    std::map<int, int> numbersMap;
    std::cout << "\tHow many numbers do you want to enter? " << std::endl;
    int numbersCount = getNumber();
    std::cout << "\tEnter your numbers:" << std::endl;
    for (int i = 0; i < numbersCount; i++)
    {
        numbersMap[getNumber()] += 1;
    }
    return numbersMap;
}

std::vector<int> findMode(const std::map<int, int> &numbersMap)
{
    std::vector<int> mode;

    int maxCount = 1;
    for (const auto &it : numbersMap)
    {
        if (it.second > maxCount)
        {
            maxCount = it.second;
        }
    }

    for (const auto &it : numbersMap)
    {
        if (it.second == maxCount)
        {
            mode.push_back(it.first);
        }
    }

    return mode;
}

void printMode(const std::vector<int> &maxCount)
{
    std::cout << "\tMode of a set of positive numbers : ";
    for (int i : maxCount)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void run()
{
    while (true)
    {
        std::map<int, int> numbersMap = getNumbersMap();
        std::vector<int> mode = findMode(numbersMap);
        printMode(mode);

        if (!runAgainMessage())
        {
            return;
        }
    }
}
int main()
{
    run();
    return 0;
}