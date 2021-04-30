// 6. Создайте вектор, хранящий десять строковых значений " zero " , "one " ,
// " . , "nine " . Используйте его в программе, преобразующей цифру в со­
// ответствующее строковое представление: например, при вводе циф­
// ры 7 на экран должна быть выведена строка seven. С помощью этой
// же программы , используя тот же цикл ввода, преобразуйте строковое
// представление цифры в числовое: например, при вводе строки seven
// на экран должна быть выведена цифра 7 .

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::string numberString;
    int number;

    const std::vector<std::string> numbersList = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    std::cout << "Enter a number from 0 to 9 or from 'one' to 'nine'.";

    if (std::cin >> number)
    {
        if (number < numbersList.size())
        {
            std::cout << "Your number is " << numbersList[number] << std::endl;
        }
        else
        {
            std::cout << "Incorrect input." << std::endl;
        }
        return 0;
    }

    std::cin.clear();

    std::cin >> numberString;
    auto result = std::find(numbersList.begin(), numbersList.end(), numberString); // result = iterator
    if (result != numbersList.end())
    {
        int index = result - numbersList.begin();
        std::cout << "Your number is " << index << std::endl;
    }
    else
    {
        std::cout << "Incorrect input." << std::endl;
    }

    return 0;
}
