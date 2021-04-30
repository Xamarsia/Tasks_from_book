// 5 . Напишите программу, выполняюrцую самые простые функции каль­
// кулятора. Ваш калькулятор должен выполнять четыре основные
// арифметические операции - сложение, вычитание, умножение и де­
// ление. Программа должна предлагать пользователю ввести три аргу­
// мента: два значения типа douЫe и символ операции. Если входные
// аргументы равны 35 . 6, 24 . 1 и ' + ' , то программа должна вывести на
// экран строку " Сумма 35 . 6 и 24 . 1 равна 5 9 . 7 " . В главе 6 мы рассмотрим
// более сложный калькулятор.



#include <iostream>
#include <exception>
#include <algorithm>
#include <cctype>
#include <clocale>

int main()
{
    double num1;
    double num2;
    char operation;
    std::cout << "Enter three arguments: two numeric values and an operation symbol." << std::endl;
    while (std::cin >> num1 >> num2 >> operation)
    {
        switch (operation)
        {

        case '+':
            std::cout << "The sum of " << num1 << " and " << num2 << " is equal to " << num1 + num2 << std::endl;
            break;

        case '-':
            std::cout << "The difference of " << num1 << " and " << num2 << " is equal to " << num1 - num2 << std::endl;
            break;

        case '/':
            if (num2 == 0)
            {
                std::cout << "Incorrect input. You cannot divide by zero!" << std::endl;
            }
            else
            {
                std::cout << "The product of " << num1 << " and " << num2 << " is equal to " << num1 / num2 << std::endl;
            }
            break;

        case '*':
            std::cout << "The quotient of " << num1 << " and " << num2 << " is equal to " << num1 * num2 << std::endl;
            break;

        default:
            std::cout << "\tIncorrect operation input. Please try again." << std::endl;
        }

        std::cout << "Enter three arguments: two numeric values and an operation symbol." << std::endl;
    }
    if(!std::cin)
    {
        std::cout << "\tIncorrect input." << std::endl;
    }
    return 0;
}