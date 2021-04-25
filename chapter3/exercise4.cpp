// 4. Напишите программу. предлагающую пользователю ввести два цело­
// численных значения. Запишите эти значения в переменные типа int
// с именами val l и val2 . Напишите программу. определяющую наи­
// меньшее и наибольшее значения, а также сумму, разность, произве­
// дение и частное этих значений.

#include <iostream>
#include <algorithm>

int main()
{
    int val1;
    int val2;
    std::cout << "Enter two integer values and press 'enter':" << std::endl;
    std::cin >> val1 >> val2;
    if (val1 = val2)
    {
        std::cout << val1 << " = " << val2 << std::endl;
    }
    else
    {
        std::cout << "Maximum: " << std::max(val1, val2) << std::endl;
        std::cout << "Minimum: " << std::min(val1, val2) << std::endl;
    }

    std::cout << "Sum: " << val2 + val1 << std::endl;
    std::cout << "Division: " << val1 / val2 << std::endl;
    std::cout << "Average: " << (val2 + val1) / 2 << std::endl;
    return 0;
}