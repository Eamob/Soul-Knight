#include"Prop.h"


Prop::Prop(int type)
{
	switch (type)
	{
	case 1:
	{
		this->open(L"res/map/trap1.png");//��������ͼƬ
		this->setWidth(BRICK_WIDTH * 2);
		this->setHeight(BRICK_WIDTH * 2);
		this->setAnchor(0.5f, 0.5f); //����01��Ϊê�㣬Ҳ���ǵ����հѴ�

		this->trapSpeed = 1;
		this->trapHarm = 1; //����ش̵��˺�

		break;
	}
	case 2:
	{
		this->open(L"res/map/box.png");
		this->setWidth(BRICK_WIDTH * 1.5);
		this->setHeight(BRICK_WIDTH * 1.5);
		this->setAnchor(0.5f, 0.5f);
		this->health = 6;

		this->isUsed = false;
		this->isOpen = false;
		break;
	}

	case 3:
	{

	}
	}
	
}

void Prop::setPropPos(float posX, float posY)
{
	this->setPos(posX, posY);
}