
#include<algorithm>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include"student_class.h"
#include"func.h"
using namespace std;
int main() {
	StudentManage class1;
	addstu("Tom Jerry", "20210001", 90, class1);
	addstu("Jerry Tom", "20210002", 80, class1);
	for (int i = 0; i < class1.students.size(); i++) {
		cout << class1.students[i].first_name << " " << class1.students[i].last_name << " " << class1.students[i].student_id << " " << class1.students[i].score << " " << class1.students[i].gpa << " " << class1.students[i].rank << endl;
	}
	cout << encrypt(class1, 1) << endl;
	cout << decrypt(encrypt(class1, 1), 1) << endl;
	cout << class1.search("20210001").first_name << endl;
	cout << class1.statistics.a << endl;
	return 0;
}