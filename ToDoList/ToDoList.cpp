// ToDoList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ToDoList.h"

int main()
{
	ToDoList todoList = ToDoList("Tasks.txt");

	todoList.ReadFromFile();

	std::string task;
	char choice;

	do
	{
		std::cout << "A - Add a task" << std::endl;
		std::cout << "V - View tasks" << std::endl;
		std::cout << "Q - Quit" << std::endl;
		choice = GetCharInput("Enter your choice", "AaVvQq");

		switch (choice)
		{
		case 'A':
		case 'a':
			task = GetStringInput("Enter a task: ");
			todoList.AddToTasks(task);
			break;
		case 'V':
		case 'v':
			todoList.ShowTasks();
			break;
		}

	} while (choice != 'Q' && choice != 'q');

}



void ToDoList::ShowTasks()
{
	std::cout << "To-Do List:" << std::endl;
	for (int i = 0; i < tasks.size(); ++i)
	{
		std::cout << i + 1 << ". " << tasks[i] << std::endl;
	}
}

void ToDoList::AddToTasks(std::string task)
{
	tasks.push_back(task);
}

void ToDoList::ReadFromFile()
{
	// Load existing tasks from file
	std::ifstream inputFile(fileName);
	std::string temp;
	while (getline(inputFile, temp))
	{
		AddToTasks(temp);
	}
	inputFile.close();
}

void ToDoList::WriteToFile()
{
	std::ofstream outputFile(fileName);
	for (const auto& t : tasks)
	{
		outputFile << t << std::endl;
	}
	outputFile.close();
}
