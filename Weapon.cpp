#include"Weapon.h"

Weapon::Weapon()
{
	Image::preload(L"res/heros/MeleeR.png");//��ǰ����ͼƬ
	Image::preload(L"res/heros/MeleeL.png");//��ǰ����ͼƬ
	Image::preload(L"res/heros/RangedL.png");
	Image::preload(L"res/heros/RangedR.png");
	Image::preload(L"res/heros/Ranged1false.png");
	Image::preload(L"res/heros/Ranged1true.png");
	Image::preload(L"res/heros/Ranged3true.png");
	Image::preload(L"res/heros/Ranged3true.png");

	this->open(L"res/heros/MeleeR.png");//��������ͼƬ
	this->setWidth(BRICK_WIDTH*2);
	this->setHeight(BRICK_WIDTH*2);
	this->setAnchor(0.0f, 1.0f); //����01��Ϊê�㣬Ҳ���ǵ����հѴ�
}

void Weapon::move(int direction, bool face, bool isRanged)
{
	if (!isRanged) //��ս����
	{
		//�����ķ���ֻ�����ﳯ���й�1=��  2=��
		if (face == true)
		{
			this->open(L"res/heros/MeleeL.png");//��������ͼƬ
			this->setWidth(BRICK_WIDTH * 2);
			this->setHeight(BRICK_WIDTH * 2);
			this->setAnchor(1.0f, 1.0f); //����11��Ϊê�㣬Ҳ���ǵ����հѴ�
		}
		else if (face == false)
		{
			this->open(L"res/heros/MeleeR.png");//��������ͼƬ
			this->setWidth(BRICK_WIDTH * 2);
			this->setHeight(BRICK_WIDTH * 2);
			this->setAnchor(0.0f, 1.0f); //����01��Ϊê�㣬Ҳ���ǵ����հѴ�
		}
	}
	else
	{
		switch (direction)
		{
		case 1:
		{
			if (face)
			{
				this->open(L"res/heros/Ranged1true.png");//��������ͼƬ
				this->setWidth(BRICK_WIDTH * 1.5);
				this->setHeight(BRICK_WIDTH * 1.5);
				this->setAnchor(0.5f, 0.5f); //����01��Ϊê�㣬Ҳ���ǵ����հѴ�
			}
			else
			{
				this->open(L"res/heros/Ranged1false.png");//��������ͼƬ
				this->setWidth(BRICK_WIDTH * 1.5);
				this->setHeight(BRICK_WIDTH * 1.5);
				this->setAnchor(0.5f, 0.5f); //����01��Ϊê�㣬Ҳ���ǵ����հѴ�
			}
			break;
		}
		case 2:
		{
			this->open(L"res/heros/RangedR.png");//��������ͼƬ
			this->setWidth(BRICK_WIDTH * 1.5);
			this->setHeight(BRICK_WIDTH * 1.5);
			this->setAnchor(0.5f, 0.5f); //����01��Ϊê�㣬Ҳ���ǵ����հѴ�
			break;
		}
		case 3:
		{
			if (face)
			{
				this->open(L"res/heros/Ranged3true.png");//��������ͼƬ
				this->setWidth(BRICK_WIDTH * 1.5);
				this->setHeight(BRICK_WIDTH * 1.5);
				this->setAnchor(0.5f, 0.5f); //����01��Ϊê�㣬Ҳ���ǵ����հѴ�
			}
			else
			{
				this->open(L"res/heros/Ranged3false.png");//��������ͼƬ
				this->setWidth(BRICK_WIDTH * 1.5);
				this->setHeight(BRICK_WIDTH * 1.5);
				this->setAnchor(0.5f, 0.5f); //����01��Ϊê�㣬Ҳ���ǵ����հѴ�
			}
			break;
		}
		case 4:
		{
			this->open(L"res/heros/RangedL.png");//��������ͼƬ
			this->setWidth(BRICK_WIDTH * 1.5);
			this->setHeight(BRICK_WIDTH * 1.5);
			this->setAnchor(0.5f, 0.5f); //����01��Ϊê�㣬Ҳ���ǵ����հѴ�
			break;
		}
		}
	}
}

