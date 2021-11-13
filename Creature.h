#pragma once
#include <easy2d/easy2d.h>

using namespace easy2d;

//生物类，包括玩家和怪物
class Creature : public Sprite
{
public:
	int direction;//1 2 3 4 上右下左
	int health;
	float speed;
	int face;//人物朝向  1=左  2=又
	bool faceChange;//用于判断人物是否变向，false是没有变向，true是变向了

public:
	void move(int dirction);//重写父类函数
};

