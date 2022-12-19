#include "Checks.h"

float value_check()
{
	float check_variable;
	cin >> check_variable;
	while (!check_variable || check_variable <= 0)
	{
		cout << "Input value must be a number bigger than 0: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> check_variable;
	}
	return check_variable;
}


int error_check()
{
	int check_variable;
	cin >> check_variable;
	while (cin.fail())
	{
		cout << "Input value must be a number bigger than 0: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> check_variable;
	}
	return check_variable;
}

int menu()
{
	cout << "1. Add a pipe   2. Add a CS   3. View all objects   4. Edit a pipe   5. Edit a CS   6. Save   7. Load\n8.Look for a pipe   9. Look for CS   10. Connect Network   11. Sort Network   12. Exit" << endl;
	return error_check();
}

string file_name_input()
{
	string file_name;
	cout << "Input file name (without '.txt'): ";
	cin >> file_name;
	file_name = file_name + ".txt";
	return file_name;
}

void inspect(Pipestruct& pipe1, Compressor_Station& CS1)
{
	cout << endl;
	for (int i = 1; i <= pipe1.pipemap.size(); i++) {
		pipe1.show_pipe(i);
	}
	cout << endl;


	for (int i = 1; i <= CS1.CSmap.size(); i++) {
		CS1.show_CS(i);
	}

	cout << endl;
}