#include "combat_medic.h"

void combat_medic_heal(Unit *self, Unit *target)
{
    if (unit_get_health(target) < 0)
    {
        printf("He is gone...");
    }
    else
    {
        printf("Hang in there!");
        unit_set_health(target, unit_get_health(target) + 10);
    }
}

void make_combat_medic(CombatMedic *self, int health, int damage)
{
    make_soldier(&self->inherited, health, damage);
    self->inherited.inherited.vt->heal_target = combat_medic_heal;
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

void _unit_attack_target(Unit *self, Unit *target)
{
    printf("'attack' method is not implemented for 'Unit' class");
    assert(0);
}

void _medic_heal_target(Unit *self, Unit *target)
{
    printf("medic heals target\n");
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
    if (target->health <= 0){
        return;
    } else {
        target->health += 10; //fast værdi som medics healing power har
        if (target->health > target->max_health) {
            target->health = target->max_health;
        }
    }

}

void make_unit(Unit *self, int health)
{
    static UnitVTable vt = { 
        _unit_get_health, 
        _unit_set_health, 
        _unit_take_hit, 
        _unit_attack_target, 
        _medic_heal_target
        };
    
    self->vt = &vt;
    self->health = health;
    self->max_health = health; //max health er start health
}
