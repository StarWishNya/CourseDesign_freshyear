
#include<algorithm>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Stat {
public:
	uint16_t a_plus = 0;
	uint16_t a = 0;
	uint16_t b_plus = 0;
	uint16_t b = 0;
	uint16_t c_plus = 0;
	uint16_t c = 0;
	uint16_t d = 0;
	uint16_t f = 0;
	uint16_t sum = 0;
};
class Student {
public:
	string first_name;//名字
	string last_name;//姓
	string student_id;//学号
	uint16_t score;//分数
	bool rebuild = false;//是否重修
	string getgpa(uint16_t);
	string gpa = getgpa(score);//绩点 A+, A, B+, B, C+, C, D, F
	uint16_t rank;//排名 成绩相同需并列
	Student(string first_name, string last_name, string student_id, uint16_t score, bool rebuild) {
		this->first_name = first_name;
		this->last_name = last_name;
		this->student_id = student_id;
		this->score = score;
		this->rebuild = rebuild;
		this->gpa = getgpa(score);
	}
	void add(string name, string id, uint16_t score);
};
string Student::getgpa(uint16_t score) {
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
void Student::add(string name, string id, uint16_t score) {
	string last_name = name.substr(0, name.find(" "));//名字
	string first_name = name.substr(name.find(" ") + 1);//姓
	bool rebuild = true;//是否重修
	if (id[3] == '2') {//2022开头的学号不需要重修，即第四位为2
		rebuild = false;
	}
	Student student(first_name, last_name, id, score, rebuild);
}
class StudentManage {
public:
	vector <Student> students;
	Stat statistics;
	void add(Student);
	void del(string id);
	Student search(string id);
	void sort_score();
	void statmaintain(string gpa, bool flag);
};
void StudentManage::add(Student student) {//添加学生信息
	students.push_back(student);
	statmaintain(student.gpa, true);
}
void StudentManage::del(string id) {//删除学生信息
	for (int i = 0; i < students.size(); i++) {
		if (students[i].student_id == id) {
			statmaintain(students[i].gpa, false);
			students.erase(students.begin() + i);
			break;
		}
	}
}
void StudentManage::statmaintain(string gpa, bool flag) {//维护统计信息
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
	}else if (gpa[0] == 'B') {
		if (gpa[1] == '+') {
			statistics.b_plus += cum;
		}
		else {
			statistics.b += cum;
		}
	}else if (gpa[0] == 'C') {
		if (gpa[1] == '+') {
			statistics.c_plus += cum;
		}
		else {
			statistics.c += cum;
		}
	}else if (gpa[0] == 'D') {
		statistics.d += cum;
	}
	else {
		statistics.f += cum;
	}
}
Student StudentManage::search(string id) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i].student_id == id) {
			return students[i];
		}
	}
}
void StudentManage::sort_score() {
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
int main()
{
    std::cout << "Hello World!\n";
}