#ifndef AIRSHIP_BASE_H
#define AIRSHIP_BASE_H

class AirShipBase
{
protected:
    int m_health = 0;
    int m_damage = 0;
    char m_identificator = '\0';

public:
    AirShipBase();
    AirShipBase(int health, int damage);

    virtual void m_receiveDamage(int receivedDamage);
    int m_getDamageForAttack() const { return m_damage; }
    int m_getHealth() const;
    char m_identifyShipType() const { return m_identificator; }
    bool is_alive() const { return m_health > 0; }
};

#endif
