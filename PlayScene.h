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
	int randomObj; //�������ӵ�����Ʒ�������
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

	//һЩ���߶���
	Prop* trap;//����
	Prop* box;//����
	std::vector<Bullet*> bullets; //������ӵ�����ֱ�ӷ��ڳ���

};