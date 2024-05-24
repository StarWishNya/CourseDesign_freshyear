
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
	addstu("Tom Jer", "20210001", 90, class1);
	addstu("Jer Tom", "20210002", 80, class1);
	printclass(class1);
	cout << encrypt(class1, 1) << endl;
	cout << decrypt(encrypt(class1, 1), 1) << endl;
	cout << class1.search("20210001").first_name << endl;
	printstat(class1);
	delstu("20210001", class1);
	printclass(class1);
	return 0;
}