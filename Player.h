#pragma once
#include <easy2d/easy2d.h>
#include<math.h>
#include"Data.h"
#include"Creature.h"
#include"Weapon.h"
<<<<<<< Updated upstream
=======
#include"Prop.h"
>>>>>>> Stashed changes
using namespace easy2d;

class Player : public Creature
{
public:

	Player();
	~Player();
<<<<<<< Updated upstream
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
=======
	void move(int dirction);//人物移动函数
	void preLoadAnimate();//定义人物的一些动画
	bool hit(Prop *Obj);//判定人物的近战武器是否与道具触碰到。
	//void attack();//人物攻击时候的一些武器动画

	Animate* animateL;//定义人物向左行走的帧动画
	Animate* animateR;//定义人物向右行走的帧动画
	Action* loop_animateL;
	Action* loop_animateR;

	bool isRanged; //判断是否用远程武器
	int numBullet; //玩家剩余子弹数numBullet

	Weapon* weapon; //武器类
	Point playerPos;
	//Bullet* bullets; //用于储存子弹

>>>>>>> Stashed changes
};

