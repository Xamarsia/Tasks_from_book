// 19. Напишите программу, в которую сначала вводится набор пар, состо­
// ящих из имени и значения, например Joe 17 и Barbara 22. Для ка­
// ждой пары занесите имя в вектор names , а число - в вектор scores
// (в соответствующие позиции. так что если names [ 7 ] == " Joe" . то
// scores [ 7 ] =17 ) . Прекратите ввод. встретив строку ввода NoName О .
// Убедитесь. что каждое имя единственное. и выведите сообщение об
// ошибке. если имеется имя, введенное дважды. Выведите на печать все
// пары ( имя. баллы) по одной в строке.

// 20. Измените программу из упр. 19 так, чтобы при вводе имени она выво­
// дила соответствующее количество баллов или сообщение"Имя не най­дено " .

// 21 . Измените программу из упр. 19 так, чтобы при вводе целого числа она
// выводила имена всех студентов, получивших указанное количество
// баллов, или сообщение " Баллы не найдены " .

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

double getNumber()
{
    while (true)
    {
        double number;
        if (std::cin >> number && number >= 0)
        {
            return number;
        }
        std::cout << "\tIncorrect number input. Please, try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string getUniqueName(const std::vector<std::string> &names)
{
    while (true)
    {
        std::string newName;
        std::cin >> newName;
        for (std::string name : names)
        {
            if (newName == name)
            {
                std::cout << "\tIncorrect name input. This name is entered twice. Please, try again." << std::endl;
                std::cin.clear();
                continue;
            }
        }
        return newName;
    }
}

void getPair(std::vector<std::string>& names, std::vector<int>& scores)
{
    while (true)
    {
        std::cout << "Please enter a pair of values (name and score): " << std::endl;
        std::string name = getUniqueName(names);
        int score = getNumber();
        if (name == "NoName" && score == 0)
        {
            return;
        }
        else
        {
            names.push_back(name);
            scores.push_back(score);
        }
    }
}

void printAllPairs(const std::vector<std::string> &names, const std::vector<int> &scores)
{
    for (int i = 0; i < names.size(); i++)
    {
        std::cout << "\tYour pair:" << names[i] << " " << scores[i] << std::endl;
    }
}

void printData(const std::string& name, const std::vector<std::string> &names, const std::vector<int> &scores)
{
    auto it = std::find(names.begin(), names.end(), name);
    if(it == names.end())
    {
        std::cout << "Name not found." << std::endl;
    }
    else
    {
        auto index = it - names.begin();
        std::cout << names[index] << " has " << scores[index] << " scores." << std::endl;
    }
}

void printData(const int& appraisal, const std::vector<std::string> &names, const std::vector<int> &scores)
{
    auto it = std::find(scores.begin(), scores.end(), appraisal);
    if(it == scores.end())
    {
        std::cout << "No scores found." << std::endl;
    }
    else
    {
        auto index = it - scores.begin();
        std::cout << names[index] << std::endl;
    }
}


bool askUsersAction(const std::string &question)
{
    while (true)
    {
        std::cout << question << std::endl;
        char ansver;
        std::cin >> ansver;
        switch (ansver)
        {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\tIncorrect input. Please, try again." << std::endl;
        }
    }
}

void run()
{
    std::vector<std::string> names;
    std::vector<int> scores;
    getPair(names, scores);
    printAllPairs(names, scores);
    if(askUsersAction("Do you want find name from your notes? (y/n)"))
    {
        std::cout << "Please, enter the name" << std::endl;
        std::string name;
        std::cin >> name;
        printData(name,names,scores);
    }

    if(askUsersAction("Do you want find humens with some scores? (y/n)"))
    {
        std::cout << "Enter the number of scores:" << std::endl;
        int appraisal = getNumber();
        printData(appraisal, names,scores);
    }
}

int main()
{
    run();
    return 0;
}