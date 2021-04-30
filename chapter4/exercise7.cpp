// 7. Модифицируйте мини-калькулятор, описанный в упр. 5, так. чтобы он
// принимал на вход цифры. записанные как в числовом, так и в строко­
// вом формате.

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

double calculate(int num1, int num2, char operation)
{
    switch (operation)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '/':
        return num1 / num2;
    case '*':
        return num1 * num2;
    }
    return std::numeric_limits<double>::quiet_NaN();
}

bool operatorIsValid(char operation)
{
    return operation == '+' || operation == '/' || operation == '*' || operation == '-';
}

int convertToNumber(std::string numberString)
{

    const std::vector<std::string> numbersList = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    auto result = std::find(numbersList.begin(), numbersList.end(), numberString); // result = iterator
    if (result != numbersList.end())
    {
        int index = result - numbersList.begin();
        return index;
    }
    return -1;
}

int getNumber()
{
    int number;
    if (std::cin >> number)
    {
        if (number < 0 || number > 9)
        {
            number = -1;
            return number;
        }
        return number;
    }

    std::cin.clear();
    std::string numberString;
    std::cin >> numberString;
    number = convertToNumber(numberString);
    return number;
}

bool runAgain()
{
    while(true)
    {
        std::cout << "Run again(y/n):" << std::endl;
        char runAgain;
        std::cin >> runAgain;
        if (runAgain == 'n')
        {
            return false;
        }
        else if(runAgain != 'y')
        {
            continue;
        }
        return true;    
    }
 
}
        
int main()
{
    while (true)
    {
        std::cout << "Enter three arguments: two numeric values and an operation symbol." << std::endl;
        std::cout << "Numbers must be from 0 to 9 or from 'one' to 'nine'." << std::endl;

        int num1 = getNumber();
        int num2 = getNumber();
        char operation;
        std::cin >> operation;

        if (operatorIsValid(operation))
        {
            std::cout << "\tIncorrect operation input. Please try again." << std::endl;
            continue;
        }
        else if (num1 == -1 || num2 == -1)
        {
            std::cout << "\tIncorrect numbers input. Please try again." << std::endl;
            continue;
        }
        else if (num2 == 0 && operation == '/')
        {
            std::cout << "\tCan't divide by zero. Please try again." << std::endl;
            continue;
        }

        double answer = calculate(num1, num2, operation);
        std::cout << "\t" << num1 << " " << operation << " " << num2 << " = " << answer << std::endl;
        if(!runAgain())
        {
            return 0;
        }
    }

    return 0;
}
