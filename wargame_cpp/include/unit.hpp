#ifndef UNIT_HPP
#define UNIT_HPP
class Unit
{
public:
    Unit(int health);
    virtual const int get_health();
    virtual void set_health(int health);
    virtual void take_hit(int damage);
    virtual void attack(Unit &target) = 0;
    virtual void heal(Unit &target) = 0;
    virtual ~Unit(){};

private:
    int health;
    int damage;

    typedef struct UnitVTable
{
    int (*get_health)(Unit *self);
    void (*set_health)(Unit *self, int health);
    void (*take_hit)(Unit *self, int);
    void (*attack_target)(Unit *self, Unit *target);
    void (*heal_target)(Unit *self, Unit *target);
} UnitVTable;
};
#endif // UNIT_HPP