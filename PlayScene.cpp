#include "PlayScene.h"
#include"Data.h"

//������Ӧ���������Ŀ�ʼʱ��洢����
auto timeStart = std::chrono::high_resolution_clock::now();

PlayScene::PlayScene(int level)
{
	//**һЩ�����ڵ�Կ����Ŀ������ֵ����ʾ

	//**����Ӧ�ø�һЩ��ͣ��ťֱ�Ӱ�
	// ��ӵ�ͼ����
	mapLayer = gcnew Node();
	this->addChild(mapLayer);

	// ���ùؿ�
	this->SetLevel(level);

	//���õ���
	//1. �������壬��������������������Ҫ�������壬����Ȱ�������Ϊ�����child
	trap = gcnew Prop(1);
	this->addChild(trap);
	trap->setPropPos((WINDOW_WIDTH / 2 + MAP_WIDTH / 2 - 4) * BRICK_WIDTH, WINDOW_HEIGHT / 2 * BRICK_WIDTH);

	//2.���ñ���
	box = gcnew Prop(2);
	this->addChild(box);
	box->setPropPos((WINDOW_WIDTH / 2 + MAP_WIDTH / 2 - 4) * BRICK_WIDTH, (WINDOW_HEIGHT / 2 + 4) * BRICK_WIDTH);

	//�������
	player = gcnew Player();
	player->playerPos = player->getPos();
	this->addChild(player);


	//����������Ѫ���ı�
	playerHealth = gcnew Text(L"Health: " + std::to_wstring(player->health));
	playerHealth->setAnchor(0.5f, 0);
	playerHealth->setPos(BRICK_WIDTH*2, BRICK_WIDTH*2);
	this->addChild(playerHealth);

	boxHealth = gcnew Text(L"box: " + std::to_wstring(box->health));
	boxHealth->setAnchor(0.5f, 0);
	boxHealth->setPos(BRICK_WIDTH * 2, BRICK_WIDTH * 4);
	this->addChild(boxHealth);

	

}

