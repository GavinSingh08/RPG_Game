#ifndef RPG_GAME_WEAPON_H
#define RPG_GAME_WEAPON_H
#include <string>

enum Rarity {
    Common,
    Uncommon,
    Rare,
    Epic,
    Legendary
};

class Weapon {
private:
    std::string name;
    int attackPWR;
    double critRate;
    Rarity rarity;

public:
    Weapon(const std::string &name, int attackPWR, double critRate, Rarity rarity);
    virtual ~Weapon();
    [[nodiscard]] int getAttackPWR() const;
    [[nodiscard]] double getCritRate() const;
    [[nodiscard]] Rarity getRarity() const;
    [[nodiscard]] std::string getName() const;

    std::string rarityToString(Rarity r);
};


#endif //RPG_GAME_WEAPON_H