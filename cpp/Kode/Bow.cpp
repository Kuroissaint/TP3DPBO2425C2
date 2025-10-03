#include "Bow.h"
#include "WeaponMaterial.h" 

Bow::Bow(std::string n, int l, std::string t, const std::vector<std::pair<std::string, double>>& s, 
    std::unique_ptr<WeaponMaterial> m,
    int arr, double rng, double ds) : 
    Weapon(n, l, t, s, std::move(m)), arrows(arr), Range(rng), DrawSpeed(ds) {}

void Bow::displayWeapon() const {
    Weapon::displayWeapon(); 
    std::cout << "  Specifics: Arrows: " << arrows << ", Range: " << Range << ", Draw Speed: " << DrawSpeed << std::endl;
}

void Bow::displayWeaponWithoutMaterial() const {
    Weapon::displayWeaponWithoutMaterial(); 
    std::cout << "  Specifics: Arrows: " << arrows << ", Range: " << Range << ", Draw Speed: " << DrawSpeed << std::endl;
}