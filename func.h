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
void addstu(string name, string id, uint16_t score, StudentManage& whole_class) {//���ѧ����Ϣ
	string last_name = name.substr(0, name.find(" "));//����
	string first_name = name.substr(name.find(" ") + 1);//��
	bool rebuild = true;//�Ƿ�����
	if (id[3] == '2') {//2022��ͷ��ѧ�Ų���Ҫ���ޣ�������λΪ2
		rebuild = false;
	}
	Student student(first_name, last_name, id, score, rebuild);//����ѧ������
	whole_class.add(student);
}