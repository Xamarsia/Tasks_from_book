// 10. Напишите программу для игры "Камень. бумага. ножницы". Если вы
// не знаете правил этой игры. попробуйте выяснить их у друзей или с
// помощью Google (поиск информации - обычное занятие программи­

// стов). Кроме того, машина должна давать случайные ответы (т.е. вы­
// бирать камень, бумагу или ножницы на следующем ходу случайным
// образом). Написать настоящий генератор случайных чисел прямо
// сейчас вам будет довольно тяжело. поэтому заранее заполните век­
// тор последовательностью значений. Если встроить этот вектор в
// программу. то она всегда будет играть одну и ту же игру. поэтому це­
// лесообразно позволить пользователю самому вводить некоторые зна­
// чения. Попробуйте помешать пользователю легко угадывать следую­
// щий ход машины.

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <ctime>

const std::vector<std::string> possibleAnswers = {"rock", "scissors", "paper"};

std::string randomAnswer()
{
    int randomVariable = std::rand();
    return possibleAnswers[randomVariable % 3];
}

std::string getAnswer()
{
    std::string usersAnswer;
    while (true)
    {
        std::cout << "Enter 'rock', 'scissors', or 'paper':" << std::endl;
        std::cin >> usersAnswer;
        auto result = std::find(possibleAnswers.begin(), possibleAnswers.end(), usersAnswer);
        if (result != possibleAnswers.end())
        {
            break;
        }
        std::cout << "\tIncorrect input. Please try again." << std::endl;
    }
    return usersAnswer;
}

std::string gameResult(std::string usersAnswer, std::string programsAnswer)
{
    if (usersAnswer == programsAnswer)
    {
        return "Tie";
    }

    bool playerWon = (usersAnswer == "rock" && programsAnswer == "scissors") ||
                     (usersAnswer == "scissors" && programsAnswer == "paper") ||
                     (usersAnswer == "paper" && programsAnswer == "rock");

    if (playerWon)
    {
        return "Congratulations, you won.";
    }
    else
    {
        return "You lose.";
    }
}

void games()
{
    while (true)
    {
        char answer;
        std::cout << "Do you want to play game? (y/n)";
        std::cin >> answer;
        if (answer == 'n')
        {
            break;
        }
        if (answer != 'y')
        {
            std::cout << "\tIncorrect input. Please try again." << std::endl;
            continue;
        }
        std::string programsAnswer = randomAnswer();

        std::string usersAnswer = getAnswer();

        std::cout << "Your turn: " << usersAnswer << "\tEnemy move: " << programsAnswer << std::endl;
        std::cout << gameResult(usersAnswer, programsAnswer) << std::endl;
    }
}

int main()
{
    std::srand(std::time(nullptr));
    games();
    return 0;
}