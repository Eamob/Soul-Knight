#include"Bullet.h"

Bullet::Bullet()
{
	this->open(L"res/heros/Bullet.png");//��������ͼƬ
	this->setWidth(BRICK_WIDTH * 2);
	this->setHeight(BRICK_WIDTH * 2);
	this->setAnchor(0.5f, 0.5f); //����01��Ϊê�㣬Ҳ���ǵ����հѴ�
	this->speed = 400;
}


void Bullet::move(int direction)//�ӵ����ƶ�ֻ�������й�
{
	switch (direction)//1234��������
	{
	case 1:
	{
		auto move1 = gcnew MoveBy(100/speed, Vector2(0, -100));
		Loop *loop1 = gcnew Loop(move1);
		// ��һ������ִ��
		this->runAction(loop1);
		break;
	}
	case 2:
	{
		auto move2 = gcnew MoveBy(100 / speed, Vector2(100, 0));
		Loop* loop2 = gcnew Loop(move2);
		// ��һ������ִ��
		this->runAction(loop2);
		break;
	}
	case 3:
	{
		auto move3 = gcnew MoveBy(100 / speed, Vector2(0, 100));
		Loop* loop3 = gcnew Loop(move3);
		// ��һ������ִ��
		this->runAction(loop3);
		break;
	}
	case 4:
	{
		auto move4 = gcnew MoveBy(100 / speed, Vector2(-100, 0));
		Loop* loop4 = gcnew Loop(move4);
		// ��һ������ִ��
		this->runAction(loop4);
		break;
	}
	}
}