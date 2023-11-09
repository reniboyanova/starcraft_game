#ifndef PHOENIX_H
#define PHOENIX_H

#include "AirShipWithShield.h"

class Phoenix : public AirShipWithShield
{
private:
    bool isDead = false;

public:
    Phoenix();
};

#endif