#include "Carrier.h"
#include "Defines.h"

Carrier::Carrier() : AirShipWithShield(
                         CARRIER_HEALTH,
                         CARRIER_DAMAGE,
                         CARRIER_SHIELD,
                         CARRIER_SHIELD,
                         CARRIER_SHIELD_REGENERATE_RATE)
{
    m_identificator = CARRIER;
}