#ifndef RPG_GAME_INVENTORY_H
#define RPG_GAME_INVENTORY_H

#include "Item.h"
#include "Weapon.h"
#include <vector>

class Inventory {
private:
    std::vector<Item> items;
    std::vector<Weapon> weapons;

public:
    Inventory();
    ~Inventory();
    void addItem(const Item& item);
    void removeItem(Item item);
    void addWeapon(const Weapon& weapon);
    void removeWeapon(const Weapon& weapon);
    std::vector<Item> getItems();
    std::vector<Weapon> getWeapons();

};


#endif //RPG_GAME_INVENTORY_H