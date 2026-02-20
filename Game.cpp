#include "Game.h"
#include "Colors.h"

constexpr int RARELOOTPERCENTAGE = 5;

Game::Game(const Player& player) : player(player), currentLevel(1, 0, RARELOOTPERCENTAGE, 0,
        1, 1, 1) {
    Item potion("Health potion", "Heals 20 HP", Healing);
    Item sharpeningStone("Sharpening stone", "Permanently increases Attack PWR", Strength_Buff);
    Item rottenHeart("Rotten heart", "Permanently increases Max HP", Health_Buff);
    Weapon sword("Simple sword", 5, 0.05, Common);
    Weapon axeL("Demon Battleaxe", 35, 0.55, Legendary);

    inventory.addItem(potion);
    inventory.addItem(sharpeningStone);
    inventory.addItem(rottenHeart);
    inventory.addWeapon(sword);
    inventory.addWeapon(axeL);
}

Game::~Game() = default;

void Game::startGame() {
    std::cout << "Game started" << std::endl;

    spawnEnemy("Slime", Slime, 1);

    this->displayLevelText();

    while (player.isAlive()) {
        this->applyTurns();
        this->nextLevel();
        displayLevelText();
    }


    // std::cout << "Would you like to start? Y/N" << std::endl;
    //
    // char choice;
    // std::cin >> choice;
    //
    // if (std::tolower(choice) == 'y') {
    //     this->applyTurns();
    // } else {
    // }

}

void Game::nextLevel() {
    enemies.clear();
    this->currentLevel.setLevelNumber(this->currentLevel.getLevelNumber() + 1);
    this->currentLevel.setLootLevel(this->currentLevel.getLootLevel() + 1);
    this->currentLevel.setXpRate(this->currentLevel.getXpRate() + 0.25);
    this->currentLevel.setEnemyHPScale(this->currentLevel.getEnemyHPScale() + 0.25);
    this->currentLevel.setEnemyAttackScale(this->currentLevel.getEnemyAttackScale() + 0.25);

    switch (this->currentLevel.getLevelNumber()) {
        case 2:
            spawnEnemy("Slime", Slime, 2);
            spawnEnemy("Ogre", Ogre, 2);
            break;
        case 3:
            spawnEnemy("Slime", Slime, 1);
            spawnEnemy("Ogre", Ogre, 1);
            spawnEnemy("Giant", Giant, 1);
            break;
        case 4:
            spawnEnemy("Giant", Giant, 3);
            spawnEnemy("Skeleton", Skeleton, 3);
            break;
    }

    this->currentLevel.setNumEnemies(enemies.size());
}

void Game::playerTurn() {
    std::cout << "\n\n—————————————————————————" << std::endl;
    std::cout << Colors::GREEN << "Player turn" << Colors::RESET << std::endl;

    char choice;

    std::cout <<"What would you like to do?\nView Inventory (I) | Attack (A) | View Levels (L) | View Stats (S)" << std::endl;

    std::cin >> choice;
    choice = std::tolower(choice);

    if (choice == 'i') {
        this->playerViewInventory();
    } else if (choice == 'a') {
        this->playerAttack();
    } else if (choice == 'l') {
        this->playerViewLevels();
    } else if (choice == 's') {
        this->player.viewStats();
        playerTurn();
    }
}

void Game::enemyTurn() {

    std::cout << "\n\n—————————————————————————" << std::endl;
    std::cout << Colors::RED << "Enemy turn" << Colors::RESET << std::endl;

    for (int i = 0; i < enemies.size(); i++) {
            enemies.at(i).displayHPString();
            std::cout << "Attacks player for " << enemies.at(i).getAttackPWR() << " damage" << std::endl;

            player.takeDamage(enemies.at(i).attack());

            std::cout << "Current HP: ";
            player.displayHPString();
            std::cout << "\n";
    }
}

void Game::applyTurns() {
    std::cout << "You're against: " << std::endl;

    for (const Enemy& e : enemies) {
        e.displayHPString();
        std::cout << "Attack PWR: " << e.getAttackPWR() << " | Defense: " << e.getDefensePWR() << std::endl;
    }

    while (player.isAlive() && !enemies.empty()) {
        this->playerTurn();
        if (!enemies.empty()) {
            this->enemyTurn();
        }
    }
}

void Game::handleLoot() {

}

