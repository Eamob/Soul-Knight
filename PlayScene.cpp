#include "PlayScene.h"
#include"Data.h"

//避免响应过于灵敏的开始时间存储变量
auto timeStart = std::chrono::high_resolution_clock::now();

PlayScene::PlayScene(int level)
{
	//**一些场景内的钥匙数目，生命值等提示

	//**这里应该搞一些暂停按钮直接按
	// 添加地图部分
	mapLayer = gcnew Node();
	this->addChild(mapLayer);

	// 设置关卡
	this->SetLevel(level);

	player = gcnew Player();
	this->addChild(player);
}

void PlayScene::onUpdate()
{
	player_down = 0; //没被按下

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
	std::chrono::duration<double, std::milli> timeIntervel = std::chrono::high_resolution_clock::now() - timeStart;	// 毫秒


	if (Input::isDown(KeyCode::J) && timeIntervel.count() > 150)
	{
		timeStart = std::chrono::high_resolution_clock::now();
		player->weapon->attack(player->direction, player->face, player->isRanged, player->getPos());

		if (player->isRanged)
		{
			this->addChild(player->weapon->bullet); //子弹是跟场景一起运动的，所以子弹应该变成场景的类
		}
	}

	if (Input::isDown(KeyCode::U) && timeIntervel.count() > 150) //当两次按键的间隔时间大于150ms才会执行下面的函数
	{
		timeStart = std::chrono::high_resolution_clock::now();
		player->weapon->weaponChange(player->direction, player->face, player->isRanged);
		player->isRanged = !player->isRanged;
	}
}

void PlayScene::Flush()
{
	// 清除原地图
	mapLayer->removeAllChildren();
	// 加载地图
	for (int i = 0; i < map.width; i++)
	{
		for (int j = 0; j < map.height; j++)
		{
			// 取出地图中的元素
			TYPE map_type = map.value[j][i];
			// 创建精灵
			auto sprite = gcnew Sprite();

			// 根据不同类型加载不同图片
			/*
			这里可以用个随机来选择图片
			*/
			// 1.墙
			if (map_type == TYPE::Wall)
			{
				sprite->open(L"res/map/17.png");
			}
			// 2.地面
			else if (map_type == TYPE::Ground)
			{
				sprite->open(L"res/map/0.png");
			}
			// 3.普通箱子
			else if (map_type == TYPE::Box)
			{
				sprite->open(L"res/map/box.png");
			}
			else
			{
				continue;
			}
			// 设置图片属性
			sprite->setAnchor(0.0f, 0.0f);
			sprite->setWidth(BRICK_WIDTH);
			sprite->setHeight(BRICK_WIDTH);
			//根据ij信息把地图放在中间
			sprite->setPosX(((WINDOW_WIDTH - map.width) / 2 + i) * sprite->getWidth());
			sprite->setPosY(((WINDOW_HEIGHT - map.height) / 2 + j) * sprite->getHeight());
			// 显示这张图片
			mapLayer->addChild(sprite);
		}
	}
}

void PlayScene::SetLevel(int level)
{
	// 保存关卡等级
	::g_CurrentLevel = level;
	/*
	// 保存关卡信息到文件
	Data::saveInt(L"level", ::g_CurrentLevel);
	// 修改关卡信息文字
	levelText->setText(L"第" + std::to_wstring(level) + L"关");
	*/

	// 获取关卡地图信息
	map = g_Maps[level - 1];
	// 载入地图
	Flush();
}