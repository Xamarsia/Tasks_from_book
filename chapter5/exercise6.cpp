// 6. Напишите программу. преобразовывающую температуру в градусах
// Цельсия в температуру в градусах Фаренгейта и обратно (по формуле
// из раздела 4.3.3). Воспользуйтесь оценками (раздел 5.8) для того, что­
// бы убедиться в правдоподобности результатов.

#include <iostream>
#include <limits>

double toFahrenheit(double celsius)
{
    double fahrenheit = 9.0 / 5 * celsius + 32;

    if (fahrenheit < -459.67)
    {
        throw std::invalid_argument("Incorrectly entered temperature! Such a low temperature does not exist.");
    }
    return fahrenheit;
}

double toCelsius(double fahrenheit)
{
    double celsius = 5.0 / 9 * (fahrenheit - 32);

    if (fahrenheit < -459.67)
    {
        throw std::invalid_argument("Incorrectly entered temperature! Such a low temperature does not exist.");
    }
    return celsius;
}

void getFahrenheit()
{
    double celsius;
    std::cout << "Enter the temperature in Celsius." << std::endl;
    std::cin >> celsius;
    double fahrenheit;

    try
    {
        fahrenheit = toFahrenheit(celsius);
        std::cout << "Your temperature in degrees Fahrenheit is " << fahrenheit << '.' << std::endl;
    }
    catch (std::invalid_argument &exception)
    {
        std::cerr << exception.what() << std::endl;
    }
}

void getCelsius()
{
    double fahrenheit;
    std::cout << "Enter the temperature in Fahrenheit." << std::endl;
    std::cin >> fahrenheit;
    double celsius;
    try
    {
        celsius = toCelsius(fahrenheit);
        std::cout << "Your temperature in degrees Celsius is " << fahrenheit << '.' << std::endl;
    }
    catch (std::invalid_argument &exception)
    {
        std::cerr << exception.what() << std::endl;
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

int main()
{
    while (askUsersAction("Do you want to convert Celsius temperature to Fahrenheit temperature?  (y/n)"))
    {
        getFahrenheit();
    }
    while (askUsersAction("Do you want to convert Fahrenheit temperature to Celsius temperature?  (y/n)"))
    {
        getCelsius();
    }

    return 0;
}