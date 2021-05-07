// 12 . Реализуйте простую игру на угадывание "Быки и коровы" . Программа
// должна хранить вектор из четырех различных чисел в диапазоне от О
// до 9 (т.е . , например, 2345, но не 4455), а пользователь должен угадать
// загаданное число. Допустим, программа загадала число 1 234, а поль­
// зователь назвал число 1 359: программа должна ответить " 1 бык и 1
// корова", поскольку пользователь угадал одну правильную цифру ( 1 ) в
// правильной позиции (бык) и одну правильную цифру (3) в неправиль­
// ной позиции (корова). Угадывание продолжается, пока пользователь
// не получит четырех быков, т.е . не угадает четыре правильные цифры
// в четырех правильных позициях.

//бык - одну правильную цифру ( 1 ) в правильной позиции
//корова - одну правильную цифру (3) в неправиль­ной позиции

// 13 . Следующая программа довольно сложная. Создайте вариант, в кото­
// ром игрок может играть постоянно (без остановки и повторного запу­
// ска) и в каждой новой игре генерируются новые четыре цифры. Четы­
// ре случайные цифры можно сгенерировать с помощью четырех вызо­
// вов генератора случайных целых чисел randint ( lO ) из заголовочного
// файла std_lib_facilities . h. Обратите внимание на то, что при по­
// вторном выполнении программы вы каждый раз будете получать оди­
// наковые последовательности из четырех цифр. Для того чтобы избе­
// жать этого, предложите пользователю ввести любое число и до вызова
// функции randint ( l O ) вызовите функцию srand ( n) , где n - число, вве­
// денное пользователем. Такое число n называется нач.w�ьным значени­
// ем (seed), причем разные начальные значения приводят к разным по­
// следовательностям случайных чисел.

#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <random>
#include <stdexcept>

std::vector<int> getRandomVector()
{
    std::set<int> numbers;
    while (numbers.size() != 4)
    {
        int randomVariable = std::rand() % 9;
        numbers.insert(randomVariable);
    }
    std::vector<int> randomNumbers(numbers.begin(), numbers.end());

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(randomNumbers.begin(), randomNumbers.end(), g);
    return randomNumbers;
}

bool isUniqueDigits(int number)
{
    std::set<int> numbers;
    for (int i = 10000; i > 1; i /= 10)
    {
        numbers.insert((number % i) / (i / 10));
    }
    if (numbers.size() == 4)
    {
        return true;
    }
    return false;
}

int getNumber()
{
    while (true)
    {
        std::cout << "Please input a number from four different digits." << std::endl;
        int number;
        if (!(std::cin >> number))
        {
            std::cout << "\tIncorrect number input. Please, try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (!isUniqueDigits(number))
        {
            std::cout << "Your digits in number is not unique! Please, try again." << std::endl;
            continue;
        }        

        if (number < 1000 || number > 9999)
        {
            std::cout << "Your number is not four digits! Please, try again." << std::endl;
            continue;
        }
        
        return number;
    }
}

std::vector<int> getVectorFromNumber(int number)
{
    std::vector<int> numbers;
    for (int i = 10000; i > 1; i /= 10)
    {
        numbers.push_back((number % i) / (i / 10));
    }
    return numbers;
}

int bull(const std::vector<int> &usersNumber, const std::vector<int> &randomNumbers)
{
    int bullsCount = 0;
    for (int i = 0; i < 4; i++)
    {
        if (usersNumber[i] == randomNumbers[i])
            ++bullsCount;
    }
    return bullsCount;
}

int cow(int bull, const std::vector<int> &usersNumber, const std::vector<int> &randomNumbers)
{
    int cowsCount = 0;
    for (int num : randomNumbers)
    {
        auto it = std::find(usersNumber.begin(), usersNumber.end(), num);
        if (it != usersNumber.end())
        {
            ++cowsCount;
        }
    }
    return cowsCount - bull;
}

std::string getResult(int bull, int cow)
{
    if (cow == 0 && bull == 0)
    {
        return "You don't have a single bull and cow";
    }
    if (bull > 0 && cow == 0)
    {
        if (bull == 1)
        {
            return "You hav " + std::to_string(bull) + " bull.";
        }
        return "You hav " + std::to_string(bull) + " bulls.";
    }
    else if (cow > 0 && bull == 0)
    {
        if (cow == 1)
        {
            return "You hav " + std::to_string(cow) + " cow.";
        }
        return "You hav " + std::to_string(cow) + " cows.";
    }
    else if (cow == 1 && bull == 1)
    {
        return "You hav " + std::to_string(bull) + " bull and " + std::to_string(cow) + " cow.";
    }
    return "You hav " + std::to_string(bull) + " bulls and " + std::to_string(cow) + " cows.";
}

void game()
{
    std::srand(std::time(nullptr));
    std::vector<int> randomVector = getRandomVector();
    while (true)
    {
        int num = getNumber();
        std::vector<int> usersVector = getVectorFromNumber(num);
        int bulls = bull(randomVector, usersVector);
        int cows = cow(bulls, randomVector, usersVector);
        std::cout << getResult(bulls, cows) << std::endl;
        if (bulls == 4)
        {
            std::cout << "Congratulations, you won!!!" << std::endl;
            break;
        }
    }
    return;
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

int main()
{
    while (askUsersAction("Do you want to play 'Bulls and Cows' game?  (y/n)"))
    {
        game();
    }
    return 0;
}