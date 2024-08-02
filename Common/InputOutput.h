#pragma once
#include <iostream>
#include <string>

double GetDoubleInput(std::string prompt);
int GetIntInput(std::string prompt);
char GetCharInput(std::string prompt, std::string acceptableChars);
std::string GetStringInput(std::string prompt);
void IgnoreRestOfInput();
void PromptUser(std::string prompt);