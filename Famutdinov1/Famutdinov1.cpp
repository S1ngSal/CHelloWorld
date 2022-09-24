// Famutdinov1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool flag = false;

struct Pipe
{
	float length = 0;
	float diameter = 0;
	bool working = false;
};

struct Compressor_Station
{
	string name = "";
	int department_amount = 0;
	int functioning_department_amount = 0;
	float station_efficiency = 0;
};

void add_pipe()
{
	Pipe pipe_adding;
	while (pipe_adding.length <= 0)
	{	
		cin.clear();
		pipe_adding.length = 0;
		cout << "Enter a length of the pipe: ";
		cin >> pipe_adding.length;
	}
}

int main()
{
	cout << "1. Add a pipe   2. Add a CS   3. View all objects   4. Edit a pipe   5. Edit a CS   6. Save   7. Load   0. Exit" << endl; 
	int command_number;
	cin >> command_number;
	switch (command_number)
	{
	case 1:
		add_pipe();
		break;
	default:
		cout << "Inpit correct number of command";
		break;
	}
	getchar();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file. В его словах есть буквы.
