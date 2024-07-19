#pragma once
#include <iostream>

double GetDoubleInput(std::string prompt);
int GetIntInput(std::string prompt);
char GetCharInput(std::string prompt, std::string acceptableChars);
void IgnoreRestOfInput();