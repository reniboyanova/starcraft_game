#ifndef CARRIER_H
#define CARRIER_H

#include "AirShipWithShield.h"

class Carrier : public AirShipWithShield
{
private:
    bool isDead = false;

public:
    Carrier();
};

#endif