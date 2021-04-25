// 5. Измените программу так, чтобы она просила пользователя ввести два
// числа с плавающей точкой и сохраняла их в переменных типа douЬle.
// Сравните результаты работы этих двух программ для некоторых вход­
// ных данных на ваш выбор. Совпадают ли эти результаты? Должны ли
// они совпадать? Чем они различаются?

#include <iostream>

int main()
{
    double val1;
    double val2;
    std::cout << "Enter two integer values and press 'enter': \n";
    std::cin >> val1 >> val2;
    if (val1 > val2)
    {
        std::cout << "Minimum: " << val2 << "\n";
        std::cout << "Maximum: " << val1 << "\n";
    }
    else if (val1 < val2)
    {
        std::cout << "Minimum: " << val1 << "\n";
        std::cout << "Maximum: " << val2 << "\n";
    }
    else
    {
        std::cout << val1 << "=" << val2 << "\n";
    }
    std::cout << "Sum: " << val2 + val1 << "\n";
    std::cout << "Division: " << val1 / val2 << "\n";
    std::cout << "Average: " << (val2 + val1) / 2 << "\n";
    return 0;
}