#pragma once

#define BRICK_WIDTH 30     // 砖块边长 

#define WINDOW_WIDTH  30  // 总窗口宽度（单位：BRICK_WIDTH）
#define WINDOW_HEIGHT 16   // 总窗口高度（单位：BRICK_WIDTH）

//地图大小
#define MAP_WIDTH 14     // 游戏面板宽度（单位：BRICK_WIDTH）
#define MAP_HEIGHT 14    // 游戏面板高度（单位：BRICK_WIDTH）


//定义关卡数目，暂时设置成1
#define MAX_LEVEL 1

extern int BULLET_INIT; //定义人物初始的子弹数(由于后续捡到子弹，数目会变化，所以设置成变量)(在源文件PlayScene.cpp中定义)

/* 这个类用于储存游戏的地图内部数据结构
* 
* 地图元素类型（TYPE）共有5种，分别是墙、地面、箱子
* 地图块（Piece）结构体由 属性TYPE 和其他属性组成
* 地图（Map）结构体由宽度高度、角色起始坐标、和 Piece数组 组成

*/

// 地图元素类型
// Empty    空
// Ground	地面
// Wall		墙
// Box		箱子
enum TYPE {Empty=0, Ground, Wall};

// 地图
struct Map
{
	// 地图宽高
	int width;
	int height;
	// 地图
	TYPE value[20][20];
};


// 声明关卡数目
extern Map g_Maps[MAX_LEVEL];
// 当前房间
extern int g_CurrentLevel;
/*
// 声音是否打开
extern bool g_SoundOpen;
// 人物方向，1234 分别代表 上下左右
extern int g_Direct;
// 人是否正在推箱子
extern bool g_Pushing;
*/