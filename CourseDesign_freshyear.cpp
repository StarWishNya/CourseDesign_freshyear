#include<algorithm>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include"student_class.h"
#include"ui.h"
#include"StudentManager.h"
void test() {
	std::cout << chn_menu() << endl;
	classes.newclass("class1");
	classes.newclass("class2");
	classes.newclass("class3");
	std::string classname = classchoose()->classname;
	Student_class* class1 = classes.findclass("class1");
	printstu("202100101100", *class1);
	class1->add(addstu("张 三", "202100101100", 60));
	printstu("202100101100", *class1);
	class1->add(addstu("李 四", "202200101101", 85));
	printclass(*class1);
	printstat(*class1);
	delstu("202100101100", *class1);
	printclass(*class1);
	std::cout << encrypt(*class1, 1) << endl;
	std::cout << decrypt(encrypt(*class1, 1), 1) << endl;
	return;
}
int main() {
	//test();
	ui_control();
	return 0;
}