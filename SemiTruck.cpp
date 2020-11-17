#include "SemiTruck.h"
#include "Highway.h"

SemiTruck::SemiTruck(const std::string& n) : Vehicle(n) {}

SemiTruck::~SemiTruck() = default;

void SemiTruck::complientlyPullOver()
{
    std::cout << name << ": s***!" << std::endl;
    setSpeed(0);
}

void SemiTruck::closeWindows()
{
    setSpeed(55);
    std::cout << name << ": closing the windows!" << std::endl;
}
