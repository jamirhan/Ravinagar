cmake_minimum_required(VERSION 3.0)
set(PROJECT_NAME "Ravinagar")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

#Set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2 -Wall -Wextra")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(HEADERS src/Environment.h
        src/Coins/Builder/CoinsBuilder.h
        src/Game/GameStat.h
        src/Game/Game.h
        src/Game/Config.h;
        src/Units/Unit.h
        src/Message.h
        src/Graph.h
        src/Commutator.h
        src/Traps/Trap.h
        src/Traps/TrapsComposer.h
        src/Traps/Builder/TrapFactory.h
        src/Traps/Builder/TrapsBuilder.h
        src/Traps/Builder/CloneCreator.h
        src/Traps/Builder/GraphCatcherCreator.h
        src/Traps/Builder/MineCreator.h
        src/Coins/Coin.h
        src/Player.h
        src/Server.h
        src/Coins/Types/AntiCoin.h
        src/Coins/Types/ClassicCoin.h
        src/Coins/Types/SuperCoin.h
        src/Coins/Builder/CoinsFactory.h
        src/Coins/Builder/AntiCoinCreator.h
        src/Coins/Builder/ClassicCoinCreator.h
        src/Coins/Builder/SuperCoinCreator.h
        src/Point.h
        src/Coins/CoinsComposer.h
        src/Units/UnitsComposer.h
        src/GraphsComposer.h
        src/Poly.h
        )

set(SOURCES
        src/Message.cpp
        src/Game/GameStat.cpp
        src/Server.cpp
        src/Commutator.cpp
        src/Environment.cpp
        src/Game/Game.cpp
        src/Game/Config.cpp;
        src/Coins/Types/AntiCoin.cpp
        src/Coins/Types/ClassicCoin.cpp
        src/Coins/Types/SuperCoin.cpp
        src/Coins/Builder/CoinsBuilder.cpp
        src/Coins/Builder/AntiCoinCreator.cpp
        src/Coins/Builder/ClassicCoinCreator.cpp
        src/Coins/Builder/SuperCoinCreator.cpp
        src/Point.cpp
        src/Player.cpp
        src/Coins/Coin.cpp
        src/Coins/CoinsComposer.cpp
        src/GraphsComposer.cpp
        src/Poly.cpp
        src/Graph.cpp
        src/Traps/Trap.cpp
        src/Traps/TrapsComposer.cpp
        src/Traps/Builder/TrapFactory.cpp
        src/Traps/Builder/TrapsBuilder.cpp
        src/Traps/Builder/CloneCreator.cpp
        src/Traps/Builder/GraphCatcherCreator.cpp
        src/Traps/Builder/MineCreator.cpp
        src/Units/UnitsComposer.cpp
        src/Units/Unit.cpp
        )

include_directories(
        ${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Coins
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Coins/Builder
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Coins/Types
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Units
)

include_directories("root_finder")

set(client_headers
        src/Client/Client.h)

set(client_sources
        src/Client/Client.cpp)

set(BOOST_ROOT boost_1_71_0)
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
set(GSL_ROOT_DIR "gsl-2.6")
find_package(Boost 1.71.0 REQUIRED)
find_package(Qt5 COMPONENTS Network Widgets Core Gui REQUIRED)
#find_package(GSL REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
#include_directories(${GSL_INCLUDE_DIR})
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} src/main.cpp)
add_executable(Client ${client_headers} ${client_sources} src/Client/main.cpp)
#target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} GSL::gsl GSL::gslcblas)

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

target_link_libraries(${PROJECT_NAME} PUBLIC
        Qt5::Network Qt5::Widgets Qt5::Core Qt5::Gui)

target_link_libraries(Client PUBLIC
        Qt5::Network Qt5::Widgets Qt5::Core Qt5::Gui)
