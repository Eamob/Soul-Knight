#pragma once
#include"Data.h"
<<<<<<< Updated upstream
=======
#include"Prop.h"
>>>>>>> Stashed changes
#include<easy2d/easy2d.h>
using namespace easy2d;

//�ӵ��࣬�����ӵ����Ƕ���������������ģ�������Լ����ٶ�
class Bullet : public Sprite
{
public:
	float speed;
<<<<<<< Updated upstream
	Bullet();
=======

	bool isFired; //�ж��ӵ��Ƿ��Ѿ������ȥ
	bool isUsed; //�ж��ӵ��Ƿ��Ѿ�ʹ��

	Bullet();

>>>>>>> Stashed changes
	void move(int direction);//�ӵ����ƶ�ֻ�������й�
};