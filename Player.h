#pragma once
#include <easy2d/easy2d.h>
#include"Data.h"
#include"Creature.h"
using namespace easy2d;

class Player : public Creature
{
public:

	Player();
	void move(int dirction);
	void attack();
	void pickup();
	bool isdead();
	void vibration();

public:
	int attack1;//近身攻击 伤害值
	int attack2;//远程攻击 伤害值
};

