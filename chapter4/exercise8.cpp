// 8. Легенда гласит, что некий царь захотел поблагодарить изобретате­
// ля шахмат и предложил ему попросить любую награду. Изобретатель
// попросил положить на первую клетку одно зерно риса. на вторую -
// два. на третью - четыре и так далее, удваивая количество зерен на
// каждой из 64 клеток. На первый взгляд. это желание выглядит впол­
// не скромным. но на самом деле в царстве не было такого количества
// риса!
//      Напишите программу. вычисляющую. сколько клеток надо за­
// полнить. чтобы изобретатель получил не менее 1 ООО зерен риса, не
// менее 1 ООО ООО зерен риса и не менее 1 ООО ООО ООО зерен риса. Вам,
// разумеется. понадобится цикл и. вероятно, несколько переменных
// типа int. для того чтобы отслеживать текущий номер клетки. коли­
// чество зерен в текущей клетке и количество зерен во всех предыду­
// щих клетках. Мы предлагаем на каждой итерации цикла выводить на 
// экран значения всех этих переменных, чтобы видеть промежуточные
// результаты.

#include <iostream>

int getGrains(unsigned int grains)
{
    int allPrevGrains = 0;
    int currentGrains = 1;
    int currentCell = 1;
    while(currentGrains + allPrevGrains < grains)
    {
        allPrevGrains +=  currentGrains;        
        currentGrains *=  2;
        ++currentCell;
    }
    return currentCell;
}

int main()
{
    std::cout << getGrains(1000) << std::endl;
    std::cout << getGrains(1000000) << std::endl;
    std::cout << getGrains(1000000000) << std::endl;
    return 0;
}