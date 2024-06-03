#pragma once
#include<conio.h>
#include<cstdlib>
#include<iostream>
#include<windows.h>
#include"student_class.h"
#include"StudentManager.h"
using std::cin;
using std::cout;
using std::endl;
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
void sleep(uint16_t time) {
	Sleep(time);
}
void clearsceen() {
	system("cls");
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
Classes classes;
Student_class *classchoose() {
	rgb_init();
	const std::map <std::string, Student_class>& class_map = classes.outclassmap();
	cout << "班级列表" << endl;
	auto flag = class_map.begin();
	uint16_t r = 255, g = 0, b = 0;
	for (auto iter = class_map.begin(); iter != class_map.end(); iter++) {//打印班级列表
		std::string classname = iter->first;
		classname += "\n";
		colorprint(classname, 255, 255, 255);
	}
	while (1) {//选择班级
		Direction dir = getArrowInput();
		if (dir == Direction::Up) {
			if (flag == class_map.begin()) {
				flag = class_map.end()--;
			} else {
				flag--;
			}
		}
		else if (dir == Direction::Down) {
			flag++;
			if (flag == class_map.end()) flag = class_map.begin();
		}
		else if (dir == Direction::Enter) {
			return &flag->second;
		}
		clearsceen();
		for (auto iter = class_map.begin(); iter != class_map.end(); iter++) {
			std::string classname = iter->first;
			classname += "\n";
			if (iter == flag) {
				colorprint(classname, 255, 0, 0);
			}
			else {
				colorprint(classname, 255, 255, 255);
			}
		}
	}
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
	colorprint("6. 选择班级\n", 255, 255, 255);
	colorprint("7. 退出\n", 255, 255, 255);
	while (1) {
		//获取方向键输入
		Direction dir = getArrowInput();
		if (dir == Direction::Up) {
			flag--;
			if (flag < 1) flag = 7;
		}
		else if (dir == Direction::Down) {
			flag++;
			if (flag > 7) flag = 1;
		}
		else if (dir == Direction::Enter) {
			return flag;
		}
		clearsceen();
		//设置颜色
		for (int i = 1; i <= 7; i++) {
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
				colorprint("6. 选择班级\n", r, g, b);
				break;
			case 7:
				colorprint("7. 退出\n", r, g, b);
				break;
			}
		}
	}
	return flag;
}
