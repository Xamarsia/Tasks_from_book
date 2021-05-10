// 14. Введите пары (день недели, значение) из стандартного потока ввода.
// Например:
// Тuesday 23 Friday 56 Tuesday -3 Thursday 99
// Запишите все значения для каждого дня недели в вектор vector<int>.
// Выведите значения семи векторов для каждого из дней недели.

// Напе­чатайте сумму чисел в каждом из векторов. 

//Неправильный день
// недели, например Funday, можно игнорировать, но обычные синонимы
// допускаются, например Моn и monday.
// Выведите на печать количество отвергнутых значений.

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <tuple>
#include <string>
#include <array>


const std::array<std::array<std::string, 2>, 7> DAYS_OF_WEEK 
{
    std::array<std::string, 2>{"monday","mon"}, 
    std::array<std::string, 2>{"tuesday","tues"},
    std::array<std::string, 2>{"wednesday","wed"},
    std::array<std::string, 2>{"thursday", "thurs"},
    std::array<std::string, 2>{"friday","fri"},
    std::array<std::string, 2>{"saturday","sat"},
    std::array<std::string, 2>{"sunday","sun"}
};

int getPositiveNumber()
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

int getNumber()
{
    while (true)
    {
        int number;
        if (std::cin >> number)
        {
            return number;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string getString()
{
    std::string str;
    std::cin >> str;
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

std::pair<std::string, int> getDayNumberPair()
{
    std::pair<std::string, int> day(getString(), getNumber());
    return day;
}

int findIndexOfDay(const std::pair<std::string, int>& day)
{
    for (int i = 0; i < DAYS_OF_WEEK.size(); ++i)
    {
        for(auto &DAY : DAYS_OF_WEEK[i])
        {
            if (DAY == day.first)
            {
               return i; 
            }
            
        }

    }
    return -1;
}

int sumOfNumbers(const std::vector<int> &nums)
{
    int numbersSum = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        numbersSum += nums[i];
    }
    return numbersSum;
}

void printVector(const std::vector<int> &nums)
{
    if (nums.size() == 0)
    {
        std::cout << "Vector blank";
        return;
    }

    for (auto num : nums)
    {
        std::cout << num << " ";
    }
}

void printData(const std::array<std::vector<int>, 7>& daysOfWeekVectors)
{
    for (int i = 0; i < 7; ++i)
    {
        std::cout << "\t" << DAYS_OF_WEEK[i][0] << ": " ;
        printVector(daysOfWeekVectors[i]);
        std::cout  << "\tSum of numbers:" << sumOfNumbers(daysOfWeekVectors[i]) << std::endl;

    }
}

bool getInfoOfDay(std::array<std::vector<int>, 7>& daysOfWeekVectors)
{
    std::cout << "Please enter pairs (day of week, value): " << std::endl;
    std::pair<std::string, int> day = getDayNumberPair();
    int indexDay = findIndexOfDay(day);

    if (indexDay == -1)
    {
        return false;
    }
    else
    {
        daysOfWeekVectors[indexDay].push_back(day.second);
        return true;
    }
}


int main()
{
    std::cout << "\tHow many days do you want to enter? " << std::endl;
    int daysCount = getPositiveNumber();

    std::array<std::vector<int>, 7> daysOfWeekVectors;
    int rejectedValuesCount = 0;            // количество отвергнутых значений
    for(int i = 0; i < daysCount; ++i)
    {
        if(!getInfoOfDay(daysOfWeekVectors))
        {
            ++rejectedValuesCount;
        }
    }
    printData(daysOfWeekVectors);
    std::cout << "Count of rejected values: " << rejectedValuesCount << std::endl;


    return 0;
}