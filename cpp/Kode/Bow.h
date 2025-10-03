#ifndef BOW_H
#define BOW_H

#include "Weapon.h" 
class WeaponMaterial; 

class Bow : virtual public Weapon { 
public:
    int arrows;
    double Range;
    double DrawSpeed;

    Bow(std::string n, int l, std::string t, const std::vector<std::pair<std::string, double>>& s, 
        std::unique_ptr<WeaponMaterial> m,
        int arr, double rng, double ds);

    void displayWeapon() const override;
    void displayWeaponWithoutMaterial() const override;
};

#endif // BOW_H