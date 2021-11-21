#include"Weapon.h"

Weapon::Weapon()
{
	Image::preload(L"res/heros/MeleeR.png");//提前加载图片
	Image::preload(L"res/heros/MeleeL.png");//提前加载图片
	Image::preload(L"res/heros/RangedL.png");
	Image::preload(L"res/heros/RangedR.png");
	Image::preload(L"res/heros/Ranged1false.png");
	Image::preload(L"res/heros/Ranged1true.png");
	Image::preload(L"res/heros/Ranged3true.png");
	Image::preload(L"res/heros/Ranged3true.png");

<<<<<<< Updated upstream
	this->open(L"res/heros/MeleeR.png");//导入人物图片
=======
	this->open(L"res/heros/MeleeR.png");//导入武器图片
>>>>>>> Stashed changes
	this->setWidth(BRICK_WIDTH*2);
	this->setHeight(BRICK_WIDTH*2);
	this->setAnchor(0.0f, 1.0f); //设置01作为锚点，也就是刀的握把处

<<<<<<< Updated upstream
=======
	this->forceMelee = 2;
	this->forceRanged = 1;

>>>>>>> Stashed changes
}

void Weapon::move(int direction, bool face, bool isRanged)
{
	if (!isRanged) //近战武器
	{
		//武器的方向只跟人物朝向有关1=左  2=右
		if (face == true)
		{
			this->open(L"res/heros/MeleeL.png");//导入人物图片
			this->setWidth(BRICK_WIDTH * 2);
			this->setHeight(BRICK_WIDTH * 2);
			this->setAnchor(1.0f, 1.0f); //设置11作为锚点，也就是刀的握把处
		}
		else if (face == false)
		{
			this->open(L"res/heros/MeleeR.png");//导入人物图片
			this->setWidth(BRICK_WIDTH * 2);
			this->setHeight(BRICK_WIDTH * 2);
			this->setAnchor(0.0f, 1.0f); //设置01作为锚点，也就是刀的握把处
		}
	}
	else
	{
		SetRanged(direction, face);
	}
}

void Weapon::attack(int direction, bool face, bool isRanged, Point playerPos)
{
	//direction: 1234上右下左
	//face: 12左右

	if (!isRanged)
	{
		switch (direction)
		{
		case 1:
		{
			//动画定义
			if (face == true)
			{
				auto rotateTo = gcnew RotateTo(0.05f, 60);
				auto rotateBack = gcnew RotateTo(0.05f, 0);

				auto sequence = gcnew Sequence({ rotateTo, rotateBack });
				// 执行顺序动画
				this->runAction(sequence);
			}
			else
			{
				auto rotateTo = gcnew RotateTo(0.05f, -60);
				auto rotateBack = gcnew RotateTo(0.05f, 0);
				auto sequence = gcnew Sequence({ rotateTo, rotateBack });
				// 执行顺序动画
				this->runAction(sequence);
			}
			break;
		}
		case 2:
		{
<<<<<<< Updated upstream
			if (face == true)
			{
				auto rotateTo = gcnew RotateTo(0.05f, -60);
				auto rotateBack = gcnew RotateTo(0.05f, 0);

				auto sequence = gcnew Sequence({ rotateTo, rotateBack });
				// 执行顺序动画
				this->runAction(sequence);
			}
			else
			{
				auto rotateTo = gcnew RotateTo(0.05f, 60);
				auto rotateBack = gcnew RotateTo(0.05f, 0);
				auto sequence = gcnew Sequence({ rotateTo, rotateBack });
				// 执行顺序动画
				this->runAction(sequence);
			}
=======
			auto rotateTo = gcnew RotateTo(0.05f, 60);
			auto rotateBack = gcnew RotateTo(0.05f, 0);
			auto sequence = gcnew Sequence({ rotateTo, rotateBack });
			// 执行顺序动画
			this->runAction(sequence);
>>>>>>> Stashed changes
			break;
		}
		case 3:
		{
			if (face == true)
			{
				auto rotateTo = gcnew RotateTo(0.05f, -180);
				auto rotateBack = gcnew RotateTo(0.05f, 0);

				auto sequence = gcnew Sequence({ rotateTo, rotateBack });
				// 执行顺序动画
				this->runAction(sequence);
			}
			else
			{
				auto rotateTo = gcnew RotateTo(0.05f, 180);
				auto rotateBack = gcnew RotateTo(0.05f, 0);

				auto sequence = gcnew Sequence({ rotateTo, rotateBack });
				// 执行顺序动画
				this->runAction(sequence);
			}
			break;
		}
		case 4:
		{
			auto rotateTo = gcnew RotateTo(0.05f, -60);
			auto rotateBack = gcnew RotateTo(0.05f, 0);

			auto sequence = gcnew Sequence({ rotateTo, rotateBack });
			// 执行顺序动画
			this->runAction(sequence);
			break;
		}
		}
	}
	else//远程武器攻击
	{
		bullet = gcnew Bullet();
		bullet->setPos(playerPos);
		bullet->move(direction);
	}
}

