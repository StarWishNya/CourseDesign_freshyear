#pragma once
#include<vector>
#include<string>
using namespace std;
class Stat {//ͳ����Ϣ
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
	string first_name;//����
	string last_name;//��
	string student_id;//ѧ��
	uint16_t score;//����
	bool rebuild = false;//�Ƿ�����
	string getgpa(uint16_t);
	string gpa = getgpa(score);//���� A+, A, B+, B, C+, C, D, F
	uint16_t rank;//���� �ɼ���ͬ�貢��
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
class StudentManage {//ѧ������
public:
	vector <Student> students;
	Stat statistics;
	void add(Student);
	void del(string id);
	Student search(string id);
	void sort_score();
	void statmaintain(string gpa, bool flag);
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
void StudentManage::add(Student student) {//���ѧ����Ϣ
	students.push_back(student);
	statmaintain(student.gpa, true);
}
void StudentManage::del(string id) {//ɾ��ѧ����Ϣ
	for (int i = 0; i < students.size(); i++) {
		if (students[i].student_id == id) {
			statmaintain(students[i].gpa, false);
			students.erase(students.begin() + i);
			break;
		}
	}
}
void StudentManage::statmaintain(string gpa, bool flag) {//ά��ͳ����Ϣ
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
}
Student StudentManage::search(string id) {//����ѧ����Ϣ
	for (int i = 0; i < students.size(); i++) {
		if (students[i].student_id == id) {
			return students[i];
		}
	}
	return Student("#", "#", "#", 0, false);
}
void StudentManage::sort_score() {//���ɼ�����
	sort(students.begin(), students.end(), [](Student a, Student b) {
		return a.score > b.score;
		});
	int rank = 1;
	for (int i = 0; i < students.size(); i++) {//����
		students[i].rank = rank;
		if (i < students.size() - 1 && students[i].score != students[i + 1].score) {//�ɼ���ͬ�貢��
			rank++;
		}
	}
}
