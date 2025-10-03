#include "Staff.h"
#include "WeaponMaterial.h" 

Staff::Staff(std::string n, int l, std::string t, const std::vector<std::pair<std::string, double>>& s, 
      std::unique_ptr<WeaponMaterial> m,
      double ss, std::string e) : 
    Weapon(n, l, t, s, std::move(m)), spellingSpeed(ss), Element(e) {}

void Staff::displayWeapon() const {
    Weapon::displayWeapon(); 
    std::cout << "  Specifics: Element: " << Element << ", Spelling Speed: " << spellingSpeed << std::endl;
}

void Staff::displayWeaponWithoutMaterial() const {
    Weapon::displayWeaponWithoutMaterial(); 
    std::cout << "  Specifics: Element: " << Element << ", Spelling Speed: " << spellingSpeed << std::endl;
}