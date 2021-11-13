#include"Player.h"
#include"Data.h"

Player::Player()
{
	this->face = 1;
	this->faceChange = false;
	this->speed = 2.0f;

	health = 999999;//初始血量

	this->open(L"res/heros/one_l0.png");//导入人物图片
	this->setWidth(BRICK_WIDTH * 2);
	this->setHeight(BRICK_WIDTH * 2);
	this->setAnchor(0.5f, 0.5f);
	this->setPos(WINDOW_WIDTH * BRICK_WIDTH / 2, WINDOW_HEIGHT * BRICK_WIDTH / 2);//生成人物

}


void Player::move(int direction)
{
	if (this->faceChange)//方向改变
	{
		if (face == 1)
		{
			//重新生成一次人物
			this->open(L"res/heros/one_l0.png");//导入人物图片
			this->setWidth(BRICK_WIDTH * 2);
			this->setHeight(BRICK_WIDTH * 2);
			this->setAnchor(0.5f, 0.5f);
			this->setPos(this->getPosX(), this->getPosY());//生成人物

			this->faceChange = false;
		}
		else if (face == 2)
		{
			this->open(L"res/heros/one_r0.png");//导入人物图片
			this->setWidth(BRICK_WIDTH * 2);
			this->setHeight(BRICK_WIDTH * 2);
			this->setAnchor(0.5f, 0.5f);
			this->setPos(this->getPosX(), this->getPosY());//生成人物

			this->faceChange = false;
		}
	}
	
	switch (direction)
	{
	case 1:
	{
		if (this->getPosY() > (Window::getHeight() - MAP_HEIGHT * BRICK_WIDTH) / 2 + this->getHeight() / 2)
		{
			//auto moveBy = gcnew MoveBy(0.2f, Vector2(0, -speed));
			//auto two = gcnew Spawn({ moveBy, animateR });
			//this->runAction(two);
			//this->runAction(moveBy);
			this->movePosY(-speed);
			//this->runAction(gcnew Loop(animateR));
		}
		break;
	}
	case 2:
	{
		if (this->getPosX() < Window::getWidth() / 2 + MAP_WIDTH * BRICK_WIDTH / 2 - this->getWidth() / 2)
		{
			//auto moveBy = gcnew MoveBy(0.2f, Vector2(speed, 0));
			//auto two = gcnew Spawn({ moveBy, animateR });
			//this->runAction(two);
			//this->runAction(moveBy);
			this->movePosX(speed);
			//this->runAction(gcnew Loop(animateL));
		}
		break;
	}
	case 3:
	{
		if (this->getPosY() < Window::getHeight() / 2 + MAP_HEIGHT * BRICK_WIDTH / 2 - this->getHeight() / 2)
		{
			//auto moveBy = gcnew MoveBy(0.2f, Vector2(0, speed));
			//auto two = gcnew Spawn({ moveBy, animateR });
			//this->runAction(two);
			//this->runAction(moveBy);
			this->movePosY(speed);
			//this->runAction(gcnew Loop(animateR));
		}
		break;
	}
	case 4:
	{
		if (this->getPosX() > Window::getWidth() / 2 - MAP_WIDTH * BRICK_WIDTH / 2 + this->getWidth() / 2)
		{
			//auto moveBy = gcnew MoveBy(0.2f, Vector2(-speed, 0));
			//auto two = gcnew Spawn({ moveBy, animateR });
			//this->runAction(two);
			//this->runAction(moveBy);
			this->movePosX(-speed);
			//this->runAction(gcnew Loop(animateL));
		}
		break;
	}
	}
}