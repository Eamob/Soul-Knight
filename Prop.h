/*
	����ļ���Ϊ�����࣬ʵ�ֵĶ�����
	���壬���䣬�Լ����ı��أ����Ƿ����ڳ�������Ȼ������ҽ�������Ʒ��
*/

#pragma once
#include<easy2d/easy2d.h>
using namespace easy2d;
#include"Data.h"

class Prop :public Sprite
{
public:
	Prop(int type); //type�ǵ��ߵ����ͣ�1������ش̣�2�������ı��䣬3�Ǳ���
	void setPropPos(float posX, float posY);

	int trapSpeed; //������Ҳȵ�����֮���ɵ��ٶ�
	int trapHarm; //����ش̵��˺�
	int health;  //���ڶ������ӵ�Ѫ��

	bool isOpen; //�����ж������Ƿ��
	bool isUsed; //�����ж���Ʒ�Ƿ�ʹ��
};
