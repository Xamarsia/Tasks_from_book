// 11. Напишите программу. предлагающую пользователю ввести опреде­
// ленное количество 1 -, 5-, 1 0- , 25-, 50-центовых и долларовых монет.
// Пользователь должен по отдельности ввести количество монет каж­
// дого достоинства, например "Сколько у вас одвоцевтовьп монет?"
// Затем программа должна вывести результат примерно такого вида.

// У вас 23 одноцентовwх нонет.
// У вас 17 пятицентовwх нонет.
// У вас 14 десятицентовwх нонет.
// У вас 7 дв адцатипятицентовwх нонет.
// У вас 3 пятидесятицентовwх нонет.
// Общая стоимость ваших нонет равна 573 центам.

// Усовершенствуйте программу: если у пользователя только одна моне­
// та, выведите ответ в грамматически правильной форме. Например,
// 1 4 десятицентовых монет" и "1 одвоцевтовая монета" (а не " 1 од­
// ноцевтовых монет" ) . Кроме того, выведите результат в долларах и
// центах, т.е. 5 долларов 73 цента. а не 573 цента.
//"one-cent" coins,

#include <iostream>
#include <string>

int main()
{
    int quantity[5];
    int numberDenomination[] = {1, 5, 10, 25, 50};
    std::string denomination[] = {"one-cent", "five-cent", "dime", "twenty-five-cent", "fifty-cent"};
    int totalCoints;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "How many " << denomination[i] << " coins do you have?" << std::endl;
        std::cin >> quantity[i];
    }
    for (int i = 0; i < 5; i++)
    {
        if (quantity[i] == 1)
        {
            std::cout << "You have " << quantity[i] << " " << denomination[i] << " coin." << std::endl;
        }
        else
        {
            std::cout << "You have " << quantity[i] << " " << denomination[i] << " coins." << std::endl;
        }

        totalCoints = totalCoints + quantity[i] * numberDenomination[i];
    }

    std::cout << "\nYou have " << totalCoints / 100 << " dollars and " << totalCoints % 100 << " cents." << std::endl;

    if (totalCoints == 1)
    {
        std::cout << "The total value of your coins is " << totalCoints << " cent." << std::endl;
    }
    else
    {
        std::cout << "The total value of your coins is " << totalCoints << " cents." << std::endl;
    }

    return 0;
}