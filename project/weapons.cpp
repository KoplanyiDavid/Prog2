#define _CRT_SECURE_NO_WARNINGS
#include "weapons.h"

weapon::weapon(unsigned d, int du, unsigned h, string n) :damage(d), durability(du), handling(h), name(n) {}

unsigned weapon::getdamage() const
{
	return this->damage;
}

const string weapon::getname() const
{
	return this->name;
}

int weapon::getdu() const
{
	return this->durability;;
}

unsigned weapon::geth() const
{
	return this->handling;
}

meele::meele(unsigned d, int du, unsigned h, string n, string t):weapon(d, du, h, n), type(t) {}

gun::gun(unsigned d, int du, unsigned h, string n, unsigned bn) :weapon(d, du, h, n), bullet(bn) {}

void meele::usegun() {
	this->durability--;
}

unsigned meele::getbullet() const
{
	return 0;
}

void gun::usegun()
{
	this->bullet--;
	this->durability--;
}

unsigned gun::getbullet() const
{
	return this->bullet;
}