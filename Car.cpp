#include "Car.h"
//#include "Vehicle.h"
#include <iostream>

Car::Car(const std::string& n) : Vehicle(n) {}

Car::~Car() = default;

void Car::closeWindows()
{
    setSpeed(70);
    std::cout << name << ": closing the windows!" << std::endl;
}

void Car::tryToEvade()
{
    setSpeed(0);
    std::cout << name << ": hello officer, what seems to be the problem?" << std::endl;
}
