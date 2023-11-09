#include <iostream>
#include "Protoss.h"
#include "Defines.h"
#include "Terran.h"

void Protoss::m_printInformationAboutCurrentShipStateWithShield() const
{
    int currentHealt = m_airShips.back()->m_getHealth();
    int lastIndex = m_airShips.size() - 1;
    int currentShield = m_airShips.back()->m_getShield();
    std::cout << "Last Protoss AirShip with ID: " << lastIndex << " has " << currentHealt << " health and " << currentShield << " shield left" << std::endl;
}

void Protoss::m_printInformationForKilledEnemy(int currentShipIndex, int enemyIndex) const
{
    std::string airshipType;

    switch (m_airShips[currentShipIndex]->m_identifyShipType())
    {
    case PHOENIX:
        airshipType = PhoenixName;
        break;
    case CARRIER:
        airshipType = CarrierName;
        break;
    default:
        airshipType = UnknownName;
        break;
    }

    std::cout << airshipType << " with ID: " << currentShipIndex << " killed enemy airship with ID: " << enemyIndex << std::endl;
}

void Protoss::m_attackTerrans(Terran &terransFleet, int &gameTurn, bool &gameOn)
{
    int attackDmg = 0;
    char attackerShipType = '\0';
    char attackedShipType = '\0';

    int lastTerransShipToAttakIndex = (terransFleet.m_airShips.size() - 1);
    auto &terranAttackedShip = terransFleet.m_airShips[lastTerransShipToAttakIndex];

    for (int indexOfCurrentShip = 0; indexOfCurrentShip < m_airShips.size(); ++indexOfCurrentShip) // bpbbbp
    {
        if (!gameOn)
            break;

        auto prottosAttackerShip = m_airShips[indexOfCurrentShip];
        terranAttackedShip = terransFleet.m_airShips[lastTerransShipToAttakIndex];

        attackerShipType = m_airShips[indexOfCurrentShip]->m_identifyShipType();
        attackedShipType = terranAttackedShip->m_identifyShipType();
        attackDmg = prottosAttackerShip->m_getDamageForAttack();

        if (attackerShipType != CARRIER)
        {
            m_phoenixAttack(indexOfCurrentShip, terransFleet, gameOn);
        }
        else
        {
            m_carrierAttack(indexOfCurrentShip, terransFleet, gameOn);
        }

        prottosAttackerShip->m_regenerateShield();
    }
    if (terransFleet.m_airShips.size() > 0)
    {
        terransFleet.m_printInformationAboutCurrentShipState();
        gameTurn++;
    }
}

void Protoss::m_phoenixAttack(int i, Terran &terranFleet, bool &gameOn)
{
    int attack = m_airShips[i]->m_getDamageForAttack();
    int lastTerransShipIndex = terranFleet.m_airShips.size() - 1;

    auto &terransLastShip = terranFleet.m_airShips[lastTerransShipIndex];

    terransLastShip->m_receiveDamage(attack);

    if (!(terransLastShip->is_alive()))
    {
        m_printInformationForKilledEnemy(i, lastTerransShipIndex);
        terranFleet.m_airShips.pop_back();

        if (terranFleet.m_airShips.empty())
        {
            gameOn = false;
            return;
        }
        lastTerransShipIndex = terranFleet.m_airShips.size() - 1;
    }
}

void Protoss::m_carrierAttack(int i, Terran &terranFleet, bool &gameOn)
{
    int numberOfCarrierAttacks = 0;
    if (m_airShips[i]->m_getHealth() == CARRIER_HEALTH)
    {
        numberOfCarrierAttacks = MAX_NUMBER_OF_CARRIER_ATTACKS;
    }
    else
    {
        numberOfCarrierAttacks = NUMBER_OF_CARRIER_ATTACKS_WITH_NOT_FULL_HEALTH;
    }

    for (int attackCounter = 0; attackCounter < numberOfCarrierAttacks; ++attackCounter)
    {
        int attack = m_airShips[i]->m_getDamageForAttack();
        int lastTerransShipIndex = terranFleet.m_airShips.size() - 1;

        auto &terransLastShip = terranFleet.m_airShips[lastTerransShipIndex];

        terransLastShip->m_receiveDamage(attack);

        if (!(terransLastShip->is_alive()))
        {
            m_printInformationForKilledEnemy(i, lastTerransShipIndex);
            terranFleet.m_airShips.pop_back();

            if (terranFleet.m_airShips.empty())
            {
                gameOn = false;
                break;
            }
            else
            {
                lastTerransShipIndex = terranFleet.m_airShips.size() - 1;
                terransLastShip = terranFleet.m_airShips[lastTerransShipIndex];
            }
        }
    }
}
