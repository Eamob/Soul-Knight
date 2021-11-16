#pragma once
#include <easy2d/easy2d.h>
#include"Data.h"
#include"Creature.h"
#include"Weapon.h"
using namespace easy2d;

class Player : public Creature
{
public:

	Player();
	~Player();
	void move(int dirction);
	void pickup();
	bool isdead();
	void vibration();
	void preLoadAnimate();

	bool isRanged; //判断是否用远程武器

	Animate* animateL;//定义人物向左行走的帧动画
	Animate* animateR;//定义人物向右行走的帧动画
	Action* loop_animateL;
	Action* loop_animateR;
	Weapon* weapon; //武器类
};

