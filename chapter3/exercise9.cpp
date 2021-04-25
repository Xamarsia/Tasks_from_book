// 9. Напишите программу, преобразующую слова "нуль", "два" и так далее
// в цифры О. 2 и т.д. Когда пользователь вводит число в виде слова, про­
// грамма должна вывести на экран соответствующую цифру. Выпол­
// ните эту программу для цифр О, 1 , 2, 3 и 4. Если пользователь введет
// что-нибудь другое, например фразу "rлупый компьютер! " , програм­
// ма должна ответить "Я не знаю такоrо числа! "

#include <iostream>
#include <string>

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
    throw -1;
}

int main()
{
    std::string number_str;

    std::cout << "Enter an integer in letters from 0 to 4 and press enter:"
              << std::endl;

    while (std::cin >> number_str)
    {
        try
        {
            transformation(number_str);
        }
        catch (int)
        {
            std::cerr << "I don't know that number!" << std::endl;
        }
    }
    return 0;
}