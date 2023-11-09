#include <iostream>
#include "Terran.h"
#include "Defines.h"
#include "Protoss.h"

void Terran::m_printInformationAboutCurrentShipState() const
{
    int currentHealt = m_airShips.back()->m_getHealth();
    int lastIndex = m_airShips.size() - 1;
    std::cout << "Last Terran AirShip with ID: " << lastIndex << " has " << currentHealt << " health left" << std::endl;
}

void Terran::m_printInformationForKilledEnemy(int currentShipIndex, int enemyIndex) const
{
    std::string airshipType;

    switch (m_airShips[currentShipIndex]->m_identifyShipType())
    {
    case VIKING:
        airshipType = VikingName;
        break;
    case BATTLE_CRUSER:
        airshipType = BattleCruiserName;
        break;
    default:
        airshipType = UnknownName;
        break;
    }

    std::cout << airshipType << " with ID: " << currentShipIndex << " killed enemy airship with ID: " << enemyIndex << std::endl;
}

void terransDmgLogic(char attackerShipType, char attackedShipType, int gameTurn, int &attackDmg)
{
    if (attackerShipType == VIKING && attackedShipType == PHOENIX)
        attackDmg *= 2;
    else if ((attackerShipType == BATTLE_CRUSER) && ((gameTurn + 1) % 10 == 0))
        attackDmg *= 5;
}

void Terran::m_attackProtoss(Protoss &protossFleet, int &gameTurn, bool &gameOn)
{
    int attackDmg = 0;
    char attackerShipType = '\0';
    char attackedShipType = '\0';

    int lastProtossShipToAttakIndex = (protossFleet.m_airShips.size() - 1);
    auto &prottosAttackedShip = protossFleet.m_airShips[lastProtossShipToAttakIndex];

    for (int indexOfCurrentShip = 0; indexOfCurrentShip < m_airShips.size(); ++indexOfCurrentShip)
    {
        if (!gameOn)
            break;

        auto &terranAttackerShip = m_airShips[indexOfCurrentShip];
        prottosAttackedShip = protossFleet.m_airShips[lastProtossShipToAttakIndex];

        attackerShipType = m_airShips[indexOfCurrentShip]->m_identifyShipType();
        attackedShipType = prottosAttackedShip->m_identifyShipType();
        attackDmg = terranAttackerShip->m_getDamageForAttack();

        terransDmgLogic(attackerShipType, attackedShipType, gameTurn, attackDmg);
        prottosAttackedShip->m_receiveDamage(attackDmg);

        if (!(prottosAttackedShip->is_alive()))
        {
            m_printInformationForKilledEnemy(indexOfCurrentShip, lastProtossShipToAttakIndex);
            protossFleet.m_airShips.pop_back();
            if (protossFleet.m_airShips.empty())
            {
                gameOn = false;
                break;
            }

            lastProtossShipToAttakIndex = protossFleet.m_airShips.size() - 1;
        }
    }

    if (protossFleet.m_airShips.size() > 0)
    {
        protossFleet.m_printInformationAboutCurrentShipStateWithShield();
        gameTurn++;
    }
}