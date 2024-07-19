#pragma once

#include <iostream>


bool UserInteraction();
void PrintResult(double num1, double num2, char operation);
double GetDoubleInput(std::string prompt);
char GetCharInput(std::string prompt, std::string acceptableChars);
void IgnoreRestOfInput();
