#pragma once
#include<fstream>
#include<iostream>
#include"StudentManager.h"
Classes classes;
void loadclasslist() {
    std::fstream file;
    file.open("data\\classlist.txt", std::ios::in | std::ios::out | std::ios::app);
    //检查是否成功打开文件
    if (!file.is_open()) {
        // 文件不存在，创建文件
        file.open("data\\classlist.txt", std::ios::out);
        if (!file.is_open()) {
            // 创建文件失败
            std::cout << "无法创建文件" << std::endl;
            return;
        }
    }
    /*文件格式：
    Classlist:
    classname;
    clsssname;
    end;
    */
	// 读取文件
    std::string line;
	while (getline(file, line)) {
        if (line == "Classlist:") {
			continue;
		}
        if (line == "end;") {
			break;
		}
		line = line.substr(0, line.size() - 1);//去掉末尾的分号
		classes.newclass(line);
	}
	file.close();
}
void loadstudent(Student_class& classname) {
	std::fstream file;
	const std::string filename = "data\\" + classname.classname + ".txt";
	file.open(filename, std::ios::in | std::ios::out | std::ios::app);
	if (!file.is_open()) {
		file.open(filename, std::ios::out);
		if (!file.is_open()) {
			std::cout << "无法创建文件" << std::endl;
			return;
		}
	}
	/*文件格式：
	Studentlist:
	1:first_name,last_name,student_id,score;
	2:first_name,last_name,student_id,score;
	end;
	*/
	std::string line;
	while (getline(file, line)) {
		if (line == "Studentlist:") {
			continue;
		}
		if (line == "end;") {
			break;
		}
		std::string first_name, last_name, student_id, score, rebuild;
		uint16_t i = 0;
		while (line[i] != ',') {
			first_name += line[i];
			i++;
		}
		i++;
		while (line[i] != ',') {
			last_name += line[i];
			i++;
		}
		i++;
		while (line[i] != ',') {
			student_id += line[i];
			i++;
		}
		i++;
		while (line[i] != ',') {
			score += line[i];
			i++;
		}
		i++;
		while (line[i] != ';') {
			rebuild += line[i];
			i++;
		}
		bool rebuildflag;
		if (rebuild == "true") {
			rebuildflag = true;
		}
		else {
			rebuildflag = false;
		}
		classname.add(Student(first_name, last_name, student_id, std::stoi(score), rebuildflag));
	}
	file.close();
}
void writeclasslist() {
    std::ofstream file("data\\classlist.txt");
    if (!file.is_open()) {
        std::cout << "无法创建文件" << std::endl;
        return;
    }
    file << "Classlist:" << std::endl;
    const std::map<std::string, Student_class>& class_map = classes.outclassmap();
    for (const auto& iter : class_map) {
        file << iter.first << ";" << std::endl;
    }
    file << "end;" << std::endl;
    file.close();
}
void writestudentlist(Student_class& classname) {
	std::ofstream file("data\\" + classname.classname + ".txt");
	if (!file.is_open()) {
		std::cout << "无法创建文件" << std::endl;
		return;
	}
	file << "Studentlist:" << std::endl;
	for (const auto& iter : classname.students) {
		file << iter.first_name << "," << iter.last_name << "," << iter.student_id << "," << iter.score << "," << iter.rebuild << ";" << std::endl;
	}
	file << "end;" << std::endl;
	file.close();
}