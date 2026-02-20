#include "LevelStage.h"

LevelStage::LevelStage(const int levelNumber, const double lootLevel, const double rareLootPercentage, const double xpRate,
    const int numEnemies, const double enemyHPScale, const double enemyAttackScale) {

    this->levelNumber = levelNumber;
    this->lootLevel = lootLevel;
    this->rareLootPercentage = rareLootPercentage;
    this->xpRatePercent = xpRate;
    this->numEnemies = numEnemies;
    this->enemyHPScale = enemyHPScale;
    this->enemyAttackScale = enemyAttackScale;
}

LevelStage::~LevelStage() = default;

//getters

int LevelStage::getLevelNumber() const {
    return this->levelNumber;
}

int LevelStage::getNumEnemies() const {
    return this->numEnemies;
}

double LevelStage::getLootLevel() const {
    return this->lootLevel;
}

double LevelStage::getRareLootPercentage() const {
    return this->rareLootPercentage;
}

double LevelStage::getXpRate() const {
    return this->xpRatePercent;
}

double LevelStage::getEnemyHPScale() const {
    return this->enemyHPScale;
}

double LevelStage::getEnemyAttackScale() const {
    return this->enemyAttackScale;
}

//setters

void LevelStage::setLevelNumber(int _levelNumber) {
    this->levelNumber = _levelNumber;
}

void LevelStage::setNumEnemies(int _numEnemies) {
    this->numEnemies = _numEnemies;
}

void LevelStage::setLootLevel(double _lootLevel) {
    this->lootLevel = _lootLevel;
}

void LevelStage::setRareLootPercentage(double _rareLootPercentage) {
    this->rareLootPercentage = _rareLootPercentage;
}

void LevelStage::setXpRate(double _xpRate) {
    this->xpRatePercent = _xpRate;
}

void LevelStage::setEnemyHPScale(double _enemyHPScale) {
    this->enemyHPScale = _enemyHPScale;
}

void LevelStage::setEnemyAttackScale(double _enemyAttackScale) {
    this->enemyAttackScale = _enemyAttackScale;
}
