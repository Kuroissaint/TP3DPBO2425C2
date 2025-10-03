#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <iostream>

class Type {
public:
    std::string DamageType;
    std::string AttackType;
    std::string Scaling;

    Type(std::string dmg, std::string atk, std::string scl);
    void displayType() const;
};

#endif // TYPE_H