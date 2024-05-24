#include<algorithm>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include"student_class.h"
#include"func.h"
using namespace std;
int main() {
	/*for (int i = 1; i <= 2; i++) {
		newclass("class" + to_string(i));
	}
	StudentManage& class1 = class_map["class1"];
	StudentManage& class2 = class_map["class2"];*/
	StudentManage class1;
	addstu("Tom Jer", "20210001", 90, class1);
	addstu("Jer Tom", "20210002", 80, class1);
	cout << chn_menu() << endl;
	//addstu("Tom Jer", "20210003", 70, class2);
	/*for (auto it = class_map.begin(); it != class_map.end(); ++it) {
		string classname = it->first;
		StudentManage theclass = it->second;
		cout << theclass.classname << endl;
		printclass(theclass);
	}*/
	cout << encrypt(class1, 1) << endl;
	cout << decrypt(encrypt(class1, 1), 1) << endl;
	cout << class1.search("20210001").first_name << endl;
	printstat(class1);
	delstu("20210001", class1);
	printclass(class1);
	return 0;
}