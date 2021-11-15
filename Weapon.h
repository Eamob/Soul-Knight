#pragma once
//注意，这里不能包含Player类
//#include"Player.h"
//一个Player的武器类
#include"Data.h"
#include<easy2d/easy2d.h>
using namespace easy2d;

class Weapon : public Sprite
{
public:
	Weapon();//初始定义武器是近战的
	void move(int direction, bool face, bool isRanged);//根据人物行走的方向去控制武器的方向
	void attack(int direction, bool face, bool isRanged);//攻击是由玩家的方向来定的
	void weaponChange(int direction, bool face, bool isRanged);//当某个键被按下时切换武器的操作
	
	int force;//定义武器的威力
};
