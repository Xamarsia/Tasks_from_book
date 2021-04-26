// 10 . Напишите программу, принимающую на входе символ операции с
// двумя операндами и выводящую на экран результат вычисления. На­
// пример:
// + 100 3 . 14
// * 4 5
// Считайте символ операции в строку с именем operation и, используя
// инструкцию if, выясните, какую операцию хочет выполнить пользо­
// ватель, например if (operation= " + " ) . Считывайте операнды в пере­
// менные типа douЫe. Выполните операции +, -, *· /, plus, minus. mul и
// div, имеющие очевидный смысл.

#include <iostream>

int main()
{
    char operation;
    double num1;
    double num2;
    double answer;
    std::cout << "Enter an operation symbol with two operands (* 4 5 )." << std::endl;
    std::cin >> operation >> num1 >> num2;

    if (operation == '+')
    {
        answer = num1 + num2;
    }

    else if (operation == '-')
    {
        answer = num1 - num2;
    }

    else if (operation == '*')
    {
        answer = num1 * num2;
    }

    else if (operation == '/')
    {
        answer = num1 / num2;
    }
    else
    {
        std::cout << "Incorrectly entered operation!" << std::endl;
    }

    std::cout << num1 << " " << operation << " " << num2 << " = " << answer << std::endl;
    return 0;
}