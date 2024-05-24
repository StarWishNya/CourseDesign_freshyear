#pragma once
#include<vector>
#include"student_class.h"
string encrypt(StudentManage students, int key) {
	string result = "";
	for (int i = 0; i < students.students.size(); i++) {
		result += to_string(students.students[i].score);
	}
	for (int i = 0; i < result.size(); i++) {
		result[i] += key;
		if (result[i] > '9') {
			result[i] -= 10;
		}
	}
	return result;
}
string decrypt(string result, int key) {
	for (int i = 0; i < result.size(); i++) {
		result[i] -= key;
		if (result[i] < '0') {
			result[i] += 10;
		}
	}
	return result;
}
void addstu(string name, string id, uint16_t score, StudentManage& whole_class) {//添加学生信息
	string last_name = name.substr(0, name.find(" "));//名字
	string first_name = name.substr(name.find(" ") + 1);//姓
	bool rebuild = true;//是否重修
	if (id[3] == '2') {//2022开头的学号不需要重修，即第四位为2
		rebuild = false;
	}
	Student student(first_name, last_name, id, score, rebuild);//创建学生对象
	whole_class.add(student);
}
void printclass(StudentManage& whole_class) {//打印班级信息
	printf("姓名     学号     是否重修     GPA     成绩     排名\n");
	for (int i = 0; i < whole_class.students.size(); i++) {
		printf("%s %s %4s %4s ", whole_class.students[i].last_name.c_str(), whole_class.students[i].first_name.c_str(), whole_class.students[i].student_id.c_str(), whole_class.students[i].rebuild ? "是" : "否");
		printf("%11s %8d %7d\n", whole_class.students[i].gpa.c_str(), whole_class.students[i].score, i + 1);
	}
}
void printstu(string id, StudentManage whole_class) {//打印学生信息
	Student student = whole_class.search(id);
	printf("姓名     学号     是否重修     GPA     成绩     排名\n");
	printf("%s %s %4s %4s ", student.last_name.c_str(), student.first_name.c_str(), student.student_id.c_str(), student.rebuild ? "是" : "否");
	printf("%11s %8d %7d\n", student.gpa.c_str(), student.score, whole_class.search(id).rank);
}
void delstu(string id, StudentManage& whole_class) {//删除学生信息
	printstu(id, whole_class);
	cout << "是否删除该学生信息？(y/n)" << endl;
	char choice;
	cin >> choice;
	if (choice == 'y') {
		cout << "已删除" << endl;
		whole_class.del(id);

	}
	else {
		cout << "已取消删除" << endl;
	}
}
void printstat(StudentManage whole_class) {
	cout << "A+数量: " << whole_class.statistics.a_plus << endl;
	cout << "A数量: " << whole_class.statistics.a << endl;
	cout << "B+数量: " << whole_class.statistics.b_plus << endl;
	cout << "B数量: " << whole_class.statistics.b << endl;
	cout << "C+数量: " << whole_class.statistics.c_plus << endl;
	cout << "C数量: " << whole_class.statistics.c << endl;
	cout << "D数量: " << whole_class.statistics.d << endl;
	cout << "F数量: " << whole_class.statistics.f << endl;
}