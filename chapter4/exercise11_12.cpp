// 11 . Напишите программу. находящую все простые числа между 1 и 100.
// Для этого можно написать функцию. проверяющую. является ли чис­
// ло простым (т.е. делится ли оно на простое число, не превосходящее
// данное). используя вектор простых чисел, записанный в порядке воз­
// растания (например, если вектор называется primes, то primes [ 0 ] =2 ,
// primes [ 1 ] =3, primes [2 ] =5 и т.д.). Напишите цикл перебора чисел от 1
// до 1 00. проверьте каждое из них на простоту и сохраните найденные
// простые числа в векторе. Напишите другой цикл. в котором все найден­
// ные простые числа выводятся на экран. Сравните полученные резуль­
// таты с вектором primes. Первым простым числом считается число 2.

// +
// 12. Измените программу из предыд.Ущего упражнения так, чтобы в нее
// вводилось число max, а затем найдите все простые числа от 1 до max.


#include <iostream>
#include <vector>

std::vector<int> createPrimesVector(int max)
{
    std::vector<int> primes = {2};

    auto primeCheck = 
    [] (int num, const std::vector<int> &primes) 
    {
        for (int primeNum : primes)
        {
            if (num % primeNum == 0)
            {
                return false;
            }
        }
        return true;
    };

    for (int i = 2; i < max; i++)
    {
        if (primeCheck(i, primes))
        {
            primes.push_back(i);
        }
    }
    return primes;
}

void printVector(const std::vector<int> &numVector)
{
    for (int num : numVector)
    {
        std::cout << num << std::endl;
    }
}

int main()
{
    std::vector<int> primesVector = createPrimesVector(100);
    printVector(primesVector);

    return 0;
}