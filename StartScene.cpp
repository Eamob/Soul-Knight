#include "StartScene.h"
#include "PlayScene.h"

StartScene::StartScene()
{
	//添加背景图
	auto background = gcnew Sprite(L"res/start.jpg");
	background->setHeight(Window::getHeight());
	background->setWidth(Window::getWidth());
	background->setPos(0, 0);
	this->addChild(background);

	//修改节点默认中心点位置
	Node::setDefaultAnchor(0.5f, 0.5f);

	// 创建字体 (用于 Text 的字体、粗细、字号，颜色等等属性
	//这里分别为 字体，大小，粗体
	auto fontNormal = Font(L"新宋体", 28, Font::Weight::Bold);
	auto fontSelect = Font(L"新宋体", 28, Font::Weight::Bold);
	auto fontDisable = Font(L"新宋体", 28, Font::Weight::Bold);

	// 创建样式
	auto styleNormal = Text::Style(Color::YellowGreen);
	auto styleSelect = Text::Style(Color::Blue);
	auto styleDisable = Text::Style(Color::LightGray);


	//开始按钮
	auto startBtn = gcnew Button();
	startBtn->setNormal(gcnew Text(L"New Game", fontNormal, styleNormal));//设置正常情况下按钮的状态
	startBtn->setMouseOver(gcnew Text(L"New Game", fontSelect, styleSelect));//设置当鼠标停留在按钮的时候按钮的状态
	startBtn->setPos(Window::getWidth() / 2, Window::getHeight()*3/6);// 设置按钮位置
	startBtn->setClickFunc(std::bind(&StartScene::Start, this));	// 设置按钮回调函数（注意，这里的bind表示绑定，就是讲this作为start的参数绑定到一起
	this->addChild(startBtn);


	// 继续游戏按钮
	resumeBtn = gcnew Button();
	resumeBtn->setNormal(gcnew Text(L"Continue ", fontNormal, styleNormal));
	resumeBtn->setMouseOver(gcnew Text(L"Continue ", fontSelect, styleSelect));
	resumeBtn->setDisabled(gcnew Text(L"Continue ", fontDisable, styleDisable));
	// 设置按钮位置
	resumeBtn->setPos(Window::getWidth() / 2, Window::getHeight()*4/6);
	// 若当前关卡是第一个房间，禁用这个按钮

	/***这里加一个判断说是否是第一个房间，然后set unable
	/*if (g_CurrentLevel == 1)
	{
		resumeBtn->setEnable(false);
	}*/
	// 设置按钮回调函数
	resumeBtn->setClickFunc(std::bind(&StartScene::Continue, this));
	this->addChild(resumeBtn);


	// 创建退出按钮
	auto exitBtn = gcnew Button();
	exitBtn->setNormal(gcnew Text(L"Exit", fontNormal, styleNormal));
	exitBtn->setMouseOver(gcnew Text(L"Exit", fontSelect, styleSelect));
	// 设置按钮位置
	exitBtn->setPos(Window::getWidth() / 2, Window::getHeight()*5/6);
	// 设置按钮回调函数
	exitBtn->setClickFunc(std::bind(&StartScene::Exit, this));
	this->addChild(exitBtn);


	/*** 创建声音开关按钮
	soundBtn = gcnew Button(gcnew Sprite(g_SoundOpen ? L"res/soundon.png" : L"res/soundoff.png"));
	// 设置按钮位置
	soundBtn->setPos(50, 50);
	// 设置按钮回调函数
	soundBtn->setClickFunc(std::bind(&StartScene::Sound, this));
	this->addChild(soundBtn);
	*/


	// 恢复节点默认中心点位置
	Node::setDefaultAnchor(0, 0);
}

// 这个函数在进入场景时自动执行，类似于构造函数
void StartScene::onEnter()
{
	/***用于判断是否为第一个房间
	// 当前关卡不为 1 时，可以继续游戏
	if (g_CurrentLevel == 1)
	{
		resumeBtn->setEnable(false);
	}
	else
	{
		resumeBtn->setEnable(true);
	}
	*/
}

void StartScene::Start()
{
	/***创建正式游戏场景*/
	// 创建 PlayScene 场景
	auto StartGame = gcnew PlayScene(1);
	// 切换到 PlayScene 场景
	SceneManager::enter(StartGame);
}

void StartScene::Continue()
{
	/***创建正式游戏场景，这里的g_CurrentLevel就是当前关卡
	// 创建 PlayScene 场景
	auto scene = gcnew PlayScene(g_CurrentLevel);
	// 切换到 PlayScene 场景
	SceneManager::enter(scene);
	*/
}

void StartScene::Exit()
{
	// 退出游戏
	Game::quit();
}

void StartScene::Sound()
{
	/***处理音乐
	// 获取按钮状态
	if (!g_SoundOpen)
	{
		// 继续背景音乐
		MusicPlayer::resume(L"res/background.wav");
		soundBtn->setNormal(gcnew Sprite(L"res/soundon.png"));
		g_SoundOpen = true;
	}
	else
	{
		// 暂停背景音乐
		MusicPlayer::pause(L"res/background.wav");
		soundBtn->setNormal(gcnew Sprite(L"res/soundoff.png"));
		g_SoundOpen = false;
	}
	// 保存信息到文件
	Data::saveBool(L"sound", g_SoundOpen);
	*/
}
