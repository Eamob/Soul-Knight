#pragma once
//ע�⣬���ﲻ�ܰ���Player��
//#include"Player.h"
//һ��Player��������
#include"Data.h"
#include<easy2d/easy2d.h>
using namespace easy2d;

class Weapon : public Sprite
{
public:
	Weapon();//��ʼ���������ǽ�ս��
	void move(int direction, bool face, bool isRanged);//�����������ߵķ���ȥ���������ķ���
	void attack(int direction, bool face, bool isRanged);//����������ҵķ���������
	void weaponChange(int direction, bool face, bool isRanged);//��ĳ����������ʱ�л������Ĳ���
	
	int force;//��������������
};
