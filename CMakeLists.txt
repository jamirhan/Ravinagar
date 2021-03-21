cmake_minimum_required(VERSION 3.0)
set(PROJECT_NAME "Ravinagar")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

set(HEADERS include/Environment.h
        include/EnvironmentBuilder.h
        include/Game.h
        include/CoinsFactory.h
        include/AntiCoinCreator.h
        include/ClassicCoinCreator.h
        include/SuperCoinCreator.h
        include/TrapsBuilder.h
        include/TrapFactory.h
        include/GraphCatcherCreator.h
        include/MineCreator.h
        include/CloneCreator.h
        include/Unit.h
        include/Spy.h
        include/Farmer.h
        include/BestFriend.h
        include/CCTV.h
        include/Message.h
        include/Graph.h
        include/Commutator.h
        include/Point.h
        include/Trap.h
        include/GraphCatcher.h
        include/Mine.h
        include/Clone.h
        include/Coin.h
        include/ClassicCoin.h
        include/AntiCoin.h
        include/SuperCoin.h
        include/Player.h)

set(SOURCES src/Environment.cpp
        src/EnvironmentBuilder.cpp
        src/Game.cpp
        src/CoinsFactory.cpp
        src/AntiCoinCreator.cpp
        src/ClassicCoinCreator.cpp
        src/SuperCoinCreator.cpp
        src/TrapsBuilder.cpp
        src/TrapFactory.cpp
        src/GraphCatcherCreator.cpp
        src/MineCreator.cpp
        src/CloneCreator.cpp
        src/Unit.cpp
        src/Spy.cpp
        src/Farmer.cpp
        src/BestFriend.cpp
        src/CCTV.cpp
        src/Message.cpp
        src/Graph.cpp
        src/Commutator.cpp
        src/Point.cpp
        src/Trap.cpp
        src/GraphCatcher.cpp
        src/Mine.cpp
        src/Clone.cpp
        src/Coin.cpp
        src/ClassicCoin.cpp
        src/AntiCoin.cpp
        src/SuperCoin.cpp
        src/Player.cpp)

include_directories(src, include)
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} src/main.cpp)
