#include "Enemy.h"
#include "Colors.h"

Enemy::Enemy(std::string name, const int maxHP, const int attackPWR, const int defensePWR, const int level, EnemyType type) {
    this->name = std::move(name);
    this->maxHP = maxHP;
    this->currentHP = maxHP;
    this->attackPWR = attackPWR;
    this->defensePWR = defensePWR;
    this->alive = true;
    this->level = level;
    this->type = type;
}

Enemy::~Enemy() = default;

bool Enemy::isAlive() {
    if (this->currentHP <= 0) {
        setAlive(false);
        return false;
    }
    setAlive(true);
    return true;
}

void Enemy::takeDamage(const int damage) {
    setCurrentHP(getCurrentHP() - damage);
}

int Enemy::attack() const {
    return attackPWR * this->level;
}

void Enemy::displayHPString() const {
    if (currentHP <= 0) {
        std::cout << Colors::RED << this->name << " | 0/" << this->maxHP << Colors::RESET << std::endl;
    } else if (currentHP <= maxHP / 2) {
        std::cout << Colors::YELLOW << this->name << " | " << this->currentHP << "/" << this->maxHP << Colors::RESET << std::endl;
    } else {
        std::cout << Colors::GREEN << this->name << " | " << this->currentHP << "/" << this->maxHP << Colors::RESET << std::endl;
    }
}

//getters

std::string Enemy::getName() const {
    return this->name;
}

int Enemy::getCurrentHP() const {
    return this->currentHP;
}

int Enemy::getMaxHP() const {
    return this->maxHP;
}

int Enemy::getDefensePWR() const {
    return this->defensePWR;
}

int Enemy::getAttackPWR() const {
    return this->attackPWR;
}

int Enemy::getLevel() const {
    return this->level;
}

EnemyType Enemy::getType() const {
    return this->type;
}

//setters

void Enemy::setCurrentHP(const int _currentHP) {
    this->currentHP = _currentHP;
}

void Enemy::setMaxHP(const int _maxHP) {
    this->maxHP = _maxHP;
}

void Enemy::setDefensePWR(const int _defensePWR) {
    this->defensePWR = _defensePWR;
}

void Enemy::setAttackPWR(const int _attackPWR) {
    this->attackPWR = _attackPWR;
}

void Enemy::setName(const std::string &_name) {
    this->name = _name;
}

void Enemy::setAlive(const bool _alive) {
    this->alive = _alive;
}

void Enemy::setLevel(const int _level) {
    this->level = _level;
}
