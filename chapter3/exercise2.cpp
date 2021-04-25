// Напишите на языке С++ программу, которая преобразует мили в ки­
// лометры . Ваша программа должна содержать понятное приглаше­
// ние пользователю ввести количество миль. Указание: в одной миле
// 1 .609 км.

#include <iostream>

int main()
{
    double miles; 
    double kilometers;    
    std::cout << "Enter the number of miles  and press 'enter': \n ";
    std::cin >> miles;
    kilometers = miles / 1.609;
    std::cout << "In " << miles <<" mile " << kilometers <<  " kilometers.\n ";
    return 0;
}