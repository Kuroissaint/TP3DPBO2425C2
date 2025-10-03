#ifndef SWORD_H
#define SWORD_H

#include "Weapon.h" 
class WeaponMaterial; 

class Sword : virtual public Weapon { 
public:
    double sharpness;
    double AttackSpeed;
    double BlockChance;
    
    Sword(std::string n, int l, std::string t, const std::vector<std::pair<std::string, double>>& s, 
          std::unique_ptr<WeaponMaterial> m,
          double sh, double as, double bc);

    void displayWeapon() const override;
    void displayWeaponWithoutMaterial() const override;
};

#endif // SWORD_H