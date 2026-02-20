#ifndef RPG_GAME_GAME_H
#define RPG_GAME_GAME_H
#include "Enemy.h"
#include "Inventory.h"
#include "LevelStage.h"
#include "Player.h"


class Game {
private:
    Player player;
    std::vector<Enemy> enemies;
    LevelStage currentLevel;
    Inventory inventory;

public:
    explicit Game(const Player& player);
    ~Game();

    void startGame();
    void nextLevel();
    void playerTurn();
    void enemyTurn();
    void applyTurns();
    void handleLoot();
    void displayLevelText();
    void playerAttack();
    void playerViewInventory();
    void playerViewLevels();
    void spawnEnemy(const std::string &name, EnemyType type, int level);
};


#endif //RPG_GAME_GAME_H