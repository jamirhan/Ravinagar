cmake_minimum_required(VERSION 3.0)
set(PROJECT_NAME "Ravinagar")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

# execute_process(
#     COMMAND mkdir ${CMAKE_CURRENT_SOURCE_DIR}/bin
# )

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(HEADERS src/Environment.h
        src/Coins/Builder/CoinsBuilder.h
        src/Game/GameStat.h
        src/Game/Game.h
        src/Units/Unit.h
        src/Message.h
        src/Graph.h
        src/tools.h
        src/Commutator.h
        src/Traps/Trap.h
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
)

set(SOURCES
        src/Message.cpp
        src/Game/GameStat.cpp
        src/Server.cpp
        src/Commutator.cpp
        src/Environment.cpp
        src/Game/Game.cpp
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
