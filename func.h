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
void printclass(StudentManage& whole_class) {//��ӡ�༶��Ϣ
	printf("����     ѧ��     �Ƿ�����     GPA     �ɼ�     ����\n");
	for (int i = 0; i < whole_class.students.size(); i++) {
		printf("%s %s %4s %4s ", whole_class.students[i].last_name.c_str(), whole_class.students[i].first_name.c_str(), whole_class.students[i].student_id.c_str(), whole_class.students[i].rebuild ? "��" : "��");
		printf("%11s %8d %7d\n", whole_class.students[i].gpa.c_str(), whole_class.students[i].score, i + 1);
	}
}
void printstu(string id, StudentManage whole_class) {//��ӡѧ����Ϣ
	Student student = whole_class.search(id);
	printf("����     ѧ��     �Ƿ�����     GPA     �ɼ�     ����\n");
	printf("%s %s %4s %4s ", student.last_name.c_str(), student.first_name.c_str(), student.student_id.c_str(), student.rebuild ? "��" : "��");
	printf("%11s %8d %7d\n", student.gpa.c_str(), student.score, whole_class.search(id).rank);
}
void delstu(string id, StudentManage& whole_class) {//ɾ��ѧ����Ϣ
	printstu(id, whole_class);
	cout << "�Ƿ�ɾ����ѧ����Ϣ��(y/n)" << endl;
	char choice;
	cin >> choice;
	if (choice == 'y') {
		cout << "��ɾ��" << endl;
		whole_class.del(id);

	}
	else {
		cout << "��ȡ��ɾ��" << endl;
	}
}
void printstat(StudentManage whole_class) {
	cout << "A+����: " << whole_class.statistics.a_plus << endl;
	cout << "A����: " << whole_class.statistics.a << endl;
	cout << "B+����: " << whole_class.statistics.b_plus << endl;
	cout << "B����: " << whole_class.statistics.b << endl;
	cout << "C+����: " << whole_class.statistics.c_plus << endl;
	cout << "C����: " << whole_class.statistics.c << endl;
	cout << "D����: " << whole_class.statistics.d << endl;
	cout << "F����: " << whole_class.statistics.f << endl;
}