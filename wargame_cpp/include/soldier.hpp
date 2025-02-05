#ifndef SOLDIER_HPP
#define SOLDIER_HPP
#include "unit.hpp"

class Soldier : public Unit
{
public:
    Soldier(int health, int damage);
    virtual void attack(Unit &target);
    virtual void heal(Unit &target);
    virtual ~Soldier(){};

private:
    int damage;
    int health;

    typedef struct SoldierVTable
{
    int (*get_health)(Unit *self);
    void (*set_health)(Unit *self, int health);
    void (*take_hit)(Unit *self, int);
    void (*attack_target)(Unit *self, Unit *target);
    void (*heal_target)(Unit *self, Unit *target);
} SoldierVTable;
};

#endif // SOLDIER_HPP