#pragma once


#include <fstream>
#include <string>
#include <vector>



class FileObject
{
public:
	FileObject() {}
	FileObject(std::string path) : filePath(path) {}

	void WriteStringToFile(std::string input);
	void WriteStringsToFile(std::vector<std::string> input);

	std::string ReadStringFromFile();
	std::vector<std::string> ReadStringsFromFile();

private:
	std::string filePath;
};