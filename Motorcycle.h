#pragma once
#include "Vehicle.h"
#include <iostream>
#include <limits>

struct Motorcycle : Vehicle
{
    Motorcycle(const std::string& n);

    virtual ~Motorcycle() override;
    Motorcycle(const Motorcycle&) = default;
    Motorcycle& operator=(const Motorcycle&) = default;
    
    void lanesplitAndRace( int topSpeed = std::numeric_limits<int>::max() );
    
    void tryToEvade() override;

    void setSpeed(int s) override;
};
