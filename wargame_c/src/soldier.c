#include "soldier.h"

void _soldier_attack_target(Unit *self, Unit *target)
{
    Soldier *soldier = (Soldier *)self; 
    unit_take_hit(target, soldier->damage); //påfører skade på target
}

void make_soldier(Soldier *self, int health, int damage)
{
    make_unit(&self->inherited, health);
    self->inherited.vt->attack_target = _soldier_attack_target;;
    self->damage = damage;
}

