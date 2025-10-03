#ifndef STAFF_H
#define STAFF_H

#include "Weapon.h" 
class WeaponMaterial; 

class Staff : virtual public Weapon { 
public:
    double spellingSpeed;
    std::string Element;

    Staff(std::string n, int l, std::string t, const std::vector<std::pair<std::string, double>>& s, 
          std::unique_ptr<WeaponMaterial> m,
          double ss, std::string e);

    void displayWeapon() const override;
    void displayWeaponWithoutMaterial() const override;
};

#endif // STAFF_H