//#pragma once
//
#include "InputOutput.h"
#include "FileIO.h"
#include <fstream>
#include <vector>
#include <string>


class ToDoList 
{
public:
	ToDoList(std::string fileLocation)
	{
		file = FileObject(fileLocation);
	}
	void ShowTasks();
	void AddToTasks(std::string);
	void ReadFromFile();
	void WriteToFile();
	std::vector<std::string> tasks;
private:
	FileObject file;
};