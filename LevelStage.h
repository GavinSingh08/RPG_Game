#ifndef RPG_GAME_LEVELSTAGE_H
#define RPG_GAME_LEVELSTAGE_H


class LevelStage {
private:
    int levelNumber;
    int numEnemies;
    double enemyHPScale;
    double enemyAttackScale;
    double lootLevel; //0-4 to represent rarities
    double rareLootPercentage; //percent for rare loot (one higher level than lootLevel),
                                            //meaning you can get legendary gear from epic levels
    double xpRatePercent; //0-1 to represent xp multiplier, 1 for 100% extra xp gain, so double xp

public:
    LevelStage(int levelNumber, double lootLevel, double rareLootPercentage, double xpRate, int numEnemies,
        double enemyHPScale, double enemyAttackScale);
    ~LevelStage();

    [[nodiscard]] int getLevelNumber() const;
    [[nodiscard]] int getNumEnemies() const;
    [[nodiscard]] double getLootLevel() const;
    [[nodiscard]] double getRareLootPercentage() const;
    [[nodiscard]] double getXpRate() const;
    [[nodiscard]] double getEnemyHPScale() const;
    [[nodiscard]] double getEnemyAttackScale() const;

    void setLevelNumber(int _levelNumber);
    void setNumEnemies(int _numEnemies);
    void setLootLevel(double _lootLevel);
    void setRareLootPercentage(double _rareLootPercentage);
    void setXpRate(double _xpRate);
    void setEnemyHPScale(double _enemyHPScale);
    void setEnemyAttackScale(double _enemyAttackScale);

};


#endif //RPG_GAME_LEVELSTAGE_H