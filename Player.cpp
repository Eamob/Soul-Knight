#include"Player.h"

Player::Player()
{
	this->speed = 3.0f;
	this->health = 999999;//��ʼѪ��
	this->isRanged = false;//��ʼ��ʱ�ý�ս
	this->face = true;
	this->direction = 2;

	this->open(L"res/heros/one_r0.png");//��������ͼƬ
	this->setWidth(BRICK_WIDTH * 2);
	this->setHeight(BRICK_WIDTH * 2);
	this->setAnchor(0.5f, 0.5f);
	this->setPos(WINDOW_WIDTH * BRICK_WIDTH / 2, WINDOW_HEIGHT * BRICK_WIDTH / 2);//��������

	preLoadAnimate();

	//����������һЩ����
	weapon = gcnew Weapon();
	this->addChild(weapon);
	weapon->setPos(25.0f, 50.0f);//��������������������Ͻ�Ϊ����ϵ������

	this->numBullet = BULLET_INIT; //��ʼ����Ϊ20���ӵ�

	/*//�����ӵ�
	for (unsigned int i = 0; i < BULLET_INIT; i++)
	{
		Bullet *bullet = gcnew Bullet();
		bullets.push_back(bullet);
	}*/

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
			this->movePosY(-speed);
			if (face == true) 
			{
				weapon->move(direction, true, this->isRanged);
				loop_animateL->resume();//����
				loop_animateR->pause();//��ͣ
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
			loop_animateR->resume(); //����
			loop_animateL->pause(); //��ͣ
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
				loop_animateL->resume();//����
				loop_animateR->pause();//��ͣ
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

bool Player::hit(Prop* Obj)
{
	switch (this->direction)
	{
	case 1:
	{
		if (abs(this->getPosX() - Obj->getPosX()) < BRICK_WIDTH)
		{
			if (this->getPosY() - Obj->getPosY() > 0 && this->getPosY() - Obj->getPosY() < 3 * BRICK_WIDTH) return true;//��y������һ��Χ
			else return false;
		}
		break;
	}
	case 2:
	{
		if (abs(this->getPosY() - Obj->getPosY()) < BRICK_WIDTH)
		{
			if (Obj->getPosX() - this->getPosX() > 0 && Obj->getPosX() - this->getPosX() < 3 * BRICK_WIDTH) return true;//��x������һ��Χ
			else return false;
		}
		break;
	}
		
	case 3:
	{
		if (abs(this->getPosX() - Obj->getPosX()) < BRICK_WIDTH)
		{
			if (Obj->getPosY() - this->getPosY() > 0 && Obj->getPosY() - this->getPosY() < 3.5 * BRICK_WIDTH) return true;//��y������һ��Χ
			else return false;
		}
		break;
	}
	case 4:
	{
		if (abs(this->getPosY() - Obj->getPosY()) < BRICK_WIDTH)
		{
			if (this->getPosX() - Obj->getPosX() > 0 && this->getPosX() - Obj->getPosX() < 3 * BRICK_WIDTH) return true;//��x������һ��Χ
			else return false;
		}
		break;
	}
	}
	return false;
}

void Player::attack()
{
	if (!this->isRanged)
	{
		switch (this->direction)
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
				this->weapon->runAction(sequence);
			}
			else
			{
				auto rotateTo = gcnew RotateTo(0.05f, -60);
				auto rotateBack = gcnew RotateTo(0.05f, 0);
				auto sequence = gcnew Sequence({ rotateTo, rotateBack });
				// ִ��˳�򶯻�
				this->weapon->runAction(sequence);
			}
			break;
		}
		case 2:
		{
			auto rotateTo = gcnew RotateTo(0.05f, 60);
			auto rotateBack = gcnew RotateTo(0.05f, 0);
			auto sequence = gcnew Sequence({ rotateTo, rotateBack });
			// ִ��˳�򶯻�
			this->weapon->runAction(sequence);
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
				this->weapon->runAction(sequence);
			}
			else
			{
				auto rotateTo = gcnew RotateTo(0.05f, 180);
				auto rotateBack = gcnew RotateTo(0.05f, 0);

				auto sequence = gcnew Sequence({ rotateTo, rotateBack });
				// ִ��˳�򶯻�
				this->weapon->runAction(sequence);
			}
			break;
		}
		case 4:
		{
			auto rotateTo = gcnew RotateTo(0.05f, -60);
			auto rotateBack = gcnew RotateTo(0.05f, 0);

			auto sequence = gcnew Sequence({ rotateTo, rotateBack });
			// ִ��˳�򶯻�
			this->weapon->runAction(sequence);
			break;
		}
		}
	}
}