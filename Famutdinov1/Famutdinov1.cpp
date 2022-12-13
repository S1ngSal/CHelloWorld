#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include "Pipe.h"
#include "Checks.h"
#include "CS.h"

using namespace std;
class Pipestruct;
class Compressor_Station;
float work_check();
string file_name_input();


int menu()
{
	cout << "1. Add a pipe   2. Add a CS   3. View all objects   4. Edit a pipe   5. Edit a CS   6. Save   7. Load\n8.Look for a pipe   9. Look for CS   10. Exit" << endl;
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


int main()
{	
	string file_name;
	Pipestruct pipe;
	Compressor_Station CS;
	bool keep_running = true;
	while (keep_running)
	{
		switch (menu())
		{
		case 1:
			pipe.pipe_adding(pipe);
			break; 
		case 2:
			CS.CS_adding(CS);
			break;
		case 3:
			inspect(pipe, CS);
			break;
		case 4:
			pipe.edit_pipe(pipe);
			break;
		case 5:
			CS.edit_CS(CS);
			break;
		case 6:
			file_name = file_name_input();
			pipe.save_pipe(pipe, file_name);
			CS.save_CS(CS, file_name);
			break;
		case 7:
			file_name = file_name_input();
			pipe.load_pipe(pipe, file_name);
			CS.load_CS(CS, file_name);
			break;
		case 8:
			pipe.find_pipe(pipe);
			break;
		case 9:
			CS.find_CS(CS);
			break;
		case 10:
			keep_running = false;
			break;
		default:
			cout << endl << "Enter a valid command id" << endl;
			break;
		}
	}
	return 0;
}