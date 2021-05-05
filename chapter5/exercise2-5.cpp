// 2. Следующая программа получает температуру в градусах Цельсия
// и преобразует ее в температуру в градусах Кельвина. Этот исходный
// текст содержит много ошибок. Найдите ошибки. перечислите их и ис­
// правьте программу.


#include <iostream>

double toKelvin(double celsiusT)
{
    double kelvinT = celsiusT + 273.15;
    return kelvinT;
}


int main()
{
    double celsius;
    std::cout << "Enter the temperature in Celsius." << std::endl;
    std::cin >> celsius;
    double kelvin;
    std::cout << "Your temperature in degrees Kelvin is " << kelvin << '.' << std::endl;

    return 0;
}