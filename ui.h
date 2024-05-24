#pragma once
#include<conio.h>
#include<cstdlib>
#include<iostream>
#include<windows.h>
#include"student_class.h"
using namespace std;
enum class Direction {//方向
	Up,
	Down,
	Left,
	Right,
	Enter,
	unknown
};
Direction getArrowInput() {//获取方向键输入
	int key = _getch();
	switch (key) {
	case 72: // 上
		return Direction::Up;
	case 80: // 下
		return Direction::Down;
	case 75: // 左
		return Direction::Left;
	case 77: // 右
		return Direction::Right;
	case 13: // 回车
		return Direction::Enter;
	}
	return Direction::unknown;
}
void rgb_init() {
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);		//输入句柄
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);		//输出句柄
	DWORD dwInMode, dwOutMode;
	GetConsoleMode(hIn, &dwInMode);						//获取控制台输入模式
	GetConsoleMode(hOut, &dwOutMode);					//获取控制台输出模式
	dwInMode |= 0x0200;									//更改
	dwOutMode |= 0x0004;
	SetConsoleMode(hIn, dwInMode);						//设置控制台输入模式
	SetConsoleMode(hOut, dwOutMode);					//设置控制台输出模式
}
void rgb_set(int wr, int wg, int wb) {//设置RGB
	printf("\033[38;2;%d;%d;%dm", wr, wg, wb);	//\033[38表示前景，\033[48表示背景，三个%d表示混合的数
}
void sleep(int time) {
	Sleep(time);
}
/*void eng_menu() {
	system("cls");
	cout << "1. Add new student" << endl;
	cout << "2. Show all students" << endl;
	cout << "3. Search student" << endl;
	cout << "4. Edit student" << endl;
	cout << "5. Delete student" << endl;
	cout << "6. Exit" << endl;
}*/
void colorprint(string str, uint16_t r, uint16_t g, uint16_t b) {
	rgb_init();
	rgb_set(r, g, b);
	cout << str;
	rgb_set(255, 255, 255);
}
void classchoose() {

}
uint16_t chn_menu() {
	rgb_init();
	int flag = 1;
	uint16_t r = 255, g = 0, b = 0;
	colorprint("1. 添加学生\n", 255, 0, 0);
	colorprint("2. 显示所有学生\n", 255, 255, 255);
	colorprint("3. 查找学生\n", 255, 255, 255);
	colorprint("4. 编辑学生\n", 255, 255, 255);
	colorprint("5. 删除学生\n", 255, 255, 255);
	colorprint("6. 退出\n", 255, 255, 255);
	while (1) {
		//获取方向键输入
		Direction dir = getArrowInput();
		if (dir == Direction::Up) {
			flag--;
			if (flag < 1) flag = 6;
		}
		else if (dir == Direction::Down) {
			flag++;
			if (flag > 6) flag = 1;
		}
		else if (dir == Direction::Enter) {
			return flag;
		}
		system("cls");
		//设置颜色
		for (int i = 1; i <= 6; i++) {
			if (flag == i) {
				r = 255;
				g = 0;
				b = 0;
			}
			else {
				r = 255;
				g = 255;
				b = 255;
			}
			switch (i) {
			case 1:
				colorprint("1. 添加学生\n", r, g, b);
				break;
			case 2:
				colorprint("2. 显示所有学生\n", r, g, b);
				break;
			case 3:
				colorprint("3. 查找学生\n", r, g, b);
				break;
			case 4:
				colorprint("4. 编辑学生\n", r, g, b);
				break;
			case 5:
				colorprint("5. 删除学生\n", r, g, b);
				break;
			case 6:
				colorprint("6. 退出\n", r, g, b);
				break;
			}
		}
	}
	return flag;
}
/*void classchioce() {
	for (int i = 0; i < class_list.assign.size(); i++) {
		colorprint(class_list.assign[i].class_name, 255, 255, 255);
	}
}*/