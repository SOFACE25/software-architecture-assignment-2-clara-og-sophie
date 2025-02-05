#include "soldier.h"

void _soldier_attack(Unit *self, Unit *target)
{
    Soldier *soldier = (Soldier *)self;
    unit_take_hit(target, soldier->damage);
}

void make_soldier(Soldier *self, int health, int damage)
{
    make_unit(&self->inherited, health);

    // override "attack" method from base class
    self->inherited.vt->attack_target = _soldier_attack;

    self->damage = damage;
}

int _unit_get_health(Unit *self)
{
    return self->health;
}

void _unit_set_health(Unit *self, int health)
{
    self->health = health;
}

void _unit_take_hit(Unit *self, int damage)
{
    self->health -= damage;
}

void _soldier_attack_target(Unit *self, Unit *target)
{
    printf("Soldier attacks target!\n");
}

void _unit_heal_target(Unit *self, Unit *target)
{
    printf("'heal' method is not implemented for 'Unit' class");
    assert(0);
}

// virtual methods
int unit_get_health(Unit *self)
{
    return self->vt->get_health(self);
}

void unit_set_health(Unit *self, int health)
{
    self->vt->set_health(self, health);
}

void unit_take_hit(Unit *self, int damage)
{
    self->vt->take_hit(self, damage);
}

void unit_attack_target(Unit *self, Unit *target)
{
    self->vt->attack_target(self, target);
}

void unit_heal_target(Unit *self, Unit *target)
{
    self->vt->heal_target(self, target);
}

void make_soldier(Soldier *self, int health)
{
    static UnitVTable vt = {
        _unit_get_health, 
        _unit_set_health, 
        _unit_take_hit, 
        _soldier_attack_target, 
        _unit_heal_target
    };

    self->inherited.vt = &vt;
    self->inherited.health = health;//initial health
}