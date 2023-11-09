#ifndef TERRAN_H
#define TERRAN_H

#include "AirShipBase.h"
#include <vector>
#include <memory>

class Protoss;

class Terran
{

public:
    // Terran() {}
    // ~Terran() {}
    std::vector<std::shared_ptr<AirShipBase>> m_airShips;
    bool m_hasShipsInFleet = true;
    void m_printInformationAboutCurrentShipState() const;
    void m_printInformationForKilledEnemy(int currentShipIndex, int enemyIndex) const;
    void m_attackProtoss(Protoss &protossFleet, int &gameTurn, bool &gameOn);
};

#endif