void Weapon::weaponChange(int direction, bool face, bool isRanged)
{
	if (!isRanged)//当时是近战武器，这里变成远程武器
	{
		SetRanged(direction, face);
	}
	else
	{
		//武器的方向只跟人物朝向有关true=左  false=右
		if (face)
		{
			this->open(L"res/heros/MeleeL.png");//导入人物图片
			this->setWidth(BRICK_WIDTH * 2);
			this->setHeight(BRICK_WIDTH * 2);
			this->setAnchor(1.0f, 1.0f); //设置11作为锚点，也就是刀的握把处
		}
		else if (face == false)
		{
			this->open(L"res/heros/MeleeR.png");//导入人物图片
			this->setWidth(BRICK_WIDTH * 2);
			this->setHeight(BRICK_WIDTH * 2);
			this->setAnchor(0.0f, 1.0f); //设置01作为锚点，也就是刀的握把处
		}
	}
}

void Weapon::SetRanged(int direction, bool face)
{
	//direction1234: 上右下左
	//face：true左，false右
	switch (direction)
	{
	case 1:
	{
		if (face)
		{
			this->open(L"res/heros/Ranged1true.png");//导入人物图片
			this->setWidth(BRICK_WIDTH * 1.5);
			this->setHeight(BRICK_WIDTH * 1.5);
			this->setAnchor(0.5f, 0.5f); //设置01作为锚点，也就是刀的握把处
		}
		else
		{
			this->open(L"res/heros/Ranged1false.png");//导入人物图片
			this->setWidth(BRICK_WIDTH * 1.5);
			this->setHeight(BRICK_WIDTH * 1.5);
			this->setAnchor(0.5f, 0.5f); //设置01作为锚点，也就是刀的握把处
		}
		break;
	}
	case 2:
	{
		this->open(L"res/heros/RangedR.png");//导入人物图片
		this->setWidth(BRICK_WIDTH * 1.5);
		this->setHeight(BRICK_WIDTH * 1.5);
		this->setAnchor(0.5f, 0.5f); //设置01作为锚点，也就是刀的握把处
		break;
	}
	case 3:
	{
		if (face)
		{
			this->open(L"res/heros/Ranged3true.png");//导入人物图片
			this->setWidth(BRICK_WIDTH * 1.5);
			this->setHeight(BRICK_WIDTH * 1.5);
			this->setAnchor(0.5f, 0.5f); //设置01作为锚点，也就是刀的握把处
		}
		else
		{
			this->open(L"res/heros/Ranged3false.png");//导入人物图片
			this->setWidth(BRICK_WIDTH * 1.5);
			this->setHeight(BRICK_WIDTH * 1.5);
			this->setAnchor(0.5f, 0.5f); //设置01作为锚点，也就是刀的握把处
		}
		break;
	}
	case 4:
	{
		this->open(L"res/heros/RangedL.png");//导入人物图片
		this->setWidth(BRICK_WIDTH * 1.5);
		this->setHeight(BRICK_WIDTH * 1.5);
		this->setAnchor(0.5f, 0.5f); //设置01作为锚点，也就是刀的握把处
		break;
	}
	}
}