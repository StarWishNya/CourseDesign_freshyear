#pragma once
#include<vector>
#include<string>
#include"Student.h"
class Student_class {
public:
	std::vector <Student> students;
	Stat statistics;
	void add(Student);
	bool del(string id);
	Student search(string id);
	void sort_score();
	void statmaintain(string gpa, bool flag);
	std::string classname;
};

std::string Student::getgpa(uint16_t score) {
	if (score >= 93) {
		return "A+";
	}
	else if (score >= 85) {
		return "A";
	}
	else if (score >= 80) {
		return "B+";
	}
	else if (score >= 75) {
		return "B";
	}
	else if (score >= 70) {
		return "C+";
	}
	else if (score >= 65) {
		return "C";
	}
	else if (score >= 60) {
		return "D";
	}
	else {
		return "F";
	}
}
void Student_class::add(Student student) {//添加学生信息
	students.push_back(student);
	statmaintain(student.gpa, true);
}
bool Student_class::del(string id) {//删除学生信息
	for (int i = 0; i < students.size(); i++) {
		if (students[i].student_id == id) {
			statmaintain(students[i].gpa, false);
			students.erase(students.begin() + i);
			return true;
		}
	}
	return false;
}
void Student_class::statmaintain(string gpa, bool flag) {//维护统计信息
	int cum = 1;
	if (flag == false) {
		cum = -1;
	}
	if (gpa[0] == 'A') {
		if (gpa[1] == '+') {
			statistics.a_plus += cum;
		}
		else {
			statistics.a += cum;
		}
	}
	else if (gpa[0] == 'B') {
		if (gpa[1] == '+') {
			statistics.b_plus += cum;
		}
		else {
			statistics.b += cum;
		}
	}
	else if (gpa[0] == 'C') {
		if (gpa[1] == '+') {
			statistics.c_plus += cum;
		}
		else {
			statistics.c += cum;
		}
	}
	else if (gpa[0] == 'D') {
		statistics.d += cum;
	}
	else {
		statistics.f += cum;
	}
	statistics.sum += cum;
	sort_score();
}
Student Student_class::search(string id) {//查找学生信息
	for (int i = 0; i < students.size(); i++) {
		if (students[i].student_id == id) {
			return students[i];
		}
	}
	return Student("#", "#", "#", 0, false);
}
void Student_class::sort_score() {//按成绩排序
	sort(students.begin(), students.end(), [](Student a, Student b) {
		return a.score > b.score;
		});
	int rank = 1;
	for (int i = 0; i < students.size(); i++) {//排名
		students[i].rank = rank;
		if (i < students.size() - 1 && students[i].score != students[i + 1].score) {//成绩相同需并列
			rank++;
		}
	}
}