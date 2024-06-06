#pragma once
#include<string>
using std::string;
struct Stat {//统计信息
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
	//void add(string name, string id, uint16_t score);
};