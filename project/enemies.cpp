#define _CRT_SECURE_NO_WARNINGS

#include "enemies.h"
#include "player.h"

enemy::enemy(string n, int l, unsigned d) : name(n), life(l), dmg(d) {}

const string enemy::getname() const {
    return this->name;
}

int enemy::getlife() const {
    return this->life;
}

void enemy::setlife(int const el) {
    this->life = el;
}

unsigned enemy::getdamage() const {
    return this->dmg;
}

zombie::zombie(string n, int l, unsigned d, int zl) : enemy(n, l + zl, d) {}

void zombie::attack(player &p) {
    int pl;
    pl = p.getlife();
    pl -= this->dmg;
    p.setlife(pl);
    this->life++;
}

int zombie::getzlife() const {
    return this->zlife;
}

human::human(string n, int l, unsigned d, weapon &w) : enemy(n, l, d), hw(w) {}

void human::attack(player &p) {
    int damage = this->dmg + this->hw.getdamage() + this->hw.geth();
    int pl = p.getlife();
    pl -= damage;
    p.setlife(pl);
}

weapon &human::gethwpn() const {
    return this->hw;
}
