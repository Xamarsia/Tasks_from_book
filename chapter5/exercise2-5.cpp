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

// 5. Измените программу так. чтобы она преобразовывала температуру в
// градусах Кельвина в температуру в градусах Цельсия.

#include <iostream>

double toCelsius(double kelvinT)
{
    double celsiusT = kelvinT - 273.15;
    if (kelvinT < -273.15)
    {
        throw std::invalid_argument("Incorrectly entered temperature!Such a low temperature does not exist.");
    }
    return celsiusT;
}


int main()
{
    double kelvin;
    std::cout << "Enter the temperature in Kelvin." << std::endl;
    std::cin >> kelvin;
    double celsius;
    try
    { 
        kelvin = toCelsius(kelvin);
    }

    catch (std::invalid_argument &exception)
    {
        std::cerr << exception.what() << std::endl;
    }
    
    std::cout << "Your temperature in degrees Celsius is " << kelvin << '.' << std::endl;

    return 0;
}