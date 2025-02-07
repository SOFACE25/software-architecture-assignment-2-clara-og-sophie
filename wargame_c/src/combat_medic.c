#include "combat_medic.h"

void combat_medic_heal(Unit *self, Unit *target) //funkiton der helbreder
{
    if(unit_get_health(target) < 0)
    {
        printf("he is gone...");
    }
    else
    {
        unit_set_health(target, unit_get_health(target));  
    }
}

void make_combat_medic(CombatMedic *self, int health, int damage)
{
    make_soldier(&self->inherited, health, damage); //initialiserer combatmedic som soldier
    self->inherited.inherited.vt->heal_target = combat_medic_heal; //overrider heal_target fra soldier
}


