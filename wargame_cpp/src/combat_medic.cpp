#include "combat_medic.hpp"

CombatMedic::CombatMedic(int health, int damage) : Soldier(health, damage)
{
}

void CombatMedic::heal(Unit &target)
{
    if(target.get_health() > 0){
        target.set_health(target.get_health() + getDamage());
    }
}