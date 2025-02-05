#include "combat_medic.hpp"

CombatMedic::CombatMedic(int health, int damage) : Soldier(health, damage)
{
}

void CombatMedic::heal(Unit &target)
{
    int new_health = target.get_health() + 10; //heal target by fixed value (ex. 10 points)
    target.set_health(new_health);
}