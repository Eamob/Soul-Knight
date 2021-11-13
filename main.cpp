#include<easy2d/easy2d.h>
#include"StartScene.h"
#include"Data.h"
using namespace easy2d;

void Init();

int main()
{
	Logger::showConsole(false);
	// 初始化游戏, Game::init 函数默认会创建一个 800x600 大小的窗口，初始化时也可以设置窗口的标题和大小：
	if (Game::init(L"fortest", WINDOW_WIDTH * BRICK_WIDTH, WINDOW_HEIGHT * BRICK_WIDTH))
	{
		// 初始化音乐资源文件
		Init();

		// 进入开始场景
		auto startScene = gcnew StartScene();
		SceneManager::enter(startScene);

		// 开始游戏
		Game::start();
	}

	// 回收游戏资源
	Game::destroy();
	return 0;
}

void Init()
{
	/* 预加载音乐文件*/
	return;
	/*** 预加载音乐文件
	MusicPlayer::preload(L"res/background.wav");
	MusicPlayer::preload(L"res/boxmove.wav");
	MusicPlayer::preload(L"res/manmove.wav");
	// 循环播放背景音乐，-1 表示循环播放
	MusicPlayer::play(L"res/background.wav", -1);
	// 从文件读取关卡信息，未读取到时默认为 1
	g_CurrentLevel = Data::getInt(L"level", 1);
	// 从文件读取声音开关信息，未读取到时默认为 1
	g_SoundOpen = Data::getBool(L"sound", true);
	if (!g_SoundOpen)
	{
		MusicPlayer::pause(L"res/background.wav");
	}*/
}