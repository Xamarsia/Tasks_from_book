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

// 1О. Измените программу из упр. 8 так. чтобы она использовала тип douhle
// вместо int. Кроме того, создайте вектор действительных чисел, содер­
// жащий N- 1 разностей между соседними величинами, и выведите этот
// вектор на печать.

#include <iostream>
#include <limits>
#include <vector>
#include <stdexcept>
#include <string>

double getNumber()
{
    while (true)
    {
        double number;
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
        if (std::cin >> number && number > 0)
        {
            if (number <= max)
            {
                return number;
            }
            else
            {
                std::cout << "Your number more than " << max << "." << std::endl;
                continue;
            }
        }
        std::cout << "\tIncorrect number input. Please, try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::vector<double> fillVector()
{
    std::vector<double> numbers;
    while (true)
    {
        std::cout << "Enter multiple integers ( '|' to complete input): ";
        double number;
        if (std::cin >> number)
        {
            numbers.push_back(number);
            continue;
        }
        std::cin.clear();
        char sumbol;
        std::cin >> sumbol;
        if (sumbol != '|')
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\tIncorrect input. Please, try again." << std::endl;
            continue;
        }
        if (numbers.size() == 0)
        {
            std::cout << "Your list of numbers is empty. Please, enter some numbers. " << std::endl;
            continue;
        }
        break;
    }
    return numbers;
}

int getCount()
{
    std::cout << "Enter the number of values to be added. The number must be greater than 0." << std::endl;
    int count = getNumber();
    return count;
}

std::string printNumbers(const std::vector<double> &numbers, double max = -1)
{
    if (max == -1)
    {
        max = numbers.size();
    }
    std::string numbersLine;
    for (double i = 0; i < max; i++)
    {
        numbersLine = numbersLine + std::to_string(numbers[i]) + " ";
    }
    return numbersLine;
}

double getSum(const std::vector<double> &numbers, int count)
{
    if (count > numbers.size())
    {
        throw std::range_error("Operation cannot be performed. Fewer numbers entered than needed for summation.");
    }
    double sumNumbers = 0.0;
    double maxDouble = std::numeric_limits<double>::max();
    double minDouble = std::numeric_limits<double>::lowest();
    for (int i = 0; i < count; i++)
    {
        maxDouble -= numbers[i];
        minDouble += numbers[i];
        if (maxDouble < 0.0)
        {
            throw std::overflow_error("Your result is too large. The result cannot be represented as an int value.");
        }
        else if (minDouble > 0.0)
        {
            throw std::overflow_error("Your result is too small. The result cannot be represented as an int value.");
        }
        sumNumbers += numbers[i];
    }
    return sumNumbers;
}

std::vector<double> findDifferencesVector(const std::vector<double> &numbers, int count)
{
    std::vector<double> differences;
    if (count > numbers.size())
    {
        throw std::range_error("Operation cannot be performed. Fewer numbers entered than needed for summation.");
    }
    for (int i = 0; i < count; i++)
    {
        differences.push_back(numbers[i] - numbers[i + 1]);
    }
    return differences;
}

void run()
{
    int count = getCount();
    std::vector<double> numbers = fillVector();
    std::cout << printNumbers(numbers) << std::endl;
    double numbersSum = 0.0;
    try
    {
        numbersSum = getSum(numbers, count);
    }
    catch (const std::range_error &exception)
    {
        std::cerr << exception.what() << '\n';
        count = getNumberLessEqualMax(numbers.size());
        numbersSum = getSum(numbers, count);
    }
    catch (const std::overflow_error &exception)
    {
        std::cerr << exception.what() << '\n';
        return;
    }
    std::cout << "Sum of the first " << count << " numbers (" << printNumbers(numbers, count) << ") is " << numbersSum << std::endl;
    std::vector<double> differences = findDifferencesVector(numbers, count);
    std::cout << printNumbers(differences) << std::endl;
}

int main()
{
    run();
    return 0;
}