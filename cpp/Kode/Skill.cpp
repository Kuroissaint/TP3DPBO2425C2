#include "Skill.h"
#include "Type.h" 

Skill::Skill(std::string n, int mc, double cd, Type* t) : 
    Name(n), ManaCost(mc), Cooldown(cd), skillType(t) {}

void Skill::displaySkillDetails() const {
    std::cout << "  - [SKILL] Name: " << Name << ", Mana Cost: " << ManaCost << ", Cooldown: " << Cooldown << "s" << std::endl;
    if (skillType) {
        std::cout << "    Type Details: ";
        skillType->displayType(); 
        std::cout << std::endl;
    }
}