#ifndef RPG_GAME_PLAYER_H
#define RPG_GAME_PLAYER_H

#include <iostream>

#include "Item.h"
#include "Weapon.h"

class Player {
private:
    std::string name;
    int currentHP;
    int maxHP;
    int attackPWR;
    int defensePWR; //TODO: add implementation for damage neg later
    bool alive;
    int level; //TODO add leveling implementation
    Weapon currentWeapon;

public:
    Player(const std::string &name, int maxHP, int attackPWR, int defensePWR);
    virtual ~Player();

    bool isAlive();
    void takeDamage(int damage);
    void heal(int healAmount);
    [[nodiscard]] int attack() const;
    void displayHPString() const;
    void equipWeapon(const Weapon &_weapon);
    void useItem(const Item &_item);
    void viewStats();

    //get and setters
    std::string getName();
    [[nodiscard]] int getCurrentHP() const;
    [[nodiscard]] int getMaxHP() const;
    [[nodiscard]] int getDefensePWR() const;
    [[nodiscard]] int getAttackPWR() const;
    [[nodiscard]] int getLevel() const;

    void setCurrentHP(int _currentHP);
    void setMaxHP(int _maxHP);
    void setDefensePWR(int _defensePWR);
    void setAttackPWR(int _attackPWR);
    void setName(const std::string &_name);
    void setAlive(bool _alive);
    void setLevel(int _level);

};


#endif //RPG_GAME_PLAYER_H