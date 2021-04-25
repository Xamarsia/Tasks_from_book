// 7. Выполните упр. 6 для трех строковых значений. Так, если пользова­
// тель вводит значения Steinbeck, Hemingway, Fitzgerald, то вывод
// программы должен имеет вид Fitzgerald, Hemingway. Steinbeck.

#include <iostream>

void sortInsertion(std::string array[], unsigned int num)
{
    for (int i = 0; i < num; i++)
    {
        std::string temp = array[i];
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
    std::string array[3];

    std::cout << "Enter three string values and press 'enter':\n";
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