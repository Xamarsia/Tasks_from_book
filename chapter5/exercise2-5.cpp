// 2. Следующая программа получает температуру в градусах Цельсия
// и преобразует ее в температуру в градусах Кельвина. Этот исходный
// текст содержит много ошибок. Найдите ошибки. перечислите их и ис­
// правьте программу.

// 3. Самой низкой температурой является абсолютный нуль, т.е. -273. 15°C,
// или ОК. Даже после исправления приведенная выше программа выво­
// дит неверные результаты для температуры ниже абсолютного нуля.
// Поместите в функцию main ( ) проверку, которая будет выводить сооб­
// щение об ошибке для температур ниже -273. 1 5°С.

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
    double kelvin = toKelvin(celsius); 
    if (kelvin < -273.15) //  task 5
    {
        std::cout << "Error, there is no such low temperature." << std::endl;
        return 0;
    }
    std::cout << "Your temperature in degrees Kelvin is " << kelvin << '.' << std::endl;

    return 0;
}