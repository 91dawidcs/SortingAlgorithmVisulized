// AlgorithmVisulized.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>

int ConsoleSizeColums();
int HowManyNumbers();
std::vector<int> ListNumbers();
std::vector<std::string> StringNumbers(std::vector<int> listOfNumbers);
void BubbleSort(std::vector<int> listOfNumbers, std::vector<std::string> stringNumbers);

int main() {

	std::vector<int> listOfNumbers = ListNumbers();
	std::vector<std::string> stringNumbers = StringNumbers(listOfNumbers);

	std::cout << std::endl;

	BubbleSort(listOfNumbers, stringNumbers);

	return 0;
}

int ConsoleSizeColums()
{

	CONSOLE_SCREEN_BUFFER_INFO sizeOfConsole;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &sizeOfConsole);
	columns = sizeOfConsole.srWindow.Right - sizeOfConsole.srWindow.Left + 1;
	rows = sizeOfConsole.srWindow.Bottom - sizeOfConsole.srWindow.Top + 1;

	return columns;
}

int HowManyNumbers()
{
	int howManyNumbers;
	std::cout << "How many numbers you'd like to sort? ";
	std::cin >> howManyNumbers;
	std::cout << "\n\n";

	return howManyNumbers;
}

std::vector<int> ListNumbers()
{
	int howManyNumbers = HowManyNumbers();
	std::vector<int> listOfNumbers;
	//RANDOM NUMBERS
	for (int i = 0; i < howManyNumbers; i++) {
		listOfNumbers.push_back(rand() % 100 + 1);
	}
	
	//MANUAL DATA INPUT
	/*
	std::cout << "Numbers can be in the range of 0-100\n";

	while (listOfNumbers.size() < howManyNumbers) {
		int temp;
		bool validInput = false;
		if (std::cin >> temp && temp <= 100 && temp >= 0) {
			listOfNumbers.push_back(temp);
		}
		else {
			std::cout << "Please give a number in the range of 0-100\n";
		}
		
	}*/

	return listOfNumbers;
}

std::vector<std::string> StringNumbers(std::vector<int> listOfNumbers)
{
	std::vector<std::string> barForNums;
	
	int barWidth = ConsoleSizeColums() - 10;

	for (int i = 0; i < listOfNumbers.size(); i++) {

		float progress = listOfNumbers.at(i) / 100.0;

		std::string visualNumber = "";

		visualNumber += "[";
		int pos = barWidth * progress;
		for (int i = 0; i < barWidth; ++i) {

			if (i < pos) {
				visualNumber += "=";
			}
			else {
				visualNumber += " ";
			}
		}
		visualNumber += "]";
		visualNumber += std::to_string(listOfNumbers.at(i));
		visualNumber += "\n";
		barForNums.push_back(visualNumber);
		Sleep(100);
	}

	return barForNums;
}

// Algorithms

void BubbleSort(std::vector<int> listOfNumbers, std::vector<std::string> stringNumbers)
{
	std::string swapTemp;

	bool swap;
	do {
		swap = false;
		for (int i = 0; i < listOfNumbers.size() - 1; i++) {
			if (listOfNumbers.at(i) > listOfNumbers.at(i + 1)) {

				listOfNumbers.at(i) += listOfNumbers.at(i + 1);
				listOfNumbers.at(i + 1) = listOfNumbers.at(i) - listOfNumbers.at(i + 1);
				listOfNumbers.at(i) -= listOfNumbers.at(i + 1);

				swapTemp = stringNumbers.at(i);
				stringNumbers.at(i) = stringNumbers.at(i + 1);
				stringNumbers.at(i + 1) = swapTemp;

				swap = true;

				system("cls");
				for (int j = 0; j < listOfNumbers.size(); j++) {
					std::cout << stringNumbers.at(j) << std::endl;

				}
				std::cout << std::endl;
				Sleep(100);
				system("cls");

			}
		}
	} while (swap);

	for (int j = 0; j < listOfNumbers.size(); j++) {
		std::cout << stringNumbers.at(j) << std::endl;

	}

}