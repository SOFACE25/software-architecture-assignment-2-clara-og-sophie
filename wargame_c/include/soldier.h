#ifndef SOLDIER_H
#define SOLDIER_H

#include "unit.h"

typedef struct Soldier
{
    Unit inherited;
    int damage;
} Soldier;


void soldier_attack_target(Unit *self, Unit *target);

UnitVTable Soldier_VTable = {
    .get_health = unit_get_health,
    .set_health = unit_set_health,
    .take_hit = unit_take_hit,
    .attack_target = soldier_attack_target,
    .heal_target = unit_heal_target,
};

void make_soldier(Soldier *self, int health, int damage);

#endif // SOLDIER_H