// 2. Допустим, мы определяем медиану последовательности как "число,
// относительно которого ровно половина элементов меньше, а другая
// половина - больше". Исправьте программу из раздела 4.6.2 так, что­
// бы она всегда выводила медиану. Подсказка: медиана не обязана быть
// элементом последовательности.

#include <iostream>
#include <vector>

int main()
{
    double sum;
    double median;
    std::cout << "Enter the number:" << std::endl;
    std::vector<double> sequence;
    for (double number; std::cin >> number;)
    {
        sequence.push_back(number);
        sum = sum + number;
        median = sum / sequence.size();
        std::cout << "The median of the sequence is: " << median << " ." << std::endl;
    }

    
    return 0;
}