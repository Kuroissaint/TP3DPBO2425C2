#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include <memory> 
#include "Weapon.h" // Perlu definisi penuh
#include "Skill.h"  // Perlu definisi penuh

class Character {
public:
    std::string Username;
    int Level;
    std::string Job;
    int HP;
    int Mana;
    
    // Asosiasi: Character menunjuk ke objek Weapon dan Skill di memori global
    Weapon* equippedWeapon = nullptr; 
    std::vector<Skill*> learnedSkills; 

    Character(std::string u, int l, std::string j, int hp, int m);
    
    void displayCharacter() const;
    void equipWeapon(Weapon* w);
    void learnSkill(Skill* s);

    ~Character() = default;
};

#endif // CHARACTER_H