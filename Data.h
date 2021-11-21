#pragma once

#define BRICK_WIDTH 30     // ש��߳� 

#define WINDOW_WIDTH  30  // �ܴ��ڿ�ȣ���λ��BRICK_WIDTH��
#define WINDOW_HEIGHT 16   // �ܴ��ڸ߶ȣ���λ��BRICK_WIDTH��

//��ͼ��С
#define MAP_WIDTH 14     // ��Ϸ����ȣ���λ��BRICK_WIDTH��
#define MAP_HEIGHT 14    // ��Ϸ���߶ȣ���λ��BRICK_WIDTH��


//����ؿ���Ŀ����ʱ���ó�1
#define MAX_LEVEL 1

extern int BULLET_INIT; //���������ʼ���ӵ���(���ں������ӵ�����Ŀ��仯���������óɱ���)(��Դ�ļ�PlayScene.cpp�ж���)

/* ��������ڴ�����Ϸ�ĵ�ͼ�ڲ����ݽṹ
* 
* ��ͼԪ�����ͣ�TYPE������5�֣��ֱ���ǽ�����桢����
* ��ͼ�飨Piece���ṹ���� ����TYPE �������������
* ��ͼ��Map���ṹ���ɿ�ȸ߶ȡ���ɫ��ʼ���ꡢ�� Piece���� ���

*/

// ��ͼԪ������
// Empty    ��
// Ground	����
// Wall		ǽ
// Box		����
enum TYPE {Empty=0, Ground, Wall};

// ��ͼ
struct Map
{
	// ��ͼ���
	int width;
	int height;
	// ��ͼ
	TYPE value[20][20];
};


// �����ؿ���Ŀ
extern Map g_Maps[MAX_LEVEL];
// ��ǰ����
extern int g_CurrentLevel;
/*
// �����Ƿ��
extern bool g_SoundOpen;
// ���﷽��1234 �ֱ���� ��������
extern int g_Direct;
// ���Ƿ�����������
extern bool g_Pushing;
*/