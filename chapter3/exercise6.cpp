// 6. Напишите программу. предлагающую пользователю ввести три целых
// числа, а затем выводит их в порядке возрастания, разделяя запяты­
// ми. Например, если пользователь вводит числа 10 4 6. то программа
// должна вывести на экран числа 4, 6, 10. Если два числа совпадают. то
// они должны идти одно за другим. Например. если пользователь вво­
// дит числа 4 5 4, то программа должна вывести на экран 4, 4, 5.

#include <iostream>

void sortInsertion(int array[], unsigned int num)
{
    for (int i = 0; i < num; i++)
    {
        int temp = array[i];
        int item = i - 1;
        while (item >= 0 && array[item] > temp)
        {
            array[item + 1] = array[item];
            array[item] = temp;
            item--;
        }
    }
}

int main()
{
    int array[3];

    std::cout << "Enter three integer values and press 'enter': \n";
    for (int i = 0; i < 3; i++)
    {
        std::cin >> array[i];
    }
    sortInsertion(array, 3);

    for (int i = 0; i < 3; i++)
    {
        std::cout << array[i];
        if (i < 2)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
    return 0;
}