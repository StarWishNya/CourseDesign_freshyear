#pragma once
#include<conio.h>
#include<cstdlib>
#include<iostream>
#include<windows.h>
#include"student_class.h"
#include"StudentManager.h"
#include"loadfile.h"
#include"func.h"
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
void clearscreen() {
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
void paktc() {
	cout << "请按任意键继续..." << endl;
	_getch();
}
void colorprint(string str, uint16_t r, uint16_t g, uint16_t b) {
	rgb_init();
	rgb_set(r, g, b);
	cout << str;
	rgb_set(255, 255, 255);
}
Student_class* classchoose() {
	clearscreen();
	rgb_init();
	std::map <std::string, Student_class>& class_map = classes.outclassmap();
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
		if (dir == Direction::Up || dir == Direction::Left) {
			if (flag == class_map.begin()) {
				flag = class_map.end();
				flag--;
			}
			else {
				flag--;
			}
		}
		else if (dir == Direction::Down || dir == Direction::Right) {
			flag++;
			if (flag == class_map.end()) flag = class_map.begin();
		}
		else if (dir == Direction::Enter) {
			return &flag->second;
		}
		clearscreen();
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
	clearscreen();
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
		clearscreen();
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
void add_student(Student_class& classname) {
	clearscreen();
	cout << "请输入学生信息" << endl;
	cout << "姓：";
	std::string first_name;
	cin >> first_name;
	cout << "名：";
	std::string last_name;
	cin >> last_name;
	cout << "学号：";
	std::string student_id;
	cin >> student_id;
	cout << "成绩：";
	int score;
	cin >> score;
	classname.add(addstu(first_name + " " + last_name, student_id, score));
	paktc();
}
void show_all_students(Student_class& classname) {
	clearscreen();
	printclass(classname);
	paktc();
}
void search_student(Student_class& classname) {
	clearscreen();
	cout << "请输入学号" << endl;
	std::string id;
	cin >> id;
	printstu(id, classname);
	paktc();
}
void del_student(Student_class& classname) {
	clearscreen();
	cout << "请输入学号" << endl;
	std::string id;
	cin >> id;
	if (classname.del(id) == false) {
		cout << "Error" << endl;
	}
	else {
		delstu(id, classname);
	}
	paktc();
}
uint16_t edit_student_ui() {
	rgb_init();
	int flag = 1;
	uint16_t r = 255, g = 0, b = 0;
	colorprint("1. 修改姓氏\n", 255, 0, 0);
	colorprint("2. 修改名字\n", 255, 255, 255);
	colorprint("3. 修改学号\n", 255, 255, 255);
	colorprint("4. 修改成绩\n", 255, 255, 255);
	colorprint("5. 退出\n", 255, 255, 255);
	while (1) {
		//获取方向键输入
		Direction dir = getArrowInput();
		if (dir == Direction::Up || dir == Direction::Left) {
			flag--;
			if (flag < 1) flag = 5;
		}
		else if (dir == Direction::Down || dir == Direction::Right) {
			flag++;
			if (flag > 5) flag = 1;
		}
		else if (dir == Direction::Enter) {
			return flag;
		}
		clearscreen();
		//设置颜色
		for (int i = 1; i <= 5; i++) {
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
				colorprint("1. 修改姓氏\n", r, g, b);
				break;
			case 2:
				colorprint("2. 修改名字\n", r, g, b);
				break;
			case 3:
				colorprint("3. 修改学号\n", r, g, b);
				break;
			case 4:
				colorprint("4. 修改成绩\n", r, g, b);
				break;
			case 5:
				colorprint("5. 退出\n", r, g, b);
				break;
			}
		}
	}
}
void edit_student(Student_class& classname) {
	clearscreen();
	cout << "请输入学号" << endl;
	std::string id;
	cin >> id;
	Student& student = classname._search(id);
	if (student.first_name == "#" && student.last_name == "#" && student.student_id == "#") {
		cout << "Error" << endl;
		paktc();
		return;
	}
	else {
		printstu(id, classname);
	}
	cout << "请选择要修改的信息" << endl;
	uint16_t choice = edit_student_ui();
	switch (choice) {
	case 1: {
		cout << "请输入新的姓" << endl;
		std::string first_name;
		cin >> first_name;
		student.first_name = first_name;
		break;
	}
	case 2: {
		cout << "请输入新的名" << endl;
		std::string last_name;
		cin >> last_name;
		student.last_name = last_name;
		break;
	}
	case 3: {
		cout << "请输入新的学号" << endl;
		std::string student_id;
		cin >> student_id;
		student.student_id = student_id;
		break;
	}
	case 4: {
		cout << "请输入新的成绩" << endl;
		int score;
		cin >> score;
		student.score = score;
		break;
	}
	case 5:
		return;
	}
	paktc();
}
void ui_control() {
	loadclasslist();
	Student_class* classmanager = classchoose();
	loadstudent(*classmanager);
	bool classmanagerflag = true;
	while (1) {
		if (classmanagerflag == false) {
			writestudentlist(*classmanager);
			classmanager = classchoose();
			loadstudent(*classmanager);
			classmanagerflag = true;
		}
		uint16_t choice = chn_menu();
		switch (choice) {
		case 1: {
			add_student(*classmanager);
			clearscreen();
			break;
		}
		case 2: {
			show_all_students(*classmanager);
			clearscreen();
			break;
		}
		case 3: {
			search_student(*classmanager);
			clearscreen();
			break;
		}
		case 4: {
			edit_student(*classmanager);
			clearscreen();
			break;
		}
		case 5: {
			del_student(*classmanager);
			clearscreen();
			break;
		}
		case 6: {
			classmanagerflag = false;
			break;
		}
		case 7: {
			for (auto iter = classes.outclassmap().begin(); iter != classes.outclassmap().end(); iter++) {
				writestudentlist(iter->second);
			}
			return;
		}
		}
	}
}