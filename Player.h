#pragma once
#include <easy2d/easy2d.h>
#include<math.h>
#include"Data.h"
#include"Creature.h"
#include"Weapon.h"
#include"Prop.h"
using namespace easy2d;

class Player : public Creature
{
public:

	Player();
	~Player();
	void move(int dirction);//�����ƶ�����
	void preLoadAnimate();//���������һЩ����
	bool hit(Prop *Obj);//�ж�����Ľ�ս�����Ƿ�����ߴ�������
	void attack();//���﹥��ʱ���һЩ��������

	Animate* animateL;//���������������ߵ�֡����
	Animate* animateR;//���������������ߵ�֡����
	Action* loop_animateL;
	Action* loop_animateR;

	bool isRanged; //�ж��Ƿ���Զ������
	int numBullet; //���ʣ���ӵ���numBullet
	Point playerPos;

	Weapon* weapon; //������

};

