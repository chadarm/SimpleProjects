//#pragma once
//
#include "InputOutput.h"
#include "FileIO.h"


bool UserInteraction();

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