#include<algorithm>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include"student_class.h"
#include"func.h"
#include"StudentManager.h"
using namespace std;
int main() {
	cout << chn_menu() << endl;
	Classes classes{};
	classes.newclass("class1");
	Student_class* class1 = classes.findclass("class1");
	//Student_class class1;
	printstu("202100101100", *class1);
	class1->add(addstu("张 三", "202100101100", 60));
	printstu("202100101100", *class1);
	class1->add(addstu("李 四", "202200101101", 85));
    printclass(*class1);
	printstat(*class1);
	delstu("202100101100", *class1);
	printclass(*class1);
	cout << encrypt(*class1, 1) << endl;
	cout << decrypt(encrypt(*class1, 1), 1) << endl;
	return 0;
}