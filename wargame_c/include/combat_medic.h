#ifndef COMBATMEDIC_H
#define COMBATMEDIC_H

#include "soldier.h"
typedef struct CombatMedic
{
    Soldier inherited;
} CombatMedic;


//initialiserer combatmedics sundhed og skade
void make_combat_medic(CombatMedic *self, int health, int damage);


#endif // COMBATMEDIC_H