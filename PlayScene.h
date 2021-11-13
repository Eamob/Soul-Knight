#pragma once
#include<easy2d/easy2d.h>
#include"Data.h"
#include"Player.h"
using namespace easy2d;

class PlayScene :public Scene
{
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
	Map map;
	Node* mapLayer;
	Player* player;
};