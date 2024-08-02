#include "FileIO.h"



void FileObject::WriteStringToFile(std::string input)
{
	std::ofstream outputFile(filePath);
	outputFile << input;
	outputFile.close();
}

void FileObject::WriteStringsToFile(std::vector<std::string> input)
{
	std::ofstream outputFile(filePath);
	for (const auto& t : input)
	{
		outputFile << t << std::endl;
	}
	outputFile.close();
}

std::string FileObject::ReadStringFromFile()
{
	std::string ret = "";

	std::ifstream inputFile(filePath);
	std::string line;
	while (getline(inputFile, line))
	{
		ret.append(line);
		ret.append("\n");
	}
	inputFile.close();

	return ret;
}

std::vector<std::string> FileObject::ReadStringsFromFile()
{
	std::vector<std::string> ret;
	std::ifstream inputFile(filePath);
	
	std::string line;
	while (getline(inputFile, line))
	{
		ret.emplace_back(line);
	}
	inputFile.close();

	return ret;
}
