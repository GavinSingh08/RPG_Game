#ifndef RPG_GAME_ENEMY_H
#define RPG_GAME_ENEMY_H

#include <iostream>

enum EnemyType {
    Slime,
    Ogre,
    Giant,
    Skeleton,
    Dragon
};

class Enemy {
private:
    std::string name;
    int maxHP;
    int currentHP;
    int attackPWR;
    int defensePWR; //TODO: add implementation for damage neg later
    bool alive;
    int level; //TODO add leveling implementation
    EnemyType type;

public:
    Enemy(std::string name, int maxHP, int attackPWR, int defensePWR, int level, EnemyType type);
    virtual ~Enemy();

    bool isAlive();
    void takeDamage(int damage);
    [[nodiscard]] int attack() const;

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getCurrentHP() const;
    [[nodiscard]] int getMaxHP() const;
    [[nodiscard]] int getDefensePWR() const;
    [[nodiscard]] int getAttackPWR() const;
    [[nodiscard]] int getLevel() const;
    [[nodiscard]] EnemyType getType() const;

    void setCurrentHP(int _currentHP);
    void setMaxHP(int _maxHP);
    void setDefensePWR(int _defensePWR);
    void setAttackPWR(int _attackPWR);
    void setName(const std::string &_name);
    void setAlive(bool _alive);
    void setLevel(int _level);
    void displayHPString() const;

};


#endif //RPG_GAME_ENEMY_H