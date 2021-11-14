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
	int attack1;//近身攻击 伤害值
	int attack2;//远程攻击 伤害值

	Animate* animateL;//定义人物向左行走的帧动画
	Animate* animateR;//定义人物向右行走的帧动画
	Action* loop_animateL;
	Action* loop_animateR;
};

