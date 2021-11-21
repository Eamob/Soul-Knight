/*
	这个文件作为道具类，实现的东西有
	陷阱，宝箱，以及最后的宝藏（都是放置于场景里面然后与玩家交互的物品）
*/

#pragma once
#include<easy2d/easy2d.h>
using namespace easy2d;
#include"Data.h"

class Prop :public Sprite
{
public:
	Prop(int type); //type是道具的类型，1是陷阱地刺，2是遇到的宝箱，3是宝藏
	void setPropPos(float posX, float posY);

	int trapSpeed; //定义玩家踩到陷阱之后变成的速度
	int trapHarm; //定义地刺的伤害
	int health;  //用于定义箱子的血量

	bool isOpen; //用于判断箱子是否打开
	bool isUsed; //用于判断物品是否被使用
};
