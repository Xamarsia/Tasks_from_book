// 9. Напишите программу, преобразующую слова "нуль", "два" и так далее
// в цифры О. 2 и т.д. Когда пользователь вводит число в виде слова, про­
// грамма должна вывести на экран соответствующую цифру. Выпол­
// ните эту программу для цифр О, 1 , 2, 3 и 4. Если пользователь введет
// что-нибудь другое, например фразу "rлупый компьютер! " , програм­
// ма должна ответить "Я не знаю такоrо числа! "

#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <cctype> 
#include <clocale>

int transformation(std::string &number_str)
{
    std::string array[] = {"zero", "one", "two", "three", "four"};
    for (int i = 0; i < 5; i++)
    {
        if (number_str == array[i])
        {
            std::cerr << "The number you entered is " << i << std::endl;
            return 0;
        }
    }
    throw std::invalid_argument("I don't know that number!");
}

void check(std::string number_str)
{
    for (char str : number_str)
    {
        if (!std::isalpha(str))
        {
            throw std::invalid_argument("Incorrectly entered string!");
        }
    }
}

int main()
{
    std::string number_str;

    std::cout << "Enter an integer in letters from 0 to 4 and press enter:"
              << std::endl;

    while (std::cin >> number_str)
    {
        std::transform(number_str.begin(), number_str.end(), number_str.begin(), tolower);
        try
        {
            check(number_str);
            transformation(number_str);
        }

        catch (std::invalid_argument &exception)
        {
            std::cerr << exception.what() << std::endl;
        }
    }
    return 0;
}