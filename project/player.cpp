#define _CRT_SECURE_NO_WARNINGS
#include "player.h"
#include "enemies.h"

player::player(string n, int l, weapon& w, unsigned dam) :name(n), life(l), wpn(w), damage(dam) {}

void player::attack(enemy& e)
{
	int el = e.getlife();
	el -= (this->getweapon().getdamage())+(this->getweapon().geth());
	e.setlife(el);
}

void player::fistattack(enemy & e)
{
	int el;
	el = e.getlife();
	el -= this->getdamage(); //this->damage miért jó?
	e.setlife(el);
}

const string player::getname() const
{
	return this->name;
}

int player::getlife() const
{
	return this->life;;
}

void player::setlife(const int l)
{
	this->life = l;
}

weapon & player::getweapon() const
{
	return this->wpn;
}

unsigned player::getdamage() const
{
	return this->damage;
}