void PlayScene::onUpdate()
{
	player_down = 0; //û������

	// 1 up 2 right 3 down 4 left 
	if (Input::isDown(KeyCode::S))
	{
		player_down = 1;
		player->direction = 3;
		player->move(3);
		
	}
	else if (Input::isDown(KeyCode::W))
	{
		player_down = 1;
		player->direction = 1;
		player->move(1);
	}

	if (Input::isDown(KeyCode::A))
	{
		player_down = 1;
		player->direction = 4;
		if (player->face == false)
		{
			player->face = true;
		}
		player->move(4);
	}
	else if (Input::isDown(KeyCode::D))
	{
		player_down = 1;
		player->direction = 2;
		if (player->face == true)
		{
			player->face = false;
		}
		player->move(2);
	}
	if (!player_down)
	{
		player->pauseAction(L"animate_moveright");
		player->pauseAction(L"animate_moveleft");
	}
<<<<<<< Updated upstream
	std::chrono::duration<double, std::milli> timeIntervel = std::chrono::high_resolution_clock::now() - timeStart;	// ����


	if (Input::isDown(KeyCode::J) && timeIntervel.count() > 150)
	{
		timeStart = std::chrono::high_resolution_clock::now();
		player->weapon->attack(player->direction, player->face, player->isRanged, player->getPos());

		if (player->isRanged)
		{
			this->addChild(player->weapon->bullet); //�ӵ��Ǹ�����һ���˶��ģ������ӵ�Ӧ�ñ�ɳ�������
		}
	}

=======

	//��ʱ��
	std::chrono::duration<double, std::milli> timeIntervel = std::chrono::high_resolution_clock::now() - timeStart;	// ����

	//������ť
	if (Input::isDown(KeyCode::J) && timeIntervel.count() > 200 )
	{
		
		timeStart = std::chrono::high_resolution_clock::now();

		player->weapon->attack(player->direction, player->face, player->isRanged, player->playerPos); //ʵ�����﹥���Ķ����Լ������ӵ�

		if (player->isRanged && player->numBullet > 0)//Զ�̹���ʱ
		{
			/*this->addChild(player->bullets[BULLET_INIT - player->numBullet]);
			player->bullets[BULLET_INIT - player->numBullet]->setPos(this->player->getPos());
			player->bullets[BULLET_INIT - player->numBullet]->move(player->direction);*/
			player->numBullet -= 1;
			this->addChild(player->weapon->bullet); //�ӵ��Ǹ�����һ���˶��ģ������ӵ�Ӧ�ñ�ɳ�������
		}
		else if (!player->isRanged && !box->isOpen)//��ս������������û�д򿪵�ʱ��
		{
			if (player->hit(box))//�����ս���������ӽ���
			{
				box->health -= player->weapon->forceMelee;
				box->setOpacity(box->health/6.0f);
				boxHealth->setText(L"box: " + std::to_wstring(box->health));
				if (box->health == 0)
				{
					box->setOpacity(1.0f);
					//������Դ������Ʒ
					box->open(L"res/obj/health.png");
					box->isOpen = true;
				}
			}
		}

		//�ڹ�����ʱ���ӵ���������
	}

	//�л�������ť
>>>>>>> Stashed changes
	if (Input::isDown(KeyCode::U) && timeIntervel.count() > 150) //�����ΰ����ļ��ʱ�����150ms�Ż�ִ������ĺ���
	{
		timeStart = std::chrono::high_resolution_clock::now();
		player->weapon->weaponChange(player->direction, player->face, player->isRanged);
		player->isRanged = !player->isRanged;
	}
<<<<<<< Updated upstream
=======

	//�ж�����������Ƿ��غ�
	if (player->getBoundingBox().intersects(trap->getBoundingBox()))
	{
		player->speed = trap->trapSpeed;
		if (timeIntervel.count() > 500)
		{
			timeStart = std::chrono::high_resolution_clock::now();
			player->health -= trap->trapHarm;
			playerHealth->setText(L"Health: " + std::to_wstring(player->health));
		}
	}
	else
	{
		player->speed = 3.0f;
	}

	//�������ﲻ�ܴ�������
	if (player->getBoundingBox().intersects(box->getBoundingBox()) && box->isOpen == false)
	{
		player->setPos(player->playerPos);
		timeStart = std::chrono::high_resolution_clock::now();
		
	}
	else if(player->getBoundingBox().intersects(box->getBoundingBox()) && 
		box->isUsed == false && box->isOpen == true && timeIntervel.count() > 1000) //���Ӵ���֮���������������Ʒ�Ӵ�����֮���ĸ��������Ӵ���û�б�ʹ�ù������Ӵ��ˣ��������Ӵ򿪵�1���
	{
		box->setOpacity(0.5);
		box->isUsed = true;
		player->health += 2;
		playerHealth->setText(L"Health: " + std::to_wstring(player->health));
	}

	//������������ֻ���ж������ɵ��ӵ�������ÿһ���ӵ����жϣ�Ӧ��Ҫ���ӵ��������update���������Ƿ���ײ
	/*//ע�����ȼ���Ӧ�����ж��ӵ������ӵ�������20��ʱ��ſ�ʼ�����ӵ�����������bullet�ᱨ��
	if (player->numWeapon < 20 && player->weapon->bullet->getBoundingBox().intersects(box->getBoundingBox()) && !box->isOpen &&timeIntervel.count() > 300)
	{
		timeStart = std::chrono::high_resolution_clock::now();
		box->health -= player->weapon->forceRanged;
		box->setOpacity(box->health / 6.0f);
		boxHealth->setText(L"box: " + std::to_wstring(box->health));
		if (box->health == 0)
		{
			box->setOpacity(1.0f);
			//������Դ������Ʒ
			box->open(L"res/obj/health.png");
			box->isOpen = true;
		}
	}*/
	player->playerPos = player->getPos(); //��¼��һ֡��ҵ�λ��
>>>>>>> Stashed changes
}

void PlayScene::Flush()
{
	// ���ԭ��ͼ
	mapLayer->removeAllChildren();
	// ���ص�ͼ
	for (int i = 0; i < map.width; i++)
	{
		for (int j = 0; j < map.height; j++)
		{
			// ȡ����ͼ�е�Ԫ��
			TYPE map_type = map.value[j][i];
			// ��������
			auto sprite = gcnew Sprite();

			// ���ݲ�ͬ���ͼ��ز�ͬͼƬ
			/*
			��������ø������ѡ��ͼƬ
			*/
			// 1.ǽ
			if (map_type == TYPE::Wall)
			{
				sprite->open(L"res/map/Wall.png");
			}
			// 2.����
			else if (map_type == TYPE::Ground)
			{
				sprite->open(L"res/map/Ground.png");
			}
			else
			{
				continue;
			}
			// ����ͼƬ����
			sprite->setAnchor(0.0f, 0.0f);
			sprite->setWidth(BRICK_WIDTH);
			sprite->setHeight(BRICK_WIDTH);
			//����ij��Ϣ�ѵ�ͼ�����м�
			sprite->setPosX(((WINDOW_WIDTH - map.width) / 2 + i) * sprite->getWidth());
			sprite->setPosY(((WINDOW_HEIGHT - map.height) / 2 + j) * sprite->getHeight());
			// ��ʾ����ͼƬ
			mapLayer->addChild(sprite);
		}
	}
}

void PlayScene::SetLevel(int level)
{
	::g_CurrentLevel = level;

	// ��ȡ�ؿ���ͼ��Ϣ
	map = g_Maps[level - 1];
	// �����ͼ
	Flush();
}

