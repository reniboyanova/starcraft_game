cmake_minimum_required(VERSION 3.5.1)

project(starcraft)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers_c.cmake)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SOURCES
        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/BattleField.cpp
        ${SRC_DIR}/AirShips/TerranShips/BattleCruiser.cpp
        ${SRC_DIR}/AirShips/TerranShips/Viking.cpp
        ${SRC_DIR}/AirShips/AirShipBase.cpp
        ${SRC_DIR}/AirShips/AirShipWithShield.cpp
        ${SRC_DIR}/AirShips/ProtossShips/Phoenix.cpp
        ${SRC_DIR}/AirShips/ProtossShips/Carrier.cpp
        ${SRC_DIR}/Races/Terran/Terran.cpp
        ${SRC_DIR}/Races/Protoss/Protoss.cpp
    )


add_executable(${PROJECT_NAME}
               ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE includes)