void Game::displayLevelText() {
    std::cout << Colors::YELLOW << "––––––––––––LEVEL " <<
        this->currentLevel.getLevelNumber() << "––––––––––––" << Colors::RESET << std::endl;
    std::cout << "This level has " << currentLevel.getNumEnemies() << " enemies\n" << std::endl;
}

void Game::playerAttack() {
    std::cout << "\nWhat would you like to attack: " << std::endl;
    for (Enemy& e : enemies) {
        if (e.getCurrentHP() > 0) {
            e.displayHPString();
        }
    }

    std::string enemyChoice;
    std::cin.ignore();
    getline(std::cin, enemyChoice);

    for (Enemy& e : enemies) {
        if (e.getName() == enemyChoice) {
            e.takeDamage(player.attack());
            std::cout << "Attacked: ";
            e.displayHPString();
        }
    }

    for (int i = enemies.size() - 1; i >= 0; i--) {
        if (enemies.at(i).getCurrentHP() <= 0) {
            std::cout << enemies.at(i).getName() << " is dead!\n" << std::endl;
            enemies.erase(enemies.begin() + i);
        }
    }
}

void Game::playerViewInventory() {
    std::cout << "\nInventory: " << std::endl;
    std::cout << "–––––––––ITEMS––––––––––";
    for (Item i : inventory.getItems()) {
        std::cout << "\n" << i.getName() << " | " << i.getDescription() << std::endl;
    }

    std::cout << "\n–––––––––WEAPONS––––––––––";
    for (Weapon w : inventory.getWeapons()) {
        std::cout << "\n" << w.getName() << " | Attack PWR: " << w.getAttackPWR() << " | Crit Rate: " <<
            w.getCritRate()*100 << "% | Rarity: " << w.rarityToString(w.getRarity()) << std::endl;
    }

    //TODO implement inventory management

    std::cout << "\nWould you like to access Weapons (W) or Items (I)" << std::endl;

    char choice;
    std::cin >> choice;
    choice = std::tolower(choice);

    if (choice == 'i') {
        int selectedItem;
        std::cout << "Select the corresponding number to use: " << std::endl;
        for (int i = 0; i < inventory.getItems().size(); i++) {
            std::cout << i+1 << ": " << inventory.getItems().at(i).getName() << std::endl;
        }

        std::cin >> selectedItem;
        selectedItem = selectedItem-1;
        std::cout << "You used " << inventory.getItems().at(selectedItem).getName() << std::endl;
        player.useItem(inventory.getItems().at(selectedItem));
        inventory.removeItem(inventory.getItems().at(selectedItem));
    }else if (choice == 'w') {
        int selectedItem;
        std::cout << "Select the corresponding number to equip: " << std::endl;
        for (int i = 0; i < inventory.getWeapons().size(); i++) {
            std::cout << i+1 << ": " << inventory.getWeapons().at(i).getName() << std::endl;
        }

        std::cin >> selectedItem;
        selectedItem = selectedItem-1;
        std::cout << "You equipped " << inventory.getWeapons().at(selectedItem).getName() << std::endl;
        player.equipWeapon(inventory.getWeapons().at(selectedItem));
    }

    this->playerTurn();
}

void Game::playerViewLevels() {

}

void Game::spawnEnemy(const std::string& name, EnemyType type, int level) { //TODO defense pwr stuff
    switch (type) {
        case Slime:
            enemies.emplace_back(name, 10 * currentLevel.getEnemyHPScale(),
                5 * currentLevel.getEnemyAttackScale(), 0, level, Slime);
            break;
        case Ogre:
            enemies.emplace_back(name, 20 * currentLevel.getEnemyHPScale(),
                10 * currentLevel.getEnemyAttackScale(), 0, level, Ogre);
            break;
        case Giant:
            enemies.emplace_back(name, 40 * currentLevel.getEnemyHPScale(),
                10 * currentLevel.getEnemyAttackScale(), 0, level, Giant);
            break;
        case Skeleton:
            enemies.emplace_back(name, 15 * currentLevel.getEnemyHPScale(),
                7 * currentLevel.getEnemyAttackScale(), 0, level, Skeleton);
            break;
        case Dragon:
            enemies.emplace_back(name, 100 * currentLevel.getEnemyHPScale(),
                25 * currentLevel.getEnemyAttackScale(), 0, level, Dragon);
            break;
    }
}
