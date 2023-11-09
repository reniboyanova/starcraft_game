#ifndef AIRSHIP_WITH_SHIELD_H
#define AIRSHIP_WITH_SHIELD_H

#include "AirShipBase.h"

class AirShipWithShield : public AirShipBase
{
protected:
    int m_shield;
    int m_maxShield;
    int m_shieldRegenerateRate;

public:
    AirShipWithShield();
    AirShipWithShield(int health, int damage, int shield, int maxShield, int shieldRegenerateRate);

    void m_receiveDamage(int receivedDamage) override;
    void m_regenerateShield();
    int m_getShield() const { return m_shield; };
};

#endif