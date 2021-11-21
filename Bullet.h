#pragma once
#include"Data.h"
<<<<<<< Updated upstream
=======
#include"Prop.h"
>>>>>>> Stashed changes
#include<easy2d/easy2d.h>
using namespace easy2d;

//子弹类，由于子弹类是独立于人物和武器的，因此有自己的速度
class Bullet : public Sprite
{
public:
	float speed;
<<<<<<< Updated upstream
	Bullet();
=======

	bool isFired; //判断子弹是否已经射击出去
	bool isUsed; //判断子弹是否已经使用

	Bullet();

>>>>>>> Stashed changes
	void move(int direction);//子弹的移动只跟方向有关
};