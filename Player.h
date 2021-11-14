#pragma once
#include <easy2d/easy2d.h>
#include"Data.h"
#include"Creature.h"
using namespace easy2d;

class Player : public Creature
{
public:

	Player();
	~Player();
	void move(int dirction);
	void attack();
	void pickup();
	bool isdead();
	void vibration();
	void preLoadAnimate();



public:
	int attack1;//������ �˺�ֵ
	int attack2;//Զ�̹��� �˺�ֵ

	Animate* animateL;//���������������ߵ�֡����
	Animate* animateR;//���������������ߵ�֡����
	Action* loop_animateL;
	Action* loop_animateR;
};

