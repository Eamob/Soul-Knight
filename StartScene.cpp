#include "StartScene.h"
#include "PlayScene.h"

StartScene::StartScene()
{
	//��ӱ���ͼ
	auto background = gcnew Sprite(L"res/start.jpg");
	background->setHeight(Window::getHeight());
	background->setWidth(Window::getWidth());
	background->setPos(0, 0);
	this->addChild(background);

	//�޸Ľڵ�Ĭ�����ĵ�λ��
	Node::setDefaultAnchor(0.5f, 0.5f);

	// �������� (���� Text �����塢��ϸ���ֺţ���ɫ�ȵ�����
	//����ֱ�Ϊ ���壬��С������
	auto fontNormal = Font(L"������", 28, Font::Weight::Bold);
	auto fontSelect = Font(L"������", 28, Font::Weight::Bold);
	auto fontDisable = Font(L"������", 28, Font::Weight::Bold);

	// ������ʽ
	auto styleNormal = Text::Style(Color::YellowGreen);
	auto styleSelect = Text::Style(Color::Blue);
	auto styleDisable = Text::Style(Color::LightGray);


	//��ʼ��ť
	auto startBtn = gcnew Button();
	startBtn->setNormal(gcnew Text(L"New Game", fontNormal, styleNormal));//������������°�ť��״̬
	startBtn->setMouseOver(gcnew Text(L"New Game", fontSelect, styleSelect));//���õ����ͣ���ڰ�ť��ʱ��ť��״̬
	startBtn->setPos(Window::getWidth() / 2, Window::getHeight()*3/6);// ���ð�ťλ��
	startBtn->setClickFunc(std::bind(&StartScene::Start, this));	// ���ð�ť�ص�������ע�⣬�����bind��ʾ�󶨣����ǽ�this��Ϊstart�Ĳ����󶨵�һ��
	this->addChild(startBtn);


	// ������Ϸ��ť
	resumeBtn = gcnew Button();
	resumeBtn->setNormal(gcnew Text(L"Continue ", fontNormal, styleNormal));
	resumeBtn->setMouseOver(gcnew Text(L"Continue ", fontSelect, styleSelect));
	resumeBtn->setDisabled(gcnew Text(L"Continue ", fontDisable, styleDisable));
	// ���ð�ťλ��
	resumeBtn->setPos(Window::getWidth() / 2, Window::getHeight()*4/6);
	// ����ǰ�ؿ��ǵ�һ�����䣬���������ť

	/***�����һ���ж�˵�Ƿ��ǵ�һ�����䣬Ȼ��set unable
	/*if (g_CurrentLevel == 1)
	{
		resumeBtn->setEnable(false);
	}*/
	// ���ð�ť�ص�����
	resumeBtn->setClickFunc(std::bind(&StartScene::Continue, this));
	this->addChild(resumeBtn);


	// �����˳���ť
	auto exitBtn = gcnew Button();
	exitBtn->setNormal(gcnew Text(L"Exit", fontNormal, styleNormal));
	exitBtn->setMouseOver(gcnew Text(L"Exit", fontSelect, styleSelect));
	// ���ð�ťλ��
	exitBtn->setPos(Window::getWidth() / 2, Window::getHeight()*5/6);
	// ���ð�ť�ص�����
	exitBtn->setClickFunc(std::bind(&StartScene::Exit, this));
	this->addChild(exitBtn);


	/*** �����������ذ�ť
	soundBtn = gcnew Button(gcnew Sprite(g_SoundOpen ? L"res/soundon.png" : L"res/soundoff.png"));
	// ���ð�ťλ��
	soundBtn->setPos(50, 50);
	// ���ð�ť�ص�����
	soundBtn->setClickFunc(std::bind(&StartScene::Sound, this));
	this->addChild(soundBtn);
	*/


	// �ָ��ڵ�Ĭ�����ĵ�λ��
	Node::setDefaultAnchor(0, 0);
}

// ��������ڽ��볡��ʱ�Զ�ִ�У������ڹ��캯��
void StartScene::onEnter()
{
	/***�����ж��Ƿ�Ϊ��һ������
	// ��ǰ�ؿ���Ϊ 1 ʱ�����Լ�����Ϸ
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
	/***������ʽ��Ϸ����*/
	// ���� PlayScene ����
	auto StartGame = gcnew PlayScene(1);
	// �л��� PlayScene ����
	SceneManager::enter(StartGame);
}

void StartScene::Continue()
{
	/***������ʽ��Ϸ�����������g_CurrentLevel���ǵ�ǰ�ؿ�
	// ���� PlayScene ����
	auto scene = gcnew PlayScene(g_CurrentLevel);
	// �л��� PlayScene ����
	SceneManager::enter(scene);
	*/
}

void StartScene::Exit()
{
	// �˳���Ϸ
	Game::quit();
}

void StartScene::Sound()
{
	/***��������
	// ��ȡ��ť״̬
	if (!g_SoundOpen)
	{
		// ������������
		MusicPlayer::resume(L"res/background.wav");
		soundBtn->setNormal(gcnew Sprite(L"res/soundon.png"));
		g_SoundOpen = true;
	}
	else
	{
		// ��ͣ��������
		MusicPlayer::pause(L"res/background.wav");
		soundBtn->setNormal(gcnew Sprite(L"res/soundoff.png"));
		g_SoundOpen = false;
	}
	// ������Ϣ���ļ�
	Data::saveBool(L"sound", g_SoundOpen);
	*/
}
