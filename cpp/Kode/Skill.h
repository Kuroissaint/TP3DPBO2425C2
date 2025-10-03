#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <iostream>

class Type; // Forward Declaration

class Skill {
public:
    std::string Name;
    int ManaCost;
    double Cooldown;
    Type* skillType;

    Skill(std::string n, int mc, double cd, Type* t);
    void displaySkillDetails() const;
};

#endif // SKILL_H