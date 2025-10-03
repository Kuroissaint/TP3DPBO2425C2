#include "Type.h"

Type::Type(std::string dmg, std::string atk, std::string scl) : 
    DamageType(dmg), AttackType(atk), Scaling(scl) {}

void Type::displayType() const {
    std::cout << "[TYPE] Damage: " << DamageType << ", Attack: " << AttackType << ", Scaling: " << Scaling;
}