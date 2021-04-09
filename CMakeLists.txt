cmake_minimum_required(VERSION 3.0)
set(PROJECT_NAME "Ravinagar")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2 -Wall -Wextra")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

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
        src/Traps/Types/Clone.h
        src/Traps/Types/GraphCatcher.h
        src/Traps/Types/Mine.h
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
        src/Traps/Types/Clone.cpp
        src/Traps/Types/GraphCatcher.cpp
        src/Traps/Types/Mine.cpp
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

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} src/main.cpp)
