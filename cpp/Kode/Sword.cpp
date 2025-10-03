#include "Sword.h"
#include "WeaponMaterial.h" 

Sword::Sword(std::string n, int l, std::string t, const std::vector<std::pair<std::string, double>>& s, 
      std::unique_ptr<WeaponMaterial> m,
      double sh, double as, double bc) : 
    Weapon(n, l, t, s, std::move(m)), sharpness(sh), AttackSpeed(as), BlockChance(bc) {}

void Sword::displayWeapon() const {
    Weapon::displayWeapon(); 
    std::cout << "  Specifics: Sharpness: " << sharpness << ", Attack Speed: " << AttackSpeed << ", Block Chance: " << BlockChance << std::endl;
}

void Sword::displayWeaponWithoutMaterial() const {
    Weapon::displayWeaponWithoutMaterial(); 
    std::cout << "  Specifics: Sharpness: " << sharpness << ", Attack Speed: " << AttackSpeed << ", Block Chance: " << BlockChance << std::endl;
}