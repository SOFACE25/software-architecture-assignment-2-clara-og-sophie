#ifndef COMBATMEDIC_H
#define COMBATMEDIC_H

#include "soldier.h"
typedef struct CombatMedic
{
    Soldier inherited;
} CombatMedic;

void medic_heal_target(Unit *self, Unit *target);

UnitVTable CombatMedic_VTable = {
    .get_health = unit_get_health,
    .set_health = unit_set_health,
    .take_hit = unit_take_hit,
    .attack_target = unit_attack_target,
    .heal_target = medic_heal_target,
};

void make_combat_medic(CombatMedic *self, int health, int damage);


#endif // COMBATMEDIC_H