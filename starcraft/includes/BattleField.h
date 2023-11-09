#ifndef BATTLEFIELD_H_
#define BATTLEFIELD_H_

#include <string>
#include "Protoss.h"
#include "Terran.h"

class BattleField
{

public:
  void generateTerranFleet(const std::string &terranFleetComposition, Terran &terranFleet);
  void generateProtossFleet(const std::string &protossFleetCompositon, Protoss &protossFleet);

  void startBattle(Protoss &protossFleet, Terran &terranFleet);
};

#endif