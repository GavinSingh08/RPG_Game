#include "Inventory.h"

Inventory::Inventory() = default;

Inventory::~Inventory() = default;

void Inventory::addItem(const Item& item) {
    items.push_back(item);
}

void Inventory::removeItem(Item item) {
    for (int i = 0; i < items.size(); i++) {
        if (items.at(i).getName() == item.getName()) {
            items.erase(items.begin() + i);
        }
    }
}

void Inventory::addWeapon(const Weapon& weapon) {
    weapons.push_back(weapon);
}

void Inventory::removeWeapon(const Weapon& weapon) {
    for (int i = 0; i < weapons.size(); i++) {
        if (weapons.at(i).getName() == weapon.getName()) {
            weapons.erase(weapons.begin() + i);
        }
    }
}

std::vector<Item> Inventory::getItems() {
    return items;
}

std::vector<Weapon> Inventory::getWeapons() {
    return weapons;
}
