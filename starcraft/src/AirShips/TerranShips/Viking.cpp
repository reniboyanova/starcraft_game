#include "Viking.h"
#include <typeinfo>
#include "Defines.h"

Viking::Viking() : AirShipBase(
                       VIKING_HEALTH,
                       VIKING_DAMAGE)
{
    m_identificator = VIKING;
}
