#pragma once

#include "InputOutput.h"


bool UserInteraction();

std::string Menu("Temperature Converter\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Celsius to Kelvin\n4. Kelvin to Celsius\n5. Exit\n");

double CelsiusToFahrenheit(const double celsius);
double FahrenheitToCelsius(const double fahrenheit);
double CelsiusToKelvin(const double celsius);
double KelvinToCelsius(const double kelvin);