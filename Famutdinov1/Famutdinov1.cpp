#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include "Pipe.h"
#include "Checks.h"
#include "CS.h"
#include "Transport.h"

using namespace std;

int main()
{	
	string file_name; Pipestruct pipe; Compressor_Station CS; Network NW; Trio trio;
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
			inspect(pipe, CS, NW);
			break;
		case 4:
			pipe.edit_pipe(pipe);
			break;
		case 5:
			CS.edit_CS(CS);
			break;
		case 6:
			file_name = file_name_input(); pipe.save_pipe(pipe, file_name);  CS.save_CS(CS, file_name);
			break;
		case 7:
			file_name = file_name_input(); pipe.load_pipe(pipe, file_name); CS.load_CS(CS, file_name);
			break;
		case 8:
			pipe.find_pipe(pipe);
			break;
		case 9:
			CS.find_CS(CS);
			break;
		case 10:
			NW.connect(trio, CS, pipe);
			break;
		case 12:
			keep_running = false;
			break;
		default:
			cout << endl << "Enter a valid command id" << endl;
			break;
		}
	}
	return 0;
}