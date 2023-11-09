#include <iostream>
#include "BattleField.h"
#include "BattleCruiser.h"
#include "Viking.h"
#include "Defines.h"

int main()
{
	std::string terranFleetComposition;
	std::string protossFleetCompositon;

	std::cin >> terranFleetComposition >> protossFleetCompositon;

	if (!protossFleetCompositon.empty() && !terranFleetComposition.empty())
	{
		Protoss protossFleet;
		Terran terranFleet;
		BattleField battleField;
		battleField.generateTerranFleet(terranFleetComposition, terranFleet);
		battleField.generateProtossFleet(protossFleetCompositon, protossFleet);
		battleField.startBattle(protossFleet, terranFleet);
	}
	else
	{
		throw std::invalid_argument(EMPTY_FLEET_MSG);
	}

	return EXIT_SUCCESS;
}
