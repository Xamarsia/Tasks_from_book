// 9. Попробуйте вычислить количество зерен риса, запрошенных изобре­
// тателем шахмат в упр . 8. Оказывается. что это число настолько ве­
// лико. что для его точного представления не подХодит ни тип int, ни
// тип douЫe. Чему равно наибольшее количество клеток. для которых
// еще можно вычислить точное количество зерен риса (с использовани­
// ем переменной типа int). Определите наибольшее количество клеток.
// для которых еще можно вычислить приближенное количество зерен
// (с использованием переменной типа douЫe)?

#include <iostream>
#include <limits>

template<typename T>
int maxCellsForType()
{
    T allPrevGrains = 0;
    T currentGrains = 1;
    int currentCell = 1;
    while(currentGrains + allPrevGrains < std::numeric_limits<T>::max()/2)
    {
        allPrevGrains +=  currentGrains;        
        currentGrains *=  2;
        ++currentCell;

    }
    return currentCell;
}
 
int main()
{
    std::cout << maxCellsForType<int>() << std::endl;
    std::cout << maxCellsForType<double>() << std::endl;
    return 0;
}