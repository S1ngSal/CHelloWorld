#include <string>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include "Checks.h"
#include "Pipe.h"

float Pipestruct::work_check()
{
	float check_variable;
	cin >> check_variable;
	while ((!check_variable) || (check_variable != 1) && (check_variable != 2))
	{
		cout << "Input value must be a number 1 or a number 2: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> check_variable;
	}
	return check_variable;
}

void Pipestruct::save_pipe(Pipestruct& pipe1, string file_name) {
	ofstream saving_file;
	saving_file.open(file_name);
	int pipes_deleated;
	pipes_deleated = 0;

	for (int i = 1; i <= pipe1.pipemap.size(); i++) {
		if (pipe1.pipemap[i].length == 0) {
			pipes_deleated++;
		}
	}

	if (saving_file.is_open()) {
		saving_file << pipe1.pipemap.size() << endl;
		for (int i = 1; i <= pipe1.pipemap.size() - pipes_deleated; i++) {
			if (pipe1.pipemap[i].length > 0) {
				saving_file << pipe1.pipemap[i].pipe_name << endl;
				saving_file << pipe1.pipemap[i].length << endl;
				saving_file << pipe1.pipemap[i].diameter << endl;
				saving_file << pipe1.pipemap[i].working << endl;
			}
		}
		cout << "Data has been saved" << endl;
	}
	else {
		cout << endl << "Can not open file! ";
	}

	saving_file.close();

}

void Pipestruct::load_pipe(Pipestruct& pipe1, string file_name) {
	ifstream loading_file;
	loading_file.open(file_name);
	int pipe_amount;
	if (loading_file.is_open()) {
		loading_file >> pipe_amount;
		Pipe_id = pipe_amount;
		if (pipe_amount != 0) {
			for (int i = 1; i <= pipe_amount * 4; i++) {
				pipe1.pipemap[i].Pipe_id = i;
				loading_file >> pipe1.pipemap[i].pipe_name;
				loading_file >> pipe1.pipemap[i].length;
				loading_file >> pipe1.pipemap[i].diameter;
				loading_file >> pipe1.pipemap[i].working;
			}
		}
		cout << "Data has been loaded" << endl;
	}
	else {
		cout << endl << "Can not open file! ";
	}
}

void Pipestruct::show_pipe(int pipe_index) {


	if (pipemap[pipe_index].length != 0) {
		cout << "Pipe " << pipemap[pipe_index].Pipe_id << endl;
		cout << "  Pipe name: " << pipemap[pipe_index].pipe_name << endl;
		cout << "  Pipe length: " << pipemap[pipe_index].length << endl;
		cout << "  Pipe diameter: " << pipemap[pipe_index].diameter << endl;
		if (pipemap[pipe_index].working == 1) {
			cout << "  Pipe is not working" << endl;
		}
		else {
			cout << "  Pipe is working" << endl;
		}
	}

}

void Pipestruct::pipe_name_filter() {
	string input_name;
	pipefilter.clear();
	cout << "Input name: ";
	cin >> input_name;
	for (int i = 1; i <= Pipe_id; i++) {
		if (pipemap[i].pipe_name.substr(0, size(input_name)) == input_name) {
			pipefilter.push_back(i);
		}
	}
}

void Pipestruct::pipe_functioning_filter(int x) {
	pipefilter.clear();
	for (int i = 1; i <= Pipe_id; i++)
	{
		if (pipemap[i].working == x)
		{
			pipefilter.push_back(i);
		}
	}
}


void Pipestruct::pipe_adding(Pipestruct& pipe1)
{
	Pipe_id = pipemap.size()/4+1;
	cout << "Pipe name: ";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, pipe1.pipe_name);
	cout << "Pipe length: ";
	pipe1.length = value_check();
	cout << "Pipe diameter: ";
	pipe1.diameter = value_check();
	cout << "Is pipe working? (If it is - type 2 else type 1): ";
	pipe1.working = work_check();
	cout << endl;
	pipemap.insert(make_pair(pipemap.size()+1, pipe1));
}

void Pipestruct::pipe_redactng(int pipe_index)
{
	if (Pipe_id > 0) {
		cout << "Pipe " << pipe_index << endl;
		cout << "Is pipe working? (If it is - type 2 else type 1): ";
		pipemap[pipe_index].working = work_check();
	}
	else {
		cout << "Pipe does not exist " << endl;
	}
}


