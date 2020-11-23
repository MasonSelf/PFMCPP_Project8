#include "Highway.h"
#include "Car.h"
#include "SemiTruck.h"
#include "Motorcycle.h"
#include <cassert>

void Highway::changeSpeed(int newSpeed)
{
    speedLimit = newSpeed;
    for( auto* vehicle : vehicles )
    {
        vehicle->setSpeed(speedLimit);
    }
}

void Highway::addVehicleInternal(Vehicle* v)
{
    //assert(false);
    
    /*
    depending on the derived type, call the member function that doesn't evade the cops. 
    */

    if ( auto* car = dynamic_cast<Car*>(v) )
        car->closeWindows();
    
    else if (auto* sT = dynamic_cast<SemiTruck*>(v) )
        sT->closeWindows();

    else if ( auto* m = dynamic_cast<Motorcycle*>(v) )
        m->lanesplitAndRace( 1000 );
}

void Highway::removeVehicleInternal(Vehicle* v)
{
    //assert(false);

    /*
    depending on the derived type, call the member function that tries to evade the cops. 

    trucks pull over, but cars and bikes try to evade!!
    */

    if ( auto* car = dynamic_cast<Car*>(v) )
        car->tryToEvade();

    else if ( auto* sT = dynamic_cast<SemiTruck*>(v) )
        sT->complientlyPullOver();

    else if ( auto* m = dynamic_cast<Motorcycle*>(v) )
        m->tryToEvade();

}

void Highway::addVehicle(Vehicle* v)
{
    vehicles.push_back(v);
    addVehicleInternal(v);
}
void Highway::removeVehicle(Vehicle* v)
{
    vehicles.erase(std::remove(vehicles.begin(), 
                               vehicles.end(), 
                               v), 
                   vehicles.end());
    removeVehicleInternal(v);
}
