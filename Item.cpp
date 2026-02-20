#include "Item.h"

Item::Item(const std::string &name, const std::string &description, const Type type) {
    this->name = name;
    this->description = description;
    this->type = type;
}

Item::~Item() = default;

std::string Item::getName() const {
    return name;
}

std::string Item::getDescription() const {
    return description;
}

Type Item::getType() const {
    return type;
}
