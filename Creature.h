#pragma once
#include <easy2d/easy2d.h>

using namespace easy2d;

//�����࣬������Һ͹���
class Creature : public Sprite
{
public:
	int direction;//1 2 3 4 ��������
	int health;
	float speed;
	bool face;//���ﳯ��  ture=��  false=��
	bool faceChange;//�����ж������Ƿ����false��û�б���true�Ǳ�����

public:
	void move(int dirction);//��д���ຯ��
};

