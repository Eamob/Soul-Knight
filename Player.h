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

	bool isRanged; //�ж��Ƿ���Զ������

	Animate* animateL;//���������������ߵ�֡����
	Animate* animateR;//���������������ߵ�֡����
	Action* loop_animateL;
	Action* loop_animateR;
	Weapon* weapon; //������
};

