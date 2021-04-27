// 3. Прочтите последовательности чисел типа douЬle в вектор. Будем счи­
// тать, что каждое значение представляет собой расстояние между дву­
// мя городами, расположенными на определенном маршруте. Вычисли­
// те и выведите на печать общее расстояние (сумму всех расстояний).
// Найдите и выведите на печать наименьшее и наибольшее расстоя­
// ния между двумя соседними городами. Найдите и выведите на печать
// среднее расстояние между двумя соседними городами.

#include <iostream>
#include <vector>

int main()
{

    double totalDistance;
    double average;
    double min;
    double max;

    std::cout << "Enter the distance between two cities on a particular route." << std::endl;
    std::vector<double> sequence;
    for (double distance; std::cin >> distance;)
    {
        if (distance <= 0)
        {
            std::cout << "The distance should not be so small. Try again." << std::endl;
        }
        else if (distance > 0)
        {
            sequence.push_back(distance);

            if (sequence.size() == 1)
            {
                min = sequence[0];
                max = sequence[0];
            }
            totalDistance = totalDistance + distance;

            if (min > distance)
            {
                min = distance;
            }
            else if (max < distance)
            {
                max = distance;
            }
        }
    }

    average = totalDistance / sequence.size();
    std::cout << "Total distance between cities:" << totalDistance << " ." << std::endl;
    std::cout << "Shortest distance between two neighboring cities:" << min << " ." << std::endl;
    std::cout << "Longest distance between two neighboring cities:" << max << " ." << std::endl;
    std::cout << "Average distance between two neighboring cities:" << average << " ." << std::endl;
    return 0;
}