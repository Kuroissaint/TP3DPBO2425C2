#include "WeaponMaterial.h"

WeaponMaterial::WeaponMaterial(std::string r, std::string q) : 
    Rarity(r), Quality(q) {}

void WeaponMaterial::displayMaterial() const {
    std::cout << "  [MATERIAL] Rarity: " << Rarity << ", Quality: " << Quality;
}