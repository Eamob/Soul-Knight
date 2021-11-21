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

	//设置道具
	//1. 设置陷阱，由于人物走在陷阱上面要覆盖陷阱，因此先把陷阱作为人物的child
	trap = gcnew Prop(1);
	this->addChild(trap);
	trap->setPropPos((WINDOW_WIDTH / 2 + MAP_WIDTH / 2 - 4) * BRICK_WIDTH, WINDOW_HEIGHT / 2 * BRICK_WIDTH);

	//2.设置宝箱
	box = gcnew Prop(2);
	this->addChild(box);
	box->setPropPos((WINDOW_WIDTH / 2 + MAP_WIDTH / 2 - 4) * BRICK_WIDTH, (WINDOW_HEIGHT / 2 + 4) * BRICK_WIDTH);

	//设置玩家
	player = gcnew Player();
	player->playerPos = player->getPos();
	this->addChild(player);


	//添加人物类的血量文本
	playerHealth = gcnew Text(L"Health: " + std::to_wstring(player->health));
	playerHealth->setAnchor(0.5f, 0);
	playerHealth->setPos(BRICK_WIDTH*2, BRICK_WIDTH*2);
	this->addChild(playerHealth);

	for (unsigned int i = 0; i < BULLET_INIT; i++)
	{
		Bullet* bullet = gcnew Bullet();
		bullets.push_back(bullet);
		this->addChild(bullet); //如果不在初始化的时候定义子弹的parents，在进行远程攻击的时候定义会有问题（没发现问题在哪里)。
		bullet->setOpacity(0); //但是在这里定义之后子弹默认出现在屏幕左上方，因此设置透明度为0
	}

	boxHealth = gcnew Text(L"box: " + std::to_wstring(box->health));
	boxHealth->setAnchor(0.5f, 0);
	boxHealth->setPos(BRICK_WIDTH * 2, BRICK_WIDTH * 4);
	this->addChild(boxHealth);
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

	//计时器
	std::chrono::duration<double, std::milli> timeIntervel = std::chrono::high_resolution_clock::now() - timeStart;	// 毫秒

	//攻击按钮
	if (Input::isDown(KeyCode::J) && timeIntervel.count() > 200 )
	{
		
		timeStart = std::chrono::high_resolution_clock::now();

		player->attack(); //实现人物攻击的动画以及生成子弹

		if (player->isRanged && player->numBullet > 0)//远程攻击时
		{
			this->bullets[BULLET_INIT - this->player->numBullet]->setPos(this->player->playerPos);
			this->bullets[BULLET_INIT - this->player->numBullet]->move(this->player->direction);
			this->bullets[BULLET_INIT - this->player->numBullet]->setOpacity(1.0f);
			//std::cout << player->numBullet << std::endl;
			//this->addChild(this->bullets[BULLET_INIT - this->player->numBullet]); //子弹是跟场景一起运动的，所以子弹应该变成场景的类
			//this->player->bullets[BULLET_INIT - this->player->numBullet]->getParent();
			this->player->numBullet -= 1;
		}
		else if (!player->isRanged && !box->isOpen)//近战攻击并且箱子没有打开的时候
		{
			if (player->hit(box))//人物近战武器与箱子交互
			{
				box->health -= player->weapon->forceMelee;
				box->setOpacity(box->health/6.0f);
				boxHealth->setText(L"box: " + std::to_wstring(box->health));
				if (box->health == 0)
				{
					box->setOpacity(1.0f);
					//这里可以打开随机物品
					box->open(L"res/obj/health.png");
					box->isOpen = true;
				}
			}
		}
	}

	//切换武器按钮
	if (Input::isDown(KeyCode::U) && timeIntervel.count() > 150) //当两次按键的间隔时间大于150ms才会执行下面的函数
	{
		timeStart = std::chrono::high_resolution_clock::now();
		player->weapon->weaponChange(player->direction, player->face, player->isRanged);
		player->isRanged = !player->isRanged;
	}

	//判断陷阱和人物是否重合
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

	//限制人物不能穿过箱子
	if (player->getBoundingBox().intersects(box->getBoundingBox()) && box->isOpen == false)
	{
		player->setPos(player->playerPos);
		timeStart = std::chrono::high_resolution_clock::now();
		
	}
	else if(player->getBoundingBox().intersects(box->getBoundingBox()) && 
		box->isUsed == false && box->isOpen == true && timeIntervel.count() > 1000) //箱子打开了之后人物跟出来的物品接触到了之后，四个条件：接触，没有被使用过，箱子打开了，距离箱子打开的1秒后
	{
		box->setOpacity(0.5);
		box->isUsed = true;
		player->health += 2;
		playerHealth->setText(L"Health: " + std::to_wstring(player->health));
	}

	//这里的问题就是只会判断新生成的子弹，不能每一个子弹都判断，应该要在子弹类里面的update函数定义是否碰撞
	/*//注意优先级，应该先判断子弹数，子弹数少于20的时候才开始生成子弹，否则后面的bullet会报错
	if (player->numWeapon < 20 && player->weapon->bullet->getBoundingBox().intersects(box->getBoundingBox()) && !box->isOpen &&timeIntervel.count() > 300)
	{
		timeStart = std::chrono::high_resolution_clock::now();
		box->health -= player->weapon->forceRanged;
		box->setOpacity(box->health / 6.0f);
		boxHealth->setText(L"box: " + std::to_wstring(box->health));
		if (box->health == 0)
		{
			box->setOpacity(1.0f);
			//这里可以打开随机物品
			box->open(L"res/obj/health.png");
			box->isOpen = true;
		}
	}*/
	player->playerPos = player->getPos(); //记录上一帧玩家的位置
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
				sprite->open(L"res/map/Wall.png");
			}
			// 2.地面
			else if (map_type == TYPE::Ground)
			{
				sprite->open(L"res/map/Ground.png");
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
	::g_CurrentLevel = level;

	// 获取关卡地图信息
	map = g_Maps[level - 1];
	// 载入地图
	Flush();
}

