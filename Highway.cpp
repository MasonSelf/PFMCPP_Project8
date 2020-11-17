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

    Car* car = dynamic_cast<Car*>(v);
    if ( car )
        car->closeWindows();
    
    SemiTruck* sT = dynamic_cast<SemiTruck*>(v);
    if (sT )
        sT->closeWindows();

    Motorcycle* m = dynamic_cast<Motorcycle*>(v);
    if ( m )
        m->setSpeed(speedLimit);
}

void Highway::removeVehicleInternal(Vehicle* v)
{
    //assert(false);

    /*
    depending on the derived type, call the member function that tries to evade the cops. 

    trucks pull over, but cars and bikes try to evade!!
    */

    Car* car = dynamic_cast<Car*>(v);
    if ( car )
        car->tryToEvade();

    SemiTruck* sT = dynamic_cast<SemiTruck*>(v);
    if ( sT )
        sT->complientlyPullOver();

    Motorcycle* m = dynamic_cast<Motorcycle*>(v);
    if ( m )
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
