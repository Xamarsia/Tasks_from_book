// 4. Напишите программу. предлагающую пользователю ввести два цело­
// численных значения. Запишите эти значения в переменные типа int
// с именами val l и val2 . Напишите программу. определяющую наи­
// меньшее и наибольшее значения, а также сумму, разность, произве­
// дение и частное этих значений.

#include <iostream>

int main()
{
    int val1;
    int val2;
    std::cout << "Enter two integer values and press 'enter': \n ";
    std::cin >> val1 >> val2;
    if (val1 > val2)
    {
        std::cout << "Minimum: " << val2 << "\n ";
        std::cout << "Maximum: " << val1 << "\n ";
    }
    else if (val1 < val2)
    {
        std::cout << "Minimum: " << val1 << "\n ";
        std::cout << "Maximum: " << val2 << "\n ";
    }
    else
    {
        std::cout << val1 << "=" << val2 << "\n ";
    }
    std::cout << "Sum: " << val2 + val1 << "\n ";
    std::cout << "Division : " << val1 / val2 << "\n ";
    std::cout << "Average: " << (val2 + val1) / 2 << "\n ";
    return 0;
}