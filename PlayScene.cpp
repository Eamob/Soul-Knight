#include "PlayScene.h"
#include"Data.h"

PlayScene::PlayScene(int level)
{
	//**һЩ�����ڵ�Կ����Ŀ������ֵ����ʾ

	//**����Ӧ�ø�һЩ��ͣ��ťֱ�Ӱ�

	// ��ӵ�ͼ����
	mapLayer = gcnew Node();
	this->addChild(mapLayer);

	// ���ùؿ�
	this->SetLevel(level);

	player = gcnew Player();
	this->addChild(player);
}

void PlayScene::onUpdate()
{
	player_down = 0; //û������

	// 1 up 2 right 3 down 4 left 
	if (Input::isDown(KeyCode::S))
	{
		player_down = 1;
		player->move(3);
	}
	else if (Input::isDown(KeyCode::W))
	{
		player_down = 1;
		player->move(1);
	}

	if (Input::isDown(KeyCode::A))
	{
		player_down = 1;
		if (player->face == 2)
		{
			player->face = 1;
		}
		player->move(4);
	}
	else if (Input::isDown(KeyCode::D))
	{
		player_down = 1;
		if (player->face == 1)
		{
			player->face = 2;
		}
		player->move(2);
	}
	if (!player_down)
	{
		player->pauseAction(L"animate_moveright");
		player->pauseAction(L"animate_moveleft");
	}
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
				sprite->open(L"res/map/17.png");
			}
			// 2.����
			else if (map_type == TYPE::Ground)
			{
				sprite->open(L"res/map/0.png");
			}
			// 3.��ͨ����
			else if (map_type == TYPE::Box)
			{
				sprite->open(L"res/map/box.png");
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
	// ����ؿ��ȼ�
	::g_CurrentLevel = level;
	/*
	// ����ؿ���Ϣ���ļ�
	Data::saveInt(L"level", ::g_CurrentLevel);
	// �޸Ĺؿ���Ϣ����
	levelText->setText(L"��" + std::to_wstring(level) + L"��");
	*/

	// ��ȡ�ؿ���ͼ��Ϣ
	map = g_Maps[level - 1];
	// �����ͼ
	Flush();
}