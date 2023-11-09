#include "AirShipWithShield.h"
#include <typeinfo>
#include <iostream>

AirShipWithShield::AirShipWithShield()
    : AirShipBase(), m_shield(0)
{
}

AirShipWithShield::AirShipWithShield(
    int health, int damage, int shield, int maxShield, int shieldRegenerateRate)
    : AirShipBase(health, damage), m_shield(shield), m_maxShield(maxShield), m_shieldRegenerateRate(shieldRegenerateRate)
{
}

void AirShipWithShield::m_regenerateShield()
{
    m_shield += m_shieldRegenerateRate;
    if (m_shield > m_maxShield)
    {
        m_shield = m_maxShield;
    }
}

void AirShipWithShield::m_receiveDamage(int receivedDamage)
{
    m_shield -= receivedDamage;
    if (m_shield < 0)
    {
        AirShipBase::m_receiveDamage(-m_shield);
        m_shield = 0;
    }
}
