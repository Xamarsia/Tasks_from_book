// 11 . Напишите программу, вычисляющую начальный отрезок последова­
// тельности Фибоначчи, т.е. последовательности, начинающиеся с чи­
// сел 0 1 1 2 3 5 8 13 21 34. Каждое число в этой последовательности рав­
// но сумме двух предыдущих. Найдите наибольшее число Фибоначчи,
// которое можно записать в переменную типа int.

#include <iostream>
#include <vector>
#include <limits>

int FibonacciSequence(int max)
{
    int oldNum1 = 0;
    int oldNum2 = 1;
    int newNum = 0;
    while(oldNum1 < max - oldNum2 && oldNum1 + oldNum2 < max)
    {   
        newNum = oldNum1 + oldNum2;
        oldNum1 = oldNum2;
        oldNum2 = newNum;
    }
    return newNum;
}


int main()
{
    std::cout << FibonacciSequence(std::numeric_limits<int>::max()) << std::endl;
     
    return 0;
}