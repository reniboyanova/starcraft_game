#include "AirShipBase.h"

AirShipBase::AirShipBase()
    : m_health(0), m_damage(0)
{
}

AirShipBase::AirShipBase(int health, int damage)
    : m_health(health), m_damage(damage)
{
}

void AirShipBase::m_receiveDamage(int receivedDamage)
{
    m_health -= receivedDamage;
    if (m_health < 0)
    {
        m_health = 0;
    }
}

int AirShipBase::m_getHealth() const
{
    return m_health;
}