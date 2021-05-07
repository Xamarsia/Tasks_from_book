// 8. Напишите программу. считывающую и сохраняюшую ряд целочис­
// ленных значений, а затем вычисляющую сумму первых N чисел. За­
// просите значение N. считайте значения в vector и вычислите сумму
// первых N значений. Н апример:
// Введите копичество суммируемых значений :
// 3
// Введите нескопько це.пых чисеп ( 1 дпя окончания ввода) :
// 12 23 13 24 15
// Сумма первых 3 чисеп ( 12 23 1 3 ) равна 48 .
// Обрабатывайте любые входные данные. Например, если пользовате­
// лю требуется просуммировать чисел больше, чем сохранено в векторе,
// выводите соответствующее сообщение.

// 9. Измените программу из упр. 8 так. чтобы она выводила сообщение об
// ошибке, если результат не может быть представлен в виде значения
// типа int.

#include <iostream>
#include <limits>
#include <vector>
#include <stdexcept>
#include <string>

int getNumber()
{
    while (true)
    {
        int number;
        if (std::cin >> number && number > 0)
        {
            return number;
        }
        std::cout << "\tIncorrect number input. Please, try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int getNumberLessEqualMax(int max)
{
    while (true)
    {
        std::cout << "Please select a number no more than " << max << std::endl;
        int number;
        if (std::cin >> number && number > 0 )
        {
            if (number <= max)
            {
                return number;
            }
            else
            {
                std::cout << "Your number more then " << max  << "."<< std::endl;
                continue;
            }
        }
        std::cout << "\tIncorrect number input. Please, try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::vector<int> fillVector()
{
    std::vector<int> numbers;
    while (true)
    {
        std::cout << "Enter multiple integers ( '|' to complete input): ";
        int number;
        if (std::cin >> number)
        {
            numbers.push_back(number);
        }
        else
        {
            std::cin.clear();
            char sumbol;
            std::cin >> sumbol;
            if (sumbol == '|')
            {
                if(numbers.size() == 0)
                {
                    std::cout << "Your list of numbers is empty. Enter some numbers, please. " << std::endl;
                    continue;
                }
                break;
            }
            else
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\tIncorrect input. Please, try again." << std::endl;
            }
        }
    }
    return numbers;
}

int getCount()
{
    std::cout << "Enter the number of values to be added. The number must be greater than 0." << std::endl;
    int count = getNumber();
    return count;
}

std::string printNumbers(const std::vector<int>& numbers, int max = -1)
{
    if(max == -1)
    {
        max = numbers.size();
    }
    std::string numbersLine;
    for (int i = 0; i < max; i++)
    {
        numbersLine = numbersLine + std::to_string(numbers[i]) + " ";
    }
    return numbersLine;
}

int getSum(const std::vector<int> &numbers, int count)
{
    if (count > numbers.size())
    {
        throw std::range_error("Operation cannot be performed. Fewer numbers entered than needed for summation.");
    }
    int sumNumbers = 0;
    int maxInt = std::numeric_limits<int>::max();
    int minInt = std::numeric_limits<int>::min();
    for (int i = 0; i < count; i++)
    {
        sumNumbers += numbers[i];

        maxInt -= numbers[i];
        minInt +=numbers[i];
        if (maxInt < 0 || minInt > 0)
        {
            throw std::overflow_error("Your result is too large. The result cannot be represented as an int value.");
        }
    }
    return sumNumbers;
}

void run()
{
    int count = getCount();
    std::vector<int> numbers = fillVector();
    printNumbers(numbers);
    int numbersSum = 0;
    try
    {
       numbersSum = getSum(numbers, count);
    }
    catch(const std::range_error& exception)
    {
        std::cerr << exception.what() << '\n';
        count = getNumberLessEqualMax(numbers.size());
        numbersSum = getSum(numbers, count);
    }
    catch(const std::overflow_error& exception)
    {
        std::cerr << exception.what() << '\n';
        return;
    }
    std::cout << "Sum of the first "<< count << " numbers (" << printNumbers(numbers, count) << ") is " << numbersSum << std::endl; 

}

int main()
{
    run();
    return 0;
}