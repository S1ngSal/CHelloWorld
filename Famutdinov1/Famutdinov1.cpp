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

float error_check(float check_variable)
{
	while (!check_variable)
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
	while (!lesser_value || lesser_value > bigger_value || lesser_value < 0)
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
	while (true)
	{
		int stop_edit = 0;
		int stop_edit_CS = 0;
		cout << "1. Add a pipe   2. Add a CS   3. View all objects   4. Edit a pipe   5. Edit a CS   6. Save   7. Load   0. Exit" << endl;
		int command_number;
		cin >> command_number;
		command_number = error_check(command_number);
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
			cout << endl;
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
			cout << "CS efficiency: ";
			cin >> CS.station_efficiency;
			CS.station_efficiency = value_check(CS.station_efficiency);
			cout << endl;
			break;
		case 3:
			cout << endl;
			if (pipe.length > 0) {
				cout << "Pipe properties:" << endl;
				cout << "Length: " << pipe.length << endl;
				cout << "Diameter " << pipe.diameter << endl;
				if (pipe.working == 1) {
					cout << "Pipe is not working" << endl;
				}
				else
				{
					cout << "Pipe is working" << endl;
				}
			}
			else
			{
				cout << "Pipe does not exist" << endl;
			}
			cout << endl;
			if (CS.department_amount > 0) {
				cout << "Compressor Station properties:" << endl;
				cout << "CS name: " << CS.name << endl;
				cout << "Amount of departments: " << CS.department_amount << endl;
				cout << "Amount  of functioning departments " << CS.functioning_department_amount << endl;
				cout << "CS efficiency: " << CS.station_efficiency << endl;
			}
			else
			{
				cout << "Compressor Station does not exist" << endl;
			}
			cout << endl;
			break;
		case 4:
			if (pipe.length > 0) {
				while (stop_edit != 4)
				{
					cout << "1. Edit pipe length   2. Edit pipe diameter   3. Edit pipe condition   4. Stop editing" << endl;
					cin >> stop_edit;
					stop_edit = error_check(stop_edit);
					switch (stop_edit)
					{
					case 1:
						cout << "Pipe length: ";
						cin >> pipe.length;
						pipe.length = value_check(pipe.length);
						break;
					case 2:
						cout << "Pipe diameter: ";
						cin >> pipe.diameter;
						pipe.diameter = value_check(pipe.diameter);
						break;
					case 3:
						cout << "Is pipe working? (If it is - type 2 else type 1): ";
						cin >> pipe.working;
						pipe.working = work_check(pipe.working);
						cout << endl;
						break;
					case 4:
						break;
					default:
						cout << "Enter a valid command number" << endl;
						break;
					}
				}
			}
			else {
				cout << "Pipe does not exist " << endl;
			}
			break;
		case 5:
			if (CS.department_amount > 0) {
				while (stop_edit_CS != 5)
				{
					cout << "1. Edit CS name   2. Edit an amount of departments   3. Edit an amount of functioning departments\n4. Edit CS efficiency   5. Stop editing" << endl;
					cin >> stop_edit_CS;
					stop_edit_CS = error_check(stop_edit_CS);
					switch (stop_edit_CS)
					{
					case 1:
						cout << "CS name: ";
						cin >> CS.name;
						break;
					case 2:
						cout << "Amount of departments: ";
						cin >> CS.department_amount;
						CS.department_amount = value_check(CS.department_amount);
						break;
					case 3:
						cout << "Amount of functioning departments: ";
						cin >> CS.functioning_department_amount;
						CS.functioning_department_amount = comparasion(CS.department_amount, CS.functioning_department_amount);
						break;
					case 4:
						cout << "CS efficiency: ";
						cin >> CS.station_efficiency;
						CS.station_efficiency = value_check(CS.station_efficiency);
						break;
					case 5:
						break;
					default:
						cout << "Enter a valid command number" << endl;
						break;
					}
				}
			}
			else {
				cout << "Compressor station does not exist " << endl;
			}
			break;
		default:
			cout << endl << "Enter a valid command number" << endl;
			break;
		}
	}
	return 0;
}