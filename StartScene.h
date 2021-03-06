#pragma once
#include <easy2d/easy2d.h>
using namespace easy2d;

//作为开始界面的类
class StartScene : public Scene
{
public:
	StartScene();

	// 这个函数在进入场景时自动执行
	void onEnter() override;

	// 新游戏
	void Start();
	// 继续游戏
	void Continue();
	// 退出游戏
	void Exit();

	// 打开或关闭声音
	void Sound();

protected:
	// 声音开关
	//Button* soundBtn;
	// 继续游戏按钮
	Button* resumeBtn;

};
