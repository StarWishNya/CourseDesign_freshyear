#pragma once
#include<vector>
#include<string>
#include<map>
#include"student_class.h"
class Classes {
	std::map<std::string, Student_class> class_map{};
public:
	bool newclass(const std::string& classname);
	Student_class* findclass(const std::string& classname);
	std::map<std::string, Student_class>& outclassmap();
};
Student_class* Classes::findclass(const std::string& classname) {
	auto iter = class_map.find(classname);
	if (iter == class_map.end()) {
		return nullptr;
	}
	return &iter->second;
}
bool Classes::newclass(const std::string& classname) {
	if (findclass(classname) != nullptr) {
		return false;
	}
	class_map.emplace(classname, Student_class());
	class_map.find(classname)->second.classname = classname;
	return true;
}
std::map<std::string, Student_class>& Classes::outclassmap(){
	return class_map;
}
