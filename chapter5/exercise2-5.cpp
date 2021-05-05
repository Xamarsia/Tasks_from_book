// 2. Следующая программа получает температуру в градусах Цельсия
// и преобразует ее в температуру в градусах Кельвина. Этот исходный
// текст содержит много ошибок. Найдите ошибки. перечислите их и ис­
// правьте программу.

// 3. Самой низкой температурой является абсолютный нуль, т.е. -273. 15°C,
// или ОК. Даже после исправления приведенная выше программа выво­
// дит неверные результаты для температуры ниже абсолютного нуля.
// Поместите в функцию main ( ) проверку, которая будет выводить сооб­
// щение об ошибке для температур ниже -273. 1 5°С.


// 4. Повторите упр. 3 , но в этот раз ошибку обрабатывайте в функции
// ctok().


#include <iostream>

double toKelvin(double celsiusT)
{
    double kelvinT = celsiusT + 273.15;
    if (kelvinT < -273.15) //  task 4
    {
        throw std::invalid_argument("Incorrectly entered temperature!Such a low temperature does not exist.");
    }
    return kelvinT;
}


int main()
{
    double celsius;
    std::cout << "Enter the temperature in Celsius." << std::endl;
    std::cin >> celsius;
    double kelvin;
    try
    { 
        kelvin = toKelvin(celsius);
    }

    catch (std::invalid_argument &exception)
    {
        std::cerr << exception.what() << std::endl;
    }
    std::cout << "Your temperature in degrees Kelvin is " << kelvin << '.' << std::endl;

    return 0;
}