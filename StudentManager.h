#pragma once
#include<vector>
#include<string>
#include<map>
#include"student_class.h"
class Classes {
	std::map<std::string, Student_class> class_map{};
public:
	void newclass(const std::string& classname);
	Student_class* findclass(const std::string& classname);
};
void Classes::newclass(const std::string& classname){
	class_map.emplace(classname, Student_class());
}
Student_class* Classes::findclass(const std::string& classname) {
	auto iter = class_map.find(classname);
	if (iter == class_map.end()) {
		return nullptr;
	}
	return &iter->second;
}