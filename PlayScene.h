#pragma once
#include<easy2d/easy2d.h>
#include"Data.h"
#include"Player.h"

#include<iostream>
#include <chrono>

using namespace easy2d;

class PlayScene :public Scene
{
public:
	PlayScene(int level);
	void onUpdate() override; //��һ�ֻص������������涨���ڳ���������˶���
	void Flush();             // ˢ�»���
	void SetLevel(int level); // ���ùؿ��������ڲ�ͬ��
	/*
protected:
	int step;
	Map map;
	Text* levelText;
	Text* stepText;
	Text* bestText;
	*/
	//��Ϊһ����ͼ��
	bool player_down = 0;//����Ƿ��п��������ɫ�İ���������
	Map map;
	Node* mapLayer;
	Player* player;
};