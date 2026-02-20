cmake_minimum_required(VERSION 4.1)
project(RPG_Game)

set(CMAKE_CXX_STANDARD 23)

add_executable(RPG_Game main.cpp
        Player.cpp
        Player.h
        Enemy.cpp
        Enemy.h
        Weapon.cpp
        Weapon.h
        Item.cpp
        Item.h
        Inventory.cpp
        Inventory.h
        LevelStage.cpp
        LevelStage.h
        Game.cpp
        Game.h
        Colors.h)
