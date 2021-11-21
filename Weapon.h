#pragma once
//注意，这里不能包含Player类
//#include"Player.h"
//一个Player的武器类
#include"Data.h"
#include<easy2d/easy2d.h>
#include"Bullet.h"
using namespace easy2d;

class Weapon : public Sprite
{
public:
	Weapon();//初始定义武器是近战的
	void move(int direction, bool face, bool isRanged);//根据人物行走的方向去控制武器的方向
	void SetRanged(int direction, bool face);//用于设置远程武器

	void weaponChange(int direction, bool face, bool isRanged);//当某个键被按下时切换武器的操作

	int forceRanged;//定义远程武器的威力
	int forceMelee;//定义近战武器的威力
	
};
