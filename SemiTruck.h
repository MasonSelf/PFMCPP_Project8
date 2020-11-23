#pragma once
#include "Vehicle.h"
#include <iostream>
#include <limits>

struct SemiTruck :  Vehicle 
{
    SemiTruck(const std::string& n);
    
    virtual ~SemiTruck() override;
    SemiTruck(const SemiTruck&) = default;
    SemiTruck& operator=(const SemiTruck&) = default;

    void complientlyPullOver();
    void closeWindows();
};
