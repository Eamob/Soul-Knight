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
	int attack1;//������ �˺�ֵ
	int attack2;//Զ�̹��� �˺�ֵ
};

