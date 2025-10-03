#ifndef WEAPONMATERIAL_H
#define WEAPONMATERIAL_H

#include <string>
#include <iostream>

class WeaponMaterial {
public:
    std::string Rarity;
    std::string Quality;

    WeaponMaterial(std::string r, std::string q);
    void displayMaterial() const;
};

#endif // WEAPONMATERIAL_H