#include"Player.h"


Player::Player()
{
	this->speed = 2.0f;
	this->health = 999999;//初始血量
	this->isRanged = false;//初始化时用近战
	this->face = true;
	this->direction = 2;

	this->open(L"res/heros/one_r0.png");//导入人物图片
	this->setWidth(BRICK_WIDTH * 2);
	this->setHeight(BRICK_WIDTH * 2);
	this->setAnchor(0.5f, 0.5f);
	this->setPos(WINDOW_WIDTH * BRICK_WIDTH / 2, WINDOW_HEIGHT * BRICK_WIDTH / 2);//生成人物

	preLoadAnimate();

	//定义武器的一些属性
	weapon = gcnew Weapon();
	this->addChild(weapon);
	weapon->setPos(25.0f, 50.0f);//这里的坐标是以人物左上角为坐标系决定的

}

Player::~Player() {
	//回收动画
	animateL->release();
	animateR->release();
}

void Player::move(int direction)
{
	switch (direction)
	{
	case 1:
	{
		if (this->getPosY() > (Window::getHeight() - MAP_HEIGHT * BRICK_WIDTH) / 2 + this->getHeight() / 2)
		{
			this->movePosY(-speed);
			if (face == true) 
			{
				weapon->move(direction, true, this->isRanged);
				loop_animateL->resume();//继续
				loop_animateR->pause();//暂停
			}
			else 
			{
				weapon->move(direction, false, this->isRanged);
				loop_animateR->resume();
				loop_animateL->pause();
			}
		}
		break;
	}
	case 2:
	{
		if (this->getPosX() < Window::getWidth() / 2 + MAP_WIDTH * BRICK_WIDTH / 2 - this->getWidth() / 2)
		{
			this->movePosX(speed);
			loop_animateR->resume(); //继续
			loop_animateL->pause(); //暂停
		}
		weapon->move(direction, false, this->isRanged);
		break;
	}
	case 3:
	{
		if (this->getPosY() < Window::getHeight() / 2 + MAP_HEIGHT * BRICK_WIDTH / 2 - this->getHeight() / 2)
		{
			this->movePosY(speed);
			if (face == true)
			{
				weapon->move(direction, true, this->isRanged);
				loop_animateL->resume();//继续
				loop_animateR->pause();//暂停
			}
			else 
			{
				weapon->move(direction, false, this->isRanged);
				loop_animateR->resume();
				loop_animateL->pause();
			}
		}
		break;
	}
	case 4:
	{
		if (this->getPosX() > Window::getWidth() / 2 - MAP_WIDTH * BRICK_WIDTH / 2 + this->getWidth() / 2)
		{
			this->movePosX(-speed);
			loop_animateL->resume();
			loop_animateR->pause();
		}
		weapon->move(direction, true, this->isRanged);
		break;
	}
	}
}

void Player::preLoadAnimate()
{
	//Image Image1= Image::preload(L"res/heros/one_l0.png");
	

	//首先完成帧动画的创建
	// 创建帧动画的序列帧，每 0.1 秒切换一帧
	auto animationL = gcnew Animation(0.1f);
	// 加载多个精灵帧
	animationL->add(gcnew Image(L"res/heros/one_l0.png"));
	animationL->add(gcnew Image(L"res/heros/one_l1.png"));
	animationL->add(gcnew Image(L"res/heros/one_l2.png"));
	animationL->add(gcnew Image(L"res/heros/one_l3.png"));
	animateL = gcnew Animate(animationL);
	loop_animateL = gcnew Loop(animateL);
	loop_animateL->setName(L"animate_moveleft");
	//保留动画
	animateL->retain();
	//loop_animateL->retain();
	auto animationR = gcnew Animation(0.1f);
	// 加载多个精灵帧
	animationR->add(gcnew Image(L"res/heros/one_r0.png"));
	animationR->add(gcnew Image(L"res/heros/one_r1.png"));
	animationR->add(gcnew Image(L"res/heros/one_r2.png"));
	animationR->add(gcnew Image(L"res/heros/one_r3.png"));
	animateR = gcnew Animate(animationR);
	loop_animateR = gcnew Loop(animateR);
	loop_animateR->setName(L"animate_moveright");
	//保留动画
	animateR->retain();
	//loop_animateR->retain();

	//先让人物执行动画，保留动画
	this->runAction(loop_animateL);
	this->runAction(loop_animateR);
	loop_animateR->pause();
	loop_animateL->pause();
}