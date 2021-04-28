// // 4. Напишите программу, угадываюrцую число. Пользователь должен за­
// // думать число от 1 до 100, а программа должна задавать вопросы, что­
// // бы выяснить, какое число он задумал (например, "Задуманное число
// // меньше 50"). Ваша программа должна уметь идентифицировать с по­
// // мощью не более чем семи попыток. Подсказка: используйте операто­
// // ры < и <=. а также конструкцию if-else.

#include <iostream>

void binaryGuessing(int &maxNumber, int &minNumber, int &guessedNumber)
{
    char answer;
    std::cout << "\tThe intended number is less than " << guessedNumber << "?" << std::endl;
    std::cout << "\tEnter 'y' if yes and 'n' if no." << std::endl;
    std::cin >> answer;

    switch (answer)
    {
    case 'y':
        maxNumber = guessedNumber;
        guessedNumber = (minNumber + maxNumber) / 2;
        break;
    case 'n':
        minNumber = guessedNumber;
        guessedNumber = (minNumber + maxNumber) / 2;
        break;
    default:
        std::cout << "\tIncorrect input. Please try again." << std::endl;
        break;
    }
}

int main()
{
    int maxNumber = 100;
    int minNumber = 0;
    int guessedNumber = 100 / 2;

    std::cout << "Think of a number from " << minNumber << " to " << maxNumber << std::endl;
    std::cout << "Did you guess the number " << guessedNumber << "? Enter 'y' if yes and 'n' if no." << std::endl;

    for (char answer; std::cin >> answer;)
    {
        switch (answer)
        {
        case 'y':
            break;
        case 'n':
            binaryGuessing(maxNumber, minNumber, guessedNumber);
            break;
        default:
            std::cout << "\tIncorrect input. Please try again." << std::endl;
            break;

            std::cout << "Did you guess the number " << guessedNumber << "? Enter 'y' if yes and 'n' if no." << std::endl;
        }
        std::cout << "Congratulations!!! Your number is " << guessedNumber << std::endl;
    }
    return 0;
}
