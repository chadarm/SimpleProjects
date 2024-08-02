
#include "BasicEncrypt.h"

void EncryptFile(std::string filePath, int key)
{
	std::ifstream inputFile(filePath, std::ios::binary);
	std::ofstream outputFile(filePath, std::ios::binary);

	char ch;
	while (inputFile.get(ch))
	{
		outputFile.put(ch + key);
	}

	inputFile.close();
	outputFile.close();
}

void DecryptFile(std::string filePath, int key)
{
	std::ifstream inputFile(filePath, std::ios::binary);
	std::ofstream outputFile(filePath, std::ios::binary);

	char ch;
	while (inputFile.get(ch))
	{
		outputFile.put(ch - key);
	}

	inputFile.close();
	outputFile.close();
}
