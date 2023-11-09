#include "Phoenix.h"
#include "Defines.h"

Phoenix::Phoenix() : AirShipWithShield(
                         PHOENIX_HEALTH,
                         PHOENIX_DAMAGE,
                         PHOENIX_SHIELD,
                         PHOENIX_SHIELD,
                         PHOENIX_SHIELD_REGENERATE_RATE)
{
    m_identificator = PHOENIX;
}