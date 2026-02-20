#ifndef RPG_GAME_ITEM_H
#define RPG_GAME_ITEM_H

#include <iostream>

enum Type {
    Healing,
    Strength_Buff,
    Health_Buff,
    Key_Item
};

class Item {
private:
    std::string name;
    std::string description;
    Type type;

public:
    Item(const std::string &name, const std::string &description, Type type);
    virtual ~Item();

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::string getDescription() const;
    [[nodiscard]] Type getType() const;
};


#endif //RPG_GAME_ITEM_H