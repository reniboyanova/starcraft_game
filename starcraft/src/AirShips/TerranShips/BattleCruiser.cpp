#include "BattleCruiser.h"
#include "Defines.h"

BattleCruiser::BattleCruiser() : AirShipBase(
									 BATTLE_CRUSER_HEALTH,
									 BATTLE_CRUSER_DAMAGE)
{
	m_identificator = BATTLE_CRUSER;
}
