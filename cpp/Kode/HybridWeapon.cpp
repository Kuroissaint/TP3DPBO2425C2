#include "HybridWeapon.h"
#include "Type.h" 
#include "WeaponMaterial.h"
#include <iostream>
#include <vector>
#include <utility>

HybridWeapon::HybridWeapon(std::string n, int l, std::string t, const std::vector<std::pair<std::string, double>>& s, 
      std::unique_ptr<WeaponMaterial> m, 
      int arr, double rng, double bow_ds, 
      double swd_sh, double swd_as, double swd_bc, 
      double stf_ss, std::string stf_e, 
      std::string cf, std::string eff, Type* type) :
    Weapon(n, l, t, s, std::move(m)), 
    Bow("", 0, "", {}, nullptr, arr, rng, bow_ds), 
    Sword("", 0, "", {}, nullptr, swd_sh, swd_as, swd_bc), 
    Staff("", 0, "", {}, nullptr, stf_ss, stf_e),
    specialType(type), CombinedFrom(cf), Effect(eff) 
    {}

void HybridWeapon::displayWeapon() const {
    Weapon::displayWeapon(); 
    std::cout << "  Hybrid Info: Combined From: " << CombinedFrom << ", Effect: " << Effect << std::endl;
    // Tampilkan specifics lengkap (termasuk Bow, Sword, Staff)
    std::cout << "  - Bow Specs: Arrows: " << Bow::arrows << ", Range: " << Bow::Range << std::endl;
    std::cout << "  - Sword Specs: Sharpness: " << Sword::sharpness << ", Attack Speed: " << Sword::AttackSpeed << std::endl;
    std::cout << "  - Staff Specs: Element: " << Staff::Element << ", Spelling Speed: " << Staff::spellingSpeed << std::endl;
    if (specialType) {
        std::cout << "  Special Type: "; specialType->displayType(); std::cout << std::endl;
    }
}

void HybridWeapon::displayWeaponWithoutMaterial() const {
    Weapon::displayWeaponWithoutMaterial(); 
    std::cout << "  Hybrid Info: Combined From: " << CombinedFrom << ", Effect: " << Effect << std::endl;
    // Tampilkan specifics lengkap (termasuk Bow, Sword, Staff)
    std::cout << "  - Bow Specs: Arrows: " << Bow::arrows << ", Range: " << Bow::Range << std::endl;
    std::cout << "  - Sword Specs: Sharpness: " << Sword::sharpness << ", Attack Speed: " << Sword::AttackSpeed << std::endl;
    std::cout << "  - Staff Specs: Element: " << Staff::Element << ", Spelling Speed: " << Staff::spellingSpeed << std::endl;
    if (specialType) {
        std::cout << "  Special Type: "; specialType->displayType(); std::cout << std::endl;
    }
}