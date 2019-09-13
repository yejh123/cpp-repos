#pragma once
#ifndef FILE_H
#define FILE_H
#include "Student.h"

class File {
private:
	string fileName;
public:
	//File() = default;
	File(string fileName = "students.txt"):fileName(fileName) {
		fstream fileStream("C:\\files",ofstream::app);
		fileStream.close();
	}
	File(const File& file) {
		fileName = file.fileName;
	}
	
	File& operator=(const File& file) {
		fileName = fileName;
	}

	void add()
};

#endif // !FILE_H

