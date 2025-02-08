#ifndef UNIT_H
#define UNIT_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct UnitVTable;

typedef struct Unit
{
    struct UnitVTable *vt;
    int health; //nuværende health
    int max_health; //maksimale health
} Unit;

typedef struct UnitVTable
{
    int (*get_health)(Unit *self); // returnerer health
    void (*set_health)(Unit *self, int health); //sætter health
    void (*take_hit)(Unit *self, int); //håndterer skade på unit
    void (*attack_target)(Unit *self, Unit *target); //angriber et mål
    void (*heal_target)(Unit *self, Unit *target); //helbrede et mål
} UnitVTable;

//funktioner til at håndtere handlinger
int unit_get_health(Unit *self);
void unit_set_health(Unit *self, int health);
void unit_take_hit(Unit *self, int damage);
void unit_attack_target(Unit *self, Unit *target);
void unit_heal_target(Unit *self, Unit *target);

//initialiserer units health
void make_unit(Unit *self, int health);
#endif // UNIT_H