void Weapon::attack(int direction, bool face, bool isRanged)
{
	//direction: 1234��������
	//face: 12����

	if (!isRanged)
	{
		switch (direction)
		{
		case 1:
		{
			//��������
			if (face == true)
			{
				auto rotateTo = gcnew RotateTo(0.05f, 60);
				auto rotateBack = gcnew RotateTo(0.05f, 0);

				auto sequence = gcnew Sequence({ rotateTo, rotateBack });
				// ִ��˳�򶯻�
				this->runAction(sequence);
			}
			else
			{
				auto rotateTo = gcnew RotateTo(0.05f, -60);
				auto rotateBack = gcnew RotateTo(0.05f, 0);
				auto sequence = gcnew Sequence({ rotateTo, rotateBack });
				// ִ��˳�򶯻�
				this->runAction(sequence);
			}
			break;
		}
		case 2:
		{
			if (face == true)
			{
				auto rotateTo = gcnew RotateTo(0.05f, -60);
				auto rotateBack = gcnew RotateTo(0.05f, 0);

				auto sequence = gcnew Sequence({ rotateTo, rotateBack });
				// ִ��˳�򶯻�
				this->runAction(sequence);
			}
			else
			{
				auto rotateTo = gcnew RotateTo(0.05f, 60);
				auto rotateBack = gcnew RotateTo(0.05f, 0);
				auto sequence = gcnew Sequence({ rotateTo, rotateBack });
				// ִ��˳�򶯻�
				this->runAction(sequence);
			}
			break;
		}
		case 3:
		{
			if (face == true)
			{
				auto rotateTo = gcnew RotateTo(0.05f, -180);
				auto rotateBack = gcnew RotateTo(0.05f, 0);

				auto sequence = gcnew Sequence({ rotateTo, rotateBack });
				// ִ��˳�򶯻�
				this->runAction(sequence);
			}
			else
			{
				auto rotateTo = gcnew RotateTo(0.05f, 180);
				auto rotateBack = gcnew RotateTo(0.05f, 0);

				auto sequence = gcnew Sequence({ rotateTo, rotateBack });
				// ִ��˳�򶯻�
				this->runAction(sequence);
			}
			break;
		}
		case 4:
		{
			auto rotateTo = gcnew RotateTo(0.05f, -60);
			auto rotateBack = gcnew RotateTo(0.05f, 0);

			auto sequence = gcnew Sequence({ rotateTo, rotateBack });
			// ִ��˳�򶯻�
			this->runAction(sequence);
			break;
		}
		}
	}

	else//Զ������
	{

	}
	
}

void Weapon::weaponChange(int direction, bool face, bool isRanged)
{
	if (!isRanged)//��ʱ�ǽ�ս������������Զ������
	{
		//direction1234: ��������
		//face��true��false��
		switch (direction)
		{
		case 1:
		{
			if (face)
			{
				this->open(L"res/heros/Ranged1true.png");//��������ͼƬ
				this->setWidth(BRICK_WIDTH * 1.5);
				this->setHeight(BRICK_WIDTH * 1.5);
				this->setAnchor(0.5f, 0.5f); //����01��Ϊê�㣬Ҳ���ǵ����հѴ�
			}
			else
			{
				this->open(L"res/heros/Ranged1false.png");//��������ͼƬ
				this->setWidth(BRICK_WIDTH * 1.5);
				this->setHeight(BRICK_WIDTH * 1.5);
				this->setAnchor(0.5f, 0.5f); //����01��Ϊê�㣬Ҳ���ǵ����հѴ�
			}
			break;
		}
		case 2:
		{
			this->open(L"res/heros/RangedR.png");//��������ͼƬ
			this->setWidth(BRICK_WIDTH * 1.5);
			this->setHeight(BRICK_WIDTH * 1.5);
			this->setAnchor(0.5f, 0.5f); //����01��Ϊê�㣬Ҳ���ǵ����հѴ�
			break;
		}
		case 3:
		{
			if (face)
			{
				this->open(L"res/heros/Ranged3true.png");//��������ͼƬ
				this->setWidth(BRICK_WIDTH * 1.5);
				this->setHeight(BRICK_WIDTH * 1.5);
				this->setAnchor(0.5f, 0.5f); //����01��Ϊê�㣬Ҳ���ǵ����հѴ�
			}
			else
			{
				this->open(L"res/heros/Ranged3false.png");//��������ͼƬ
				this->setWidth(BRICK_WIDTH * 1.5);
				this->setHeight(BRICK_WIDTH * 1.5);
				this->setAnchor(0.5f, 0.5f); //����01��Ϊê�㣬Ҳ���ǵ����հѴ�
			}
			break;
		}
		case 4:
		{
			this->open(L"res/heros/RangedL.png");//��������ͼƬ
			this->setWidth(BRICK_WIDTH * 1.5);
			this->setHeight(BRICK_WIDTH * 1.5);
			this->setAnchor(0.5f, 0.5f); //����01��Ϊê�㣬Ҳ���ǵ����հѴ�
			break;
		}
		}
	}
	else
	{
		//�����ķ���ֻ�����ﳯ���й�true=��  false=��
		if (face)
		{
			this->open(L"res/heros/MeleeL.png");//��������ͼƬ
			this->setWidth(BRICK_WIDTH * 2);
			this->setHeight(BRICK_WIDTH * 2);
			this->setAnchor(1.0f, 1.0f); //����11��Ϊê�㣬Ҳ���ǵ����հѴ�
		}
		else if (face == false)
		{
			this->open(L"res/heros/MeleeR.png");//��������ͼƬ
			this->setWidth(BRICK_WIDTH * 2);
			this->setHeight(BRICK_WIDTH * 2);
			this->setAnchor(0.0f, 1.0f); //����01��Ϊê�㣬Ҳ���ǵ����հѴ�
		}
	}
}