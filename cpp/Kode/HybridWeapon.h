#ifndef HYBRIDWEAPON_H
#define HYBRIDWEAPON_H

#include "Bow.h" 
#include "Sword.h" 
#include "Staff.h" 
#include "Type.h" 
class WeaponMaterial;

// Multiple Inheritance dengan Virtual Inheritance
class HybridWeapon : public Bow, public Sword, public Staff {
private:
    Type* specialType; 
    
public:
    std::string CombinedFrom;
    std::string Effect;

    HybridWeapon(std::string n, int l, std::string t, const std::vector<std::pair<std::string, double>>& s, 
                 std::unique_ptr<WeaponMaterial> m, 
                 int arr, double rng, double bow_ds, 
                 double swd_sh, double swd_as, double swd_bc, 
                 double stf_ss, std::string stf_e, 
                 std::string cf, std::string eff, Type* type);

    // Override fungsi display dari Weapon dasar
    void displayWeapon() const override;
    void displayWeaponWithoutMaterial() const override;
    
    ~HybridWeapon() override = default; 
};

#endif // HYBRIDWEAPON_H