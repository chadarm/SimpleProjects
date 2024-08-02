#pragma once


#include <iostream>
#include <fstream>
#include <string>

// Basic Caesar Cipher using char shifting by a specified key

void EncryptFile(std::string filePath, int key);
void DecryptFile(std::string filePath, int key);