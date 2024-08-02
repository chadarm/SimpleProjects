// TempConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "TempConverter.h"

int main()
{
    bool running = true;
    do
    {
        running = UserInteraction();
    } while (running);
    return 0;
}

bool UserInteraction()
{
    int choice;
    double temperature, convertedTemperature;

    PromptUser(Menu);

    choice = GetIntInput("Enter your choice (1-5):\n");
    if (choice == 5)
    {
        return false;
    }

    temperature = GetDoubleInput("Enter the temperature:\n");

    switch (choice)
    {
    case 1:
        convertedTemperature = CelsiusToFahrenheit(temperature);
        break;
    case 2:
        convertedTemperature = FahrenheitToCelsius(temperature);
        break;
    case 3:
        convertedTemperature = CelsiusToKelvin(temperature);
        break;
    case 4:
        convertedTemperature = KelvinToCelsius(temperature);
        break;
    default:
        PromptUser("Invalid choice.");
        PromptUser("\n");
        return true;
    }

    std::cout << "Converted Temperature: " << convertedTemperature << std::endl;
    PromptUser("\n");
    return true;
}


double CelsiusToFahrenheit(double celsius)
{
    return (celsius * 9.0 / 5.0) + 32.0;
}

double FahrenheitToCelsius(double fahrenheit)
{
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double CelsiusToKelvin(double celsius)
{
    return celsius + 273.15;
}

double KelvinToCelsius(double kelvin)
{
    return kelvin - 273.15;
}

