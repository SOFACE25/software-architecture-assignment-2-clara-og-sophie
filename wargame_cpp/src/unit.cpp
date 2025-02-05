#include "unit.hpp"

Unit::Unit(int health) : health(health)
{
}
const int Unit::get_health()
{
    return health;
}
void Unit::set_health(int health)
{
    this->health = (health < 0) ? 0 :health;//ensure health doesnt go below zero
}
void Unit::take_hit(int damage)
{
    set_health(get_health() - damage);
}