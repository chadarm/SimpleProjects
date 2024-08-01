#pragma once

#include "InputOutput.h"
#include <fstream>
#include <vector>
#include <string>



class ToDoList 
{
public:
	ToDoList(std::string fileLocation)
	{
		fileName = fileLocation;
	}
	void ShowTasks();
	void AddToTasks(std::string);
	void ReadFromFile();
	void WriteToFile();
	std::string fileName;
	std::vector<std::string> tasks;
};