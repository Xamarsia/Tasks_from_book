// 15. Напишите программу, принимающую на вход число n и находящую
// первые n простых чисел.

#include <iostream>
#include <vector>
#include <limits>

int getNumber()
{
    while (true)
    {   
        int number;
        std::cout << "Enter the number of prime numbers: " << std::endl;
        if (std::cin >> number)
        {
            return number;
        }
        std::cout << "\tIncorrect input. Please, try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');         // skip bad input
    }
}


std::vector<int> createPrimesVector(int count)
{
    std::vector<int> primes = {2};

    auto primeCheck =
        [](int num, const std::vector<int> &primes) {
            for (int primeNum : primes)
            {
                if (num % primeNum == 0)
                {
                    return false;
                }
            }
            return true;
        };

    for (int i = 2; primes.size() < count; i++)
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
    int count = getNumber();
    std::vector<int> primesVector = createPrimesVector(count);
    printVector(primesVector);

    return 0;
}
