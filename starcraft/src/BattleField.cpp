#include "BattleField.h"
#include "Terran.h"
#include "Protoss.h"
#include "Viking.h"
#include "BattleCruiser.h"
#include "Carrier.h"
#include "Phoenix.h"
#include "Defines.h"
#include <memory>
#include <stdexcept>
#include <iostream>

using stringComposition = const std::string;

void BattleField::generateTerranFleet(stringComposition &terranFleetComposition, Terran &terranFleet)
{
    for (size_t i = 0; i < terranFleetComposition.size(); i++)
    {
        char shipType = terranFleetComposition[i];
        if (shipType == VIKING)
        {
            terranFleet.m_airShips.push_back(std::make_shared<Viking>());
        }
        else if (shipType == BATTLE_CRUSER)
        {
            terranFleet.m_airShips.push_back(std::make_shared<BattleCruiser>());
        }
        else
        {
            throw std::invalid_argument(INVALID_SHIP_TYPE_FOR_TERRAN_FLEET);
        }
    }
}

void BattleField::generateProtossFleet(stringComposition &protossFleetCompositon, Protoss &protossFleet)
{
    for (size_t i = 0; i < protossFleetCompositon.size(); i++)
    {
        char shipType = tolower(protossFleetCompositon[i]);
        if (shipType == PHOENIX)
        {
            protossFleet.m_airShips.push_back(std::make_shared<Phoenix>());
        }
        else if (shipType == CARRIER)
        {
            protossFleet.m_airShips.push_back(std::make_shared<Carrier>());
        }
        else
        {
            throw std::invalid_argument(INVALID_SHIP_TYPE_FOR_PROTOSS_FLEET);
        }
    }
}

void announceBattleResult(Terran &terranFleet, Protoss &protossFleet)
{
    if (terranFleet.m_airShips.empty())
        std::cout << "PROTOSS has won!" << std::endl;
    else if (protossFleet.m_airShips.empty())
        std::cout << "TERRAN has won!" << std::endl;
}

void BattleField::startBattle(Protoss &protossFleet, Terran &terranFleet)
{
    int gameTurn = 1;
    bool gameOn = !(protossFleet.m_airShips.empty()) || !(terranFleet.m_airShips.empty());

    // int attackedIndexProtoss = 0;
    // int attackedIndexTerran = 0;

    while (gameOn)
    {
        if (gameTurn % 2 != 0)
        {
            terranFleet.m_attackProtoss(protossFleet, gameTurn, gameOn);
        }
        else
        {
            protossFleet.m_attackTerrans(terranFleet, gameTurn, gameOn);
        }

        if (protossFleet.m_airShips.empty() || terranFleet.m_airShips.empty())
            gameOn = false;
    }
    announceBattleResult(terranFleet, protossFleet);
}