#pragma once
#include"Data.h"
#include"Prop.h"
#include<easy2d/easy2d.h>
using namespace easy2d;

//�ӵ��࣬�����ӵ����Ƕ���������������ģ�������Լ����ٶ�
class Bullet : public Sprite
{
public:
	float speed;

	bool isUsed; //�ж��ӵ��Ƿ��Ѿ�ʹ��

	Bullet();

	void move(int direction);//�ӵ����ƶ�ֻ�������й�
};