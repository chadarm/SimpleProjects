//// ToDoList.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
#include "ToDoList.h"
//
//int main() { return 0; }
int main()
{
	ToDoList todoList = ToDoList("Tasks.txt");

	todoList.ReadFromFile();

	std::string task;
	char choice = '\n';

	do
	{
		PromptUser("A - Add a task");
		PromptUser("V - View tasks");
		PromptUser("Q - Quit");
		choice = GetCharInput("Enter your choice:\n", "AaVvQq");

		switch (choice)
		{
		case 'A':
		case 'a':
			task = GetStringInput("Enter a task:\n");
			todoList.AddToTasks(task);
			PromptUser("\n");
			break;
		case 'V':
		case 'v':
			todoList.ShowTasks();
			break;
		default:
			break;
		}

	} while (choice != 'Q' && choice != 'q');

	todoList.WriteToFile();
	return 0;
}

void ToDoList::ShowTasks()
{
	PromptUser("To-Do List:");
	for (int i = 0; i < tasks.size(); ++i)
	{
		std::cout << i + 1 << ". " << tasks[i] << std::endl;
	}
	PromptUser("\n");
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
