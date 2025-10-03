#include "Character.h"
#include <iostream>

Character::Character(std::string u, int l, std::string j, int hp, int m) : 
    Username(u), Level(l), Job(j), HP(hp), Mana(m) {}

void Character::equipWeapon(Weapon* w) {
    equippedWeapon = w;
}

void Character::learnSkill(Skill* s) {
    learnedSkills.push_back(s);
}

void Character::displayCharacter() const {
    std::cout << "  [CHARACTER] Profile: " << Username << " | Job: " << Job << std::endl;
    std::cout << "Level: " << Level << " | HP: " << HP << " | Mana: " << Mana << std::endl;
    
    // Tampilkan Senjata (Tanpa Material)
    std::cout << "\n-- EQUIPPED WEAPON --" << std::endl;
    if (equippedWeapon) {
        // Polymorphism: Panggil versi tanpa material
        equippedWeapon->displayWeaponWithoutMaterial(); 
    } else {
        std::cout << "  (No weapon equipped)" << std::endl;
    }
    
    // Tampilkan Skill
    std::cout << "\n-- LEARNED SKILLS (" << learnedSkills.size() << ") --" << std::endl;
    if (!learnedSkills.empty()) {
        for (const auto& skill : learnedSkills) {
            skill->displaySkillDetails();
        }
    } else {
        std::cout << "  (No skills learned)" << std::endl;
    }
}