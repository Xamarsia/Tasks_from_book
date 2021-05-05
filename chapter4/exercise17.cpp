// 17 . Напишите программу, определяющую наименьшее и наибольшее
// значения, а также модy последовательности строк типа s tring.

#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <stdexcept>

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

int getMax(const std::map<int, int> &numbersMap)
{
    if(numbersMap.size() == 0)
    {
        throw std::length_error("Empty map.");
    }
    int maxNumber = numbersMap.begin()->first;

    for (const auto &it : numbersMap)
    {
        if (it.first > maxNumber)
        {
            maxNumber = it.first;
        }
    }
    return maxNumber;
}

int getMin(const std::map<int, int> &numbersMap)
{
    if(numbersMap.size() == 0)
    {
        throw std::length_error("Empty map.");
    }
    int minNumber = numbersMap.begin()->first;
    for (const auto &it : numbersMap)
    {
        if (it.first < minNumber)
        {
            minNumber = it.first;
        }
    }
    return minNumber;
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
        if(numbersMap.size() == 0)
        {
            std::cout << "The sequence of lines is empty." << std::endl;
            return;
        }
        std::vector<int> mode = findMode(numbersMap);
        printMode(mode);
        std::cout << "Your smallest value: " << getMin(numbersMap) << std::endl;
        std::cout << "Your greatest value: " << getMax(numbersMap) << std::endl;
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