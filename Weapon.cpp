#include "Weapon.h"

Weapon::Weapon(const std::string &name, const int attackPWR, const double critRate, const Rarity rarity) {
    this->name = name;
    this->attackPWR = attackPWR;
    this->critRate = critRate;
    this->rarity = rarity;
}

Weapon::~Weapon() = default;

int Weapon::getAttackPWR() const {
    return this->attackPWR;
}

double Weapon::getCritRate() const {
    return this->critRate;
}

Rarity Weapon::getRarity() const {
    return this->rarity;
}

std::string Weapon::getName() const {
    return this->name;
}

std::string Weapon::rarityToString(const Rarity r) {
    switch (r) {
        case Common: return "Common";
        case Uncommon: return "Uncommon";
        case Rare: return "Rare";
        case Epic: return "Epic";
        case Legendary: return "*+-+-LEGENDARY-+-+*";
    }
}