void Pipestruct::edit_pipe(Pipestruct& pipe1)
{
	int workings;
	int left_limit;
	bool pipe_edit_switch = true;
	while (pipe_edit_switch)
	{
		bool pipe_redact_switch = true;
		cout << "Type 1 to redact pipes" << endl << "Type 2 to delete pipes" << endl << "Type 3 to stop editing" << endl;
		switch (error_check())
		{
		case 1:

			cout << "1. Redact 1 pipe   2. Redact all pipes   3. Redact pipes on filter-basis   4. Stop redacting" << endl;
			switch (error_check())
			{
			case 1:
				cout << "Input index of a pipe: ";
				left_limit = error_check();
				pipe_redactng(left_limit);
				break;
			case 2:
				cout << "Are pipes working? (If they are - type 2 else type 1): ";
				workings = work_check();
				for (int i = 1; i <= Pipe_id; i++) {
					pipemap[i].working = workings;
				}
				break;
			case 3:
				cout << "1. Redact pipes on a name-basis" << endl;
				cout << "2. Redact pipes on a functionong-basis" << endl;
				switch (error_check())
				{
				case 1:
					pipe_name_filter();
					cout << "Are pipes working? (If they are - type 2 else type 1): ";
					workings = work_check();
					for (int i = 0; i < pipefilter.size(); i++) {
						pipemap[pipefilter[i]].working = workings;
					}
					break;
				case 2:
					cout << "Type 1 to find non-functioning pipes" << endl << "Type 2 to find functioning pipes" << endl;
					switch (error_check())
					{
					case 1:
						cout << "Are pipes working? (If they are - type 2 else type 1): ";
						workings = work_check();
						pipe_functioning_filter(1);
						for (int i = 0; i < pipefilter.size(); i++) {
							pipemap[pipefilter[i]].working = workings;
						}
						break;
					case 2:
						cout << "Are pipes working? (If they are - type 2 else type 1): ";
						workings = work_check();
						pipe_functioning_filter(2);
						for (int i = 0; i < pipefilter.size(); i++) {
							pipemap[pipefilter[i]].working = workings;
						}
						break;
					default:
						cout << endl << "Enter a valid command id" << endl;
						break;
					}
					break;
				default:
					cout << endl << "Command does not exist" << endl;
					break;
				}
				break;
			case 4:
				pipe_redact_switch = false;
				break;
			default:
				cout << endl << "Enter a valid command id" << endl;
				break;
			}
			break;

		case 2:
			cout << "1. Delete 1 pipe   2. Delete all pipes   3. Delete pipes on filter-basis   4. Stop deleting" << endl;
			switch (error_check())
			{
			case 1:
				cout << "Input index of a pipe: ";
				workings = error_check();
				if (pipemap[workings].length != 0) {
					pipemap.erase(workings);
				}
				else
				{
					cout << "Pipe does not exist" << endl;
				}
				break;
			case 2:
				for (int i = 1; i <= Pipe_id; i++) {
					pipemap.erase(i);
				}
				break;
			case 3:
				cout << "Type 1 to delete pipes on a name-basis" << endl;
				cout << "Type 2 to delete pipes on a functionong-basis" << endl;
				switch (error_check())
				{
				case 1:
					pipe_name_filter();
					for (int i = 0; i < pipefilter.size(); i++) {
						pipemap.erase(pipefilter[i]);
					}
					break;
				case 2:
					cout << "Type 1 to find non-functioning pipes" << endl << "Type 2 to find functioning pipes" << endl;
					switch (error_check())
					{
					case 1:
						pipe_functioning_filter(1);
						for (int i = 0; i < pipefilter.size(); i++) {
							pipemap.erase(pipefilter[i]);
						}
						break;
					case 2:
						pipe_functioning_filter(2);
						for (int i = 0; i < pipefilter.size(); i++) {
							pipemap.erase(pipefilter[i]);
						}
						break;
					default:
						cout << endl << "Enter a valid command id" << endl;
						break;
					}
					break;
				default:
					cout << endl << "Command does not exist" << endl;
					break;
				}
				break;
			case 4:
				pipe_redact_switch = false;
				break;
			default:
				cout << endl << "Enter a valid command id" << endl;
				break;
			}
			break;
		case 3:
			pipe_edit_switch = false;
			break;
		default:
			cout << endl << "Enter a valid command id" << endl;
			break;
		}
	}

}

void Pipestruct::find_pipe(Pipestruct& pipe1)
{
	if (Pipe_id > 0)
	{
		bool pipe_looking_switch = true;
		bool functioning_pipe_looking_switch = true;
		while (pipe_looking_switch)
		{
			cout << "Type 1 to find pipes on a name-basis" << endl;
			cout << "Type 2 to find pipes on a functionong-basis" << endl;
			cout << "Type 3 to stop looking for pipes" << endl;
			switch (error_check())
			{
			case 1:
				pipe_name_filter();
				for (int i = 0; i < pipefilter.size(); i++) {
					show_pipe(pipefilter[i]);
				}
				break;
			case 2:
				while (functioning_pipe_looking_switch)
				{
					cout << "Type 1 to find non-functioning pipes" << endl << "Type 2 to find functioning pipes" << endl << "Type 3 to stop looking for pipes on functioning-basis" << endl;
					switch (error_check()) {
					case 1:
						pipe_functioning_filter(1);
						for (int i = 0; i < pipefilter.size(); i++) {
							show_pipe(pipefilter[i]);
						}
						break;
					case 2:
						pipe_functioning_filter(2);
						for (int i = 0; i < pipefilter.size(); i++) {
							show_pipe(pipefilter[i]);
						}
						break;
					case 3:
						functioning_pipe_looking_switch = false;
						break;
					default:
						cout << endl << "Enter a valid command id" << endl;
						break;
					}
				}
				break;
			case 3:
				pipe_looking_switch = false;
				break;
			default:
				cout << endl << "Enter a valid command id" << endl;
				break;
			}
		}
	}
	else
	{
		cout << "Pipes do not exist " << endl;
	}

}