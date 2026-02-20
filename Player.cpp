#include "Player.h"
#include "Item.h"
#include "Weapon.h"

//TODO view stats summary so user can see stats

Player::Player(const std::string &name, const int maxHP, const int attackPWR, const int defensePWR)
    : currentWeapon("Simple sword", 5, 0.05, Common) {
    this->name = name;
    this->maxHP = maxHP;
    this->currentHP = maxHP;
    this->attackPWR = attackPWR;
    this->defensePWR = defensePWR;
    this->alive = true;
    this->level = 1; //TODO add leveling system
    equipWeapon(currentWeapon);
}

Player::~Player() = default;

bool Player::isAlive() {
    if (this->currentHP <= 0) {
        setAlive(false);
        return false;
    }
    setAlive(true);
    return true;
}

void Player::takeDamage(const int damage) {
    setCurrentHP(getCurrentHP() - damage);
}

void Player::heal(const int healAmount) {
    setCurrentHP(getCurrentHP() + healAmount);
}

int Player::attack() const {
    return attackPWR * this->level;
}

void Player::displayHPString() const {
    if (currentHP < 0) {
        std::cout << this->name << " | 0/" << this->maxHP << std::endl;
    } else {
        std::cout << this->name << " | " << this->currentHP << "/" << this->maxHP << std::endl;
    }
}

void Player::equipWeapon(const Weapon& _weapon) {   //TODO fix this implementation, currently can stack attckpwr
    if (this->currentWeapon.getName() != _weapon.getName()) {
        setAttackPWR(getAttackPWR() - currentWeapon.getAttackPWR());
        setAttackPWR(getAttackPWR() + _weapon.getAttackPWR());
        currentWeapon = _weapon;
    }
}

void Player::useItem(const Item& _item) {
    switch (_item.getType()) {
        case Healing:

            if (getCurrentHP() + 20 > this->getMaxHP()) {
                setCurrentHP(getMaxHP());
            } else {
                this->setCurrentHP(getCurrentHP() + 20);
            }

            std::cout << "Healed! ";
            displayHPString();
            break;
        case Strength_Buff:
            this->setAttackPWR(getAttackPWR() + 5);
            std::cout << "Strength Buff! Attack PWR now " << this->getAttackPWR() << std::endl;
            break;
        case Health_Buff:
            this->setMaxHP(getMaxHP() + 20);
            this->setCurrentHP(getCurrentHP() + 20);
            std::cout << "Health Buff! Max HP now " << this->getMaxHP() << std::endl;
            break;
        case Key_Item:
            std::cout << "Key Item! You can't use this!";
            break;
    }
}

void Player::viewStats() {
    std::cout << "––––––PLAYER STATS–––––––" << std::endl;
    displayHPString();
    std::cout << "Attack PWR: " << this->getAttackPWR() << std::endl;
    std::cout << "Defense PWR: " << this->getDefensePWR() << std::endl;
    std::cout << "Level: " << this->getLevel() << std::endl;
    std::cout << "Current Weapon: " << this->currentWeapon.getName() << " | Attack PWR: " <<
        this->currentWeapon.getAttackPWR() << " | Crit Rate: " <<this->currentWeapon.getCritRate()*100 << "% | Rarity: " <<
            this->currentWeapon.rarityToString(this->currentWeapon.getRarity()) << std::endl;
}

//getters

std::string Player::getName() {
    return this->name;
}

int Player::getCurrentHP() const {
    return this->currentHP;
}

int Player::getMaxHP() const {
    return this->maxHP;
}

int Player::getDefensePWR() const {
    return this->defensePWR;
}

int Player::getAttackPWR() const {
    return this->attackPWR;
}

int Player::getLevel() const {
    return this->level;
}

//setters

void Player::setCurrentHP(const int _currentHP) {
    this->currentHP = _currentHP;
}

void Player::setMaxHP(const int _maxHP) {
    this->maxHP = _maxHP;
}

void Player::setDefensePWR(const int _defensePWR) {
    this->defensePWR = _defensePWR;
}

void Player::setAttackPWR(const int _attackPWR) {
    this->attackPWR = _attackPWR;
}

void Player::setName(const std::string &_name) {
    this->name = _name;
}

void Player::setAlive(const bool _alive) {
    this->alive = _alive;
}

void Player::setLevel(const int _level) {
    this->level = _level;
}
