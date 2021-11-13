//test
#include<easy2d/easy2d.h>
#include"StartScene.h"
#include"Data.h"
using namespace easy2d;

void Init();

int main()
{
	Logger::showConsole(false);
	// ��ʼ����Ϸ, Game::init ����Ĭ�ϻᴴ��һ�� 800x600 ��С�Ĵ��ڣ���ʼ��ʱҲ�������ô��ڵı���ʹ�С��
	if (Game::init(L"fortest", WINDOW_WIDTH * BRICK_WIDTH, WINDOW_HEIGHT * BRICK_WIDTH))
	{
		// ��ʼ��������Դ�ļ�
		Init();

		// ���뿪ʼ����
		auto startScene = gcnew StartScene();
		SceneManager::enter(startScene);

		// ��ʼ��Ϸ
		Game::start();
	}

	// ������Ϸ��Դ
	Game::destroy();
	return 0;
}

void Init()
{
	/* Ԥ���������ļ�*/
	return;
	/*** Ԥ���������ļ�
	MusicPlayer::preload(L"res/background.wav");
	MusicPlayer::preload(L"res/boxmove.wav");
	MusicPlayer::preload(L"res/manmove.wav");
	// ѭ�����ű������֣�-1 ��ʾѭ������
	MusicPlayer::play(L"res/background.wav", -1);
	// ���ļ���ȡ�ؿ���Ϣ��δ��ȡ��ʱĬ��Ϊ 1
	g_CurrentLevel = Data::getInt(L"level", 1);
	// ���ļ���ȡ����������Ϣ��δ��ȡ��ʱĬ��Ϊ 1
	g_SoundOpen = Data::getBool(L"sound", true);
	if (!g_SoundOpen)
	{
		MusicPlayer::pause(L"res/background.wav");
	}*/
}