#ifndef PROTOSS_H
#define PROTOSS_H

#include "AirShipWithShield.h"
#include <vector>
#include <memory>

class Terran;

class Protoss
{
public:
    Protoss() {}
    ~Protoss() {}
    std::vector<std::shared_ptr<AirShipWithShield>> m_airShips;
    bool m_hasShipsInFleet = true;
    void m_printInformationAboutCurrentShipStateWithShield() const;
    void m_printInformationForKilledEnemy(int currentShipIndex, int enemyIndex) const;
    void m_phoenixAttack(int i, Terran &terranFleet, bool &gameOn);
    void m_carrierAttack(int i, Terran &terranFleet, bool &gameOn);

    void m_attackTerrans(Terran &terransFleet, int &gameTurn, bool &gameOn);
};

#endif
