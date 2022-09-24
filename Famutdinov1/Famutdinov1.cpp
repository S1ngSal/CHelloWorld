// Famutdinov1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Pipestruct
{
	float length = 0;
	float diameter = 0;
	int working = 1;
};

struct Compressor_Station
{
	string name = "";
	int department_amount = 0;
	int functioning_department_amount = 0;
	float station_efficiency = 0;
};


float value_check(float check_variable)
{
	while (!check_variable || check_variable <= 0)
	{
		cout << "Input value must be a number bigger than 0: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> check_variable;
	}
	return check_variable;
}

float work_check(float check_variable)
{
	while ((!check_variable) || (check_variable != 1)&&(check_variable != 2))
	{
		cout << "Input value must be a number 1 or a number 2: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> check_variable;
	}
	return check_variable;
}

float comparasion(float bigger_value, float lesser_value)
{
	while (!lesser_value || lesser_value > bigger_value || lesser_value <=0)
	{
		cout << endl;
		cout << "Amount of functioning departments must be a number bigger than 0 \n and can't be bigger than amount of all departments: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> lesser_value;
	}
	return lesser_value;
}

int main()
{
	Pipestruct pipe;
	Compressor_Station CS;
	cout << "1. Add a pipe   2. Add a CS   3. View all objects   4. Edit a pipe   5. Edit a CS   6. Save   7. Load   0. Exit" << endl; 
	int command_number;
	cin >> command_number;
	switch (command_number)
	{
	case 1:
		cout << "Pipe length: ";
		cin >> pipe.length;
		pipe.length = value_check(pipe.length);
		cout << "Pipe diameter: ";
		cin >> pipe.diameter;
		pipe.diameter = value_check(pipe.diameter);
		cout << "Is pipe working? (If it is - type 2 else type 1): ";
		cin >> pipe.working;
		pipe.working = work_check(pipe.working);
		break;
	case 2:
		cout << "CS name: ";
		cin >> CS.name;
		cout << "Amount of departments: ";
		cin >> CS.department_amount;
		CS.department_amount = value_check(CS.department_amount);
		cout << "Amount of functioning departments: ";
		cin >> CS.functioning_department_amount;
		CS.functioning_department_amount = comparasion(CS.department_amount, CS.functioning_department_amount);
		cout << "CS efficiency";
		cin >> CS.station_efficiency;
		CS.station_efficiency = value_check(CS.station_efficiency);
		break;
	default:
		cout << "Inpit correct number of command";
		break;
	}
	return 0;
}