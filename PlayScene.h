#pragma once
#include<easy2d/easy2d.h>
#include"Data.h"
#include"Player.h"
#include"Prop.h"

#include<iostream>
#include <chrono>
using namespace easy2d;

class PlayScene :public Scene
{
private:
	Text* playerHealth = nullptr;
	Text* boxHealth = nullptr;
	Text* bulletNUM = nullptr;
	int randomObj; //定义箱子掉落物品的随机数
public:
	PlayScene(int level);
	void onUpdate() override; //是一种回调函数。在里面定义在场景里面的运动。
	void Flush();             // 刷新画面
	void SetLevel(int level); // 设置关卡，类似于不同层
	/*
protected:
	int step;
	Map map;
	Text* levelText;
	Text* stepText;
	Text* bestText;
	*/
	//作为一个地图层
	bool player_down = 0;//检测是否有控制人物角色的按键被按下
	
	Map map;
	Node* mapLayer;
	Player* player;

	//一些道具对象
	Prop* trap;//陷阱
	Prop* box;//宝箱
	std::vector<Bullet*> bullets; //人物的子弹定义直接放在场景

};