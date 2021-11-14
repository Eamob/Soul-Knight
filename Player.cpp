#include"Player.h"
#include"Data.h"

Player::Player()
{
	this->face = 1;
	this->speed = 2.0f;
	this->health = 999999;//��ʼѪ��

	this->open(L"res/heros/one_l0.png");//��������ͼƬ
	this->setWidth(BRICK_WIDTH * 2);
	this->setHeight(BRICK_WIDTH * 2);
	this->setAnchor(0.5f, 0.5f);
	this->setPos(WINDOW_WIDTH * BRICK_WIDTH / 2, WINDOW_HEIGHT * BRICK_WIDTH / 2);//��������

	preLoadAnimate();
}

Player::~Player() {
	//���ն���
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
			//auto moveBy = gcnew MoveBy(0.2f, Vector2(0, -speed));
			//auto two = gcnew Spawn({ moveBy, animateR });
			//this->runAction(two);
			//this->runAction(moveBy);
			this->movePosY(-speed);
			//this->runAction(gcnew Loop(animateR));
			if (face == 1) 
			{
				loop_animateL->resume();//����
				loop_animateR->pause();//��ͣ
			}
			else 
			{
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
			//auto moveBy = gcnew MoveBy(0.2f, Vector2(speed, 0));
			//auto two = gcnew Spawn({ moveBy, animateR });
			//this->runAction(two);
			//this->runAction(moveBy);
			this->movePosX(speed);
			//this->runAction(gcnew Loop(animateL));
			loop_animateR->resume(); //����
			loop_animateL->pause(); //��ͣ
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
			if (face == 1) 
			{
				loop_animateL->resume();//����
				loop_animateR->pause();//��ͣ
			}
			else 
			{
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
			//auto moveBy = gcnew MoveBy(0.2f, Vector2(-speed, 0));
			//auto two = gcnew Spawn({ moveBy, animateR });
			//this->runAction(two);
			//this->runAction(moveBy);
			this->movePosX(-speed);
			//this->runAction(gcnew Loop(animateL));
			loop_animateL->resume();
			loop_animateR->pause();
		}
		break;
	}
	}
}

void Player::preLoadAnimate()
{
	//Image Image1= Image::preload(L"res/heros/one_l0.png");
	

	//�������֡�����Ĵ���
	// ����֡����������֡��ÿ 0.1 ���л�һ֡
	auto animationL = gcnew Animation(0.1f);
	// ���ض������֡
	animationL->add(gcnew Image(L"res/heros/one_l0.png"));
	animationL->add(gcnew Image(L"res/heros/one_l1.png"));
	animationL->add(gcnew Image(L"res/heros/one_l2.png"));
	animationL->add(gcnew Image(L"res/heros/one_l3.png"));
	animateL = gcnew Animate(animationL);
	loop_animateL = gcnew Loop(animateL);
	loop_animateL->setName(L"animate_moveleft");
	//��������
	animateL->retain();
	//loop_animateL->retain();
	auto animationR = gcnew Animation(0.1f);
	// ���ض������֡
	animationR->add(gcnew Image(L"res/heros/one_r0.png"));
	animationR->add(gcnew Image(L"res/heros/one_r1.png"));
	animationR->add(gcnew Image(L"res/heros/one_r2.png"));
	animationR->add(gcnew Image(L"res/heros/one_r3.png"));
	animateR = gcnew Animate(animationR);
	loop_animateR = gcnew Loop(animateR);
	loop_animateR->setName(L"animate_moveright");
	//��������
	animateR->retain();
	//loop_animateR->retain();

	//��������ִ�ж�������������
	this->runAction(loop_animateL);
	this->runAction(loop_animateR);
	loop_animateR->pause();
	loop_animateL->pause();
}