#pragma once
//ע�⣬���ﲻ�ܰ���Player��
//#include"Player.h"
//һ��Player��������
#include"Data.h"
#include<easy2d/easy2d.h>
#include"Bullet.h"
using namespace easy2d;

class Weapon : public Sprite
{
public:
	Weapon();//��ʼ���������ǽ�ս��
	void move(int direction, bool face, bool isRanged);//�����������ߵķ���ȥ���������ķ���
<<<<<<< Updated upstream
	void attack(int direction, bool face, bool isRanged, Point playerPos);//����������ҵķ���������
	void weaponChange(int direction, bool face, bool isRanged);//��ĳ����������ʱ�л������Ĳ���

	void SetRanged(int direction, bool face);//��������Զ������
	
	int force;//��������������
=======
	void SetRanged(int direction, bool face);//��������Զ������

	void attack(int direction, bool face, bool isRanged, Point playerPos);//����������ҵķ���������
	void weaponChange(int direction, bool face, bool isRanged);//��ĳ����������ʱ�л������Ĳ���


	int forceRanged;//����Զ������������
	int forceMelee;//�����ս����������
	
>>>>>>> Stashed changes
	Bullet* bullet;

};
