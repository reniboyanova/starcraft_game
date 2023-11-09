#ifndef DEFINES_H_
#define DEFINES_H_
#include <string>

enum AirShipDefines
{
  BATTLE_CRUSER_HEALTH = 450,
  BATTLE_CRUSER_DAMAGE = 40,

  VIKING_HEALTH = 150,
  VIKING_DAMAGE = 15,

  CARRIER_HEALTH = 200,
  CARRIER_SHIELD = 150,
  CARRIER_DAMAGE = 8,
  CARRIER_SHIELD_REGENERATE_RATE = 40,

  PHOENIX_HEALTH = 90,
  PHOENIX_SHIELD = 90,
  PHOENIX_DAMAGE = 20,
  PHOENIX_SHIELD_REGENERATE_RATE = 20
};

const char PHOENIX = 'p';
const char CARRIER = 'c';
const char VIKING = 'v';
const char BATTLE_CRUSER = 'b';

const std::string VikingName = "Viking";
const std::string PhoenixName = "Phoenix";
const std::string BattleCruiserName = "BattleCruser";
const std::string CarrierName = "Carrier";
const std::string UnknownName = "Unknown";

const std::string INVALID_SHIP_TYPE_FOR_PROTOSS_FLEET = "Invalid ship type for Protoss fleet!";
const std::string INVALID_SHIP_TYPE_FOR_TERRAN_FLEET = "Invalid ship type for Terran fleet!";

const std::string EMPTY_FLEET_MSG = "One of the fleets is empty! Cant start the battle!";

enum CarrierDefines
{
  MAX_NUMBER_OF_CARRIER_ATTACKS = 8,
  NUMBER_OF_CARRIER_ATTACKS_WITH_NOT_FULL_HEALTH = 4
};

enum BattleCruserDefines
{
  YAMATO_CANNON_LOADING_TURNS = 4
};

#endif
