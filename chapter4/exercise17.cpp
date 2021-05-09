// 17 . Напишите программу, определяющую наименьшее и наибольшее
// значения, а также модy последовательности строк типа string.

#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <stdexcept>

std::string getString()
{
    std::cout << "Enter a string: " << std::endl;
    std::string str;
    std::cin >> str;
    return str;
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

std::map<std::string, int> getStringsMap()
{
    std::map<std::string, int> stringsMap;
    std::cout << "\tHow many strings do you want to enter? " << std::endl;
    int stringsCount = getNumber();
    std::cout << "\tEnter your string:" << std::endl;
    for (int i = 0; i < stringsCount; i++)
    {
        stringsMap[getString()] += 1;
    }
    return stringsMap;
}

std::vector<std::string> findMode(const std::map<std::string, int> &stringMap)
{
    std::vector<std::string> mode;

    int maxCount = 1;
    for (const auto &it : stringMap)
    {
        if (it.second > maxCount)
        {
            maxCount = it.second;
        }
    }

    for (const auto &it : stringMap)
    {
        if (it.second == maxCount)
        {
            mode.push_back(it.first);
        }
    }
    return mode;
}


std::string getMax(const std::map<std::string, int> &stringMap)
{
    if (stringMap.size() == 0)
    {
        throw std::length_error("Empty map.");
    }
    std::string maxString = stringMap.begin()->first;

    for (const auto &it : stringMap)
    {
        if (it.first > maxString)
        {
            maxString = it.first;
        }
    }
    return maxString;
}

std::string getMin(const std::map<std::string, int> &stringMap)
{
    if (stringMap.size() == 0)
    {
        throw std::length_error("Empty map.");
    }
    std::string minString = stringMap.begin()->first;
    for (const auto &it : stringMap)
    {
        if (it.first < minString)
        {
            minString = it.first;
        }
    }
    return minString;
}

void printMode(const std::vector<std::string> &maxCount)
{
    std::cout << "\tMode of a set of strings: ";
    for (auto i : maxCount)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void run()
{
    while (true)
    {
        std::map<std::string, int> stringsMap = getStringsMap();
        if (stringsMap.size() == 0)
        {
            std::cout << "The sequence of lines is empty." << std::endl;
            return;
        }
        std::vector<std::string> mode = findMode(stringsMap);
        printMode(mode);
        std::cout << "Your smallest value: " << getMin(stringsMap) << std::endl;
        std::cout << "Your greatest value: " << getMax(stringsMap) << std::endl;
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