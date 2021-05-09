// 18 . Напишите программу для решения квадратных уравнений. Квадрат­
// ное уравнение имеет вид ах2 + Ь + с = 0 . Если вы не знаете формул для
// решения такого уравнения, проведите дополнительные исследования.
// Напомним, что программисты часто выполняют такие исследования,
// прежде чем приступить к решению задачи . Для ввода чисел а, Ь и с
// используйте переменные типа douЫe. Поскольку квадратное уравне­
// ние имеет два решения, выведите оба значения, xl и х2 .

#include <iostream>
#include <limits>
#include <vector>
#include <cmath>
#include <utility>
#include <tuple>
	

double getNumber()
{
    while (true)
    {
        double number;
        if (std::cin >> number)
        {
            return number;
        }
        std::cout << "\tIncorrect input. Please, try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}


double getDiscriminant(double a, double b, double c)
{
    double discriminant = (b * b) - (4 * a * c);
    return discriminant;
}

std::pair<double, double> equationsSolution(double discriminant, double a, double b, double c)
{
    std::pair<double, double> answer;
    if (discriminant == 0)
    {
        answer.first = -b / 2 * a;
    }
    else if(discriminant > 0)
    {
        answer.first = (-b + sqrt(discriminant))/ (2.0 * a);
        answer.second = (-b - sqrt(discriminant))/ (2.0    * a);
    }
    return answer;
}


void answer(double discriminant,const std::pair<double, double>& answer)
{
    if(discriminant < 0)
    {
        std::cout << "No answer. The discriminant is less than zero." << std::endl;
    }
    else if(discriminant == 0)
    {
        std::cout << "Your answer is " << answer.first;
    }
    else 
    {
        std::cout << "Your answer is " << answer.first << " and " << answer.second << "." << std::endl;
    }
}

void quadraticEquation()
{
    std::cout << "\tThe quadratic equation has the form ax^2 + bx + c = 0" << std::endl;
    std::cout << "\tPlease enter your parameters (a,b,c): " << std::endl;
    double a = getNumber();
    double b = getNumber();
    double c = getNumber();
    double  discriminant = getDiscriminant(a,b,c);
    std::pair<double, double> answerNum = equationsSolution(discriminant, a, b, c);
    answer(discriminant, answerNum);
} 

int main()
{
    quadraticEquation();
    return 0;
}