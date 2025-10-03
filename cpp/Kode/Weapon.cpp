#include "Weapon.h"
#include "WeaponMaterial.h" 
#include <utility>

Weapon::Weapon(std::string n, int l, std::string t, const std::vector<std::pair<std::string, double>>& s,
               std::unique_ptr<WeaponMaterial> m) : 
    Name(n), Level(l), Tier(t), stats(s), material(std::move(m)) {}

void Weapon::displayWeapon() const {
    // Dipanggil saat Print Weapon (LENGKAP)
    std::cout << "  [WEAPON] Name: " << Name << " (Lvl " << Level << ", Tier " << Tier << ")" << std::endl;
    std::cout << "  Stats: ";
    for (const auto& stat : stats) {
        std::cout << stat.first << ": " << stat.second << "; ";
    }
    std::cout << std::endl;
    
    // Tampilkan Material (Komposisi)
    std::cout << "  --- Material (Komposisi) ---" << std::endl;
    if (material) {
        material->displayMaterial();
        std::cout << std::endl;
    } else {
        std::cout << "  No material defined." << std::endl;
    }
}

void Weapon::displayWeaponWithoutMaterial() const {
    // Dipanggil saat Print Character (HANYA Weapon)
    std::cout << "  [WEAPON] Name: " << Name << " (Lvl " << Level << ", Tier " << Tier << ")" << std::endl;
    std::cout << "  Stats: ";
    for (const auto& stat : stats) {
        std::cout << stat.first << ": " << stat.second << "; ";
    }
    std::cout << std::endl;
}