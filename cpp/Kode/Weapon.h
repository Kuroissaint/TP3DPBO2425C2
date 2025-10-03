#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <vector>
#include <iostream>
#include <utility> 
#include <memory> 

class WeaponMaterial; 

class Weapon {
private:
    // Komposisi: Weapon memiliki Material
    std::unique_ptr<WeaponMaterial> material; 
    
public:
    std::string Name;
    int Level;
    std::string Tier;
    std::vector<std::pair<std::string, double>> stats;

    Weapon(std::string n = "", int l = 0, std::string t = "", 
           const std::vector<std::pair<std::string, double>>& s = {},
           std::unique_ptr<WeaponMaterial> m = nullptr);
           
    virtual ~Weapon() = default; 
    
    // Dipanggil saat print Weapon (FULL: dengan Material)
    virtual void displayWeapon() const; 
    
    // Dipanggil saat print Character (TIDAK ADA Material)
    virtual void displayWeaponWithoutMaterial() const; 
};

#endif // WEAPON_H