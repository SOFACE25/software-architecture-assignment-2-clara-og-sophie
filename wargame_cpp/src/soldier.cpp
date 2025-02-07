#include "soldier.hpp"

Soldier::Soldier(int health, int damage) : Unit(health), damage(damage)
{
}

void Soldier::attack(Unit &target)
{
    target.take_hit(damage);//inflicts damage on the target unit
}
void Soldier::heal(Unit &target)
{
    target.set_health(target.get_health() + damage);
}

const int Soldier::getDamage()
{
    return damage;
}