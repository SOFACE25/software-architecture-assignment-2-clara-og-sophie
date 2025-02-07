#ifndef COMBAT_MEDIC_HPP
#define COMBAT_MEDIC_HPP

#include "soldier.hpp"

//inherits from soldier and adds a heal function
class CombatMedic : public Soldier
{
public:
    CombatMedic(int health, int damage);
    virtual void heal(Unit &target);
};

#endif // COMBAT_MEDIC_HPP