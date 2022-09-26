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
}
//
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

int menu()
{
	cout << "1. Add a pipe   2. Add a CS   3. View all objects   4. Edit a pipe   5. Edit a CS   6. Save   7. Load   8. Exit" << endl;
	int command_number;
	cin >> command_number;
	command_number = error_check(command_number);
	return command_number;
}

void pipe_adding(Pipestruct& pipe1)
{
	cout << "Pipe length: ";
	cin >> pipe1.length;
	pipe1.length = value_check(pipe1.length);
	cout << "Pipe diameter: ";
	cin >> pipe1.diameter;
	pipe1.diameter = value_check(pipe1.diameter);
	cout << "Is pipe working? (If it is - type 2 else type 1): ";
	cin >> pipe1.working;
	pipe1.working = work_check(pipe1.working);
	cout << endl;
}

void CS_adding(Compressor_Station& CS1)
{
	cout << "CS name: ";
	cin >> CS1.name;
	cout << "Amount of departments: ";
	cin >> CS1.department_amount;
	CS1.department_amount = value_check(CS1.department_amount);
	cout << "Amount of functioning departments: ";
	cin >> CS1.functioning_department_amount;
	CS1.functioning_department_amount = comparasion(CS1.department_amount, CS1.functioning_department_amount);
	cout << "CS efficiency: ";
	cin >> CS1.station_efficiency;
	CS1.station_efficiency = value_check(CS1.station_efficiency);
	cout << endl;
}

void inspect(Pipestruct& pipe1, Compressor_Station& CS1)
{
	cout << endl;
	if (pipe1.length > 0) {
		cout << "Pipe properties:" << endl;
		cout << "Length: " << pipe1.length << endl;
		cout << "Diameter " << pipe1.diameter << endl;
		if (pipe1.working == 1) {
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
	if (CS1.department_amount > 0) {
		cout << "Compressor Station properties:" << endl;
		cout << "CS name: " << CS1.name << endl;
		cout << "Amount of departments: " << CS1.department_amount << endl;
		cout << "Amount  of functioning departments " << CS1.functioning_department_amount << endl;
		cout << "CS efficiency: " << CS1.station_efficiency << endl;
	}
	else
	{
		cout << "Compressor Station does not exist" << endl;
	}
	cout << endl;
}

void edit_pipe(Pipestruct& pipe1)
{
	if (pipe1.length > 0) {
		cout << "Is pipe working? (If it is - type 2 else type 1): ";
		cin >> pipe1.working;
		pipe1.working = work_check(pipe1.working);
	}
	else {
		cout << "Pipe does not exist " << endl;
	}
}

void edit_CS(Compressor_Station& CS1)
{
	if (CS1.department_amount > 0) {
		cout << "Amount of functioning departments: ";
		cin >> CS1.functioning_department_amount;
		CS1.functioning_department_amount = comparasion(CS1.department_amount, CS1.functioning_department_amount);
	}
	else {
		cout << "Compressor station does not exist " << endl;
	}
}

void save_data(Pipestruct& pipe1, Compressor_Station& CS1)
{
	ofstream out;          
	out.open("pipeline.txt");
	if (out.is_open())
	{
		out << pipe1.length << endl << pipe1.diameter << endl << pipe1.working << endl << endl << CS1.name << endl << CS1.department_amount << endl << CS1.functioning_department_amount << endl << CS1.station_efficiency;
		cout << "Data has been saved." << endl;
	}
	else
	{
		cout << "Can not open file." << endl;
	}
}

void load_data(Pipestruct& pipe1, Compressor_Station& CS1)
{
	ifstream inp;
	inp.open("pipeline.txt");
	if (inp.is_open())
	{
		inp >> pipe1.length >> pipe1.diameter >> pipe1.working;
		inp.ignore();
		inp >> CS1.name >> CS1.department_amount >> CS1.functioning_department_amount >> CS1.station_efficiency;
		cout << "Data has been loaded." << endl;
	}
	else
	{
		cout << "Can not open file." << endl;
	}
}

int main()
{	
	Pipestruct pipe;
	Compressor_Station CS;
	bool keep_running = true;
	while (keep_running)
	{
		switch (menu())
		{
		case 1:
			pipe_adding(pipe);
			break;
		case 2:
			CS_adding(CS);
			break;
		case 3:
			inspect(pipe, CS);
			break;
		case 4:
			edit_pipe(pipe);
			break;
		case 5:
			edit_CS(CS);
			break;
		case 6:
			save_data(pipe, CS);
			break;
		case 7:
			load_data(pipe, CS);
			break;
		case 8:
			keep_running = false;
			break;
		default:
			cout << endl << "Enter a valid command number" << endl;
			break;
		}
	}
	return 0;
}