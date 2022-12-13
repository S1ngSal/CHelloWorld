#include <string>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include "Checks.h"
#include "CS.h"

float Compressor_Station::comparasion(float bigger_value)
{
	float lesser_value;
	cin >> lesser_value;
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

void Compressor_Station::save_CS(Compressor_Station& CS1, string file_name) {
	ofstream saving_file;
	saving_file.open(file_name, ofstream::app);
	int CS_deleated;
	CS_deleated = 0;


	for (int i = 1; i <= CS1.CSmap.size(); i++) {
		if (CS1.CSmap[i].department_amount == 0) {
			CS_deleated++;
		}
	}

	if (saving_file.is_open()) {
		saving_file << (CS1.CSmap.size() - CS_deleated) << endl;
		for (int i = 1; i <= CS1.CSmap.size() - CS_deleated; i++) {
			if (CS1.CSmap[i].department_amount > 0) {
				saving_file << CS1.CSmap[i].name << endl;
				saving_file << CS1.CSmap[i].department_amount << endl;
				saving_file << CS1.CSmap[i].functioning_department_amount << endl;
				saving_file << CS1.CSmap[i].station_efficiency << endl;
				saving_file << CS1.CSmap[i].non_functioning_department_percent << endl;
			}
		}
	}
	else {
		cout << endl << "Can not open file! ";
	}

	saving_file.close();
}

void Compressor_Station::load_CS(Compressor_Station& CS1, string file_name) {
	ifstream loading_file;
	string buffer;
	loading_file.open(file_name);
	int pipe_amount, CS_amount;
	if (loading_file.is_open()) {
		loading_file >> pipe_amount;
		if (pipe_amount != 0) {
			for (int i = 1; i <= pipe_amount * 4; i++) {
				loading_file >> buffer;
			}
		}
		loading_file >> CS_amount;
		if (CS_amount != 0) {
			for (int i = 1; i <= (CS_amount * 5); i++) {
				CS1.CSmap[i].CS_id = i;
				loading_file >> CS1.CSmap[i].name;
				loading_file >> CS1.CSmap[i].department_amount;
				loading_file >> CS1.CSmap[i].functioning_department_amount;
				loading_file >> CS1.CSmap[i].station_efficiency;
				loading_file >> CS1.CSmap[i].non_functioning_department_percent;
			}
		}
		loading_file.close();
	}
	else {
		cout << endl << "Can not open file! ";
	}
}

void Compressor_Station::CS_name_filter() {
	string input_name;
	CSfilter.clear();
	cout << "Input name: ";
	cin >> input_name;
	for (int i = 1; i <= CS_id; i++) {
		if (CSmap[i].name.substr(0, size(input_name)) == input_name) {
			CSfilter.push_back(i);
		}
	}
}

void Compressor_Station::CS_percent_filter() {
	float left_limit, right_limit;
	CSfilter.clear();
	cout << "Input minimal percent: ";
	left_limit = value_check();
	cout << "Input maximal percent: ";
	right_limit = value_check();
	for (int i = 1; i <= CS_id; i++) {
		if ((CSmap[i].non_functioning_department_percent >= left_limit) && (CSmap[i].non_functioning_department_percent <= right_limit)) {
			CSfilter.push_back(i);
		}
	}
}

void Compressor_Station::show_CS(int CS_index) {
	if (CSmap[CS_index].department_amount != 0) {
		cout << "Compressor Station " << CSmap[CS_index].CS_id << endl;
		cout << "  CS name: " << CSmap[CS_index].name << endl;
		cout << "  Amount of departments: " << CSmap[CS_index].department_amount << endl;
		cout << "  Amount of functioning departments: " << CSmap[CS_index].functioning_department_amount << endl;
		cout << "  " << CSmap[CS_index].non_functioning_department_percent << "% of departments are not functioning" << endl;
		cout << "  CS efficiency: " << CSmap[CS_index].station_efficiency << endl;
	}

}

void Compressor_Station::redact_CS(int CS_index) {
	show_CS(CS_index);
	cout << endl << "Input amount of functioning departments: ";
	CSmap[CS_index].functioning_department_amount = comparasion(CSmap[CS_index].department_amount);
	cout << endl;
}

void Compressor_Station::CS_adding(Compressor_Station& CS1)
{
	CS_id = CSmap.size()/5+1;
	cout << "CS name: ";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, CS1.name);
	cout << "Amount of departments: ";
	CS1.department_amount = value_check();
	cout << "Amount of functioning departments: ";
	CS1.functioning_department_amount = comparasion(CS1.department_amount);
	CS1.non_functioning_department_percent = round((1.00 - CS1.functioning_department_amount / CS1.department_amount) * 100);
	cout << CS1.non_functioning_department_percent << "%" << " of departments are not functioning" << endl;
	cout << "CS efficiency: ";
	CS1.station_efficiency = value_check();
	cout << endl;
	CSmap.insert(make_pair(CSmap.size()+1, CS1));
}

void Compressor_Station::edit_CS(Compressor_Station& CS1)
{
	int CS_redacting_ID;
	float left_limit, rigth_limit;
	bool edit_CS_switch = true;
	while (edit_CS_switch)
	{
		bool redact_CS_switch = true;
		cout << "Type 1 to redact CS's" << endl << "Type 2 to delete CS's" << endl << "Type 3 to stop editing" << endl;
		switch (error_check())
		{
		case 1:
			while (redact_CS_switch) {
				cout << "1. Redact 1 CS   2. Redact all CS's   3. Redact CS's on a filter-basis   4. Stop redacting" << endl;
				switch (error_check())
				{
				case 1:
					cout << "Input id of the CS: ";
					redact_CS(error_check());
					break;
				case 2:
					for (int i = 1; i <= CS_id; i++) {
						redact_CS(i);
					}
					break;
				case 3:
					cout << "1. Redact CS's on a name-basis   2. Redact CS's on functioning-department-basis" << endl;
					switch (error_check())
					{
					case 1:
						CS_name_filter();
						for (int i = 0; i < CSfilter.size(); i++) {
							redact_CS(CSfilter[i]);
						}
						break;
					case 2:
						CS_percent_filter();
						for (int i = 0; i < CSfilter.size(); i++) {
							redact_CS(CSfilter[i]);
						}
						break;
					default:
						cout << endl << "Enter a valid command id" << endl;
						break;
					}
					break;
				case 4:
					redact_CS_switch = false;
					break;
				default:
					cout << endl << "Enter a valid command id" << endl;
					break;
				}
			}
			break;
		case 2:
			cout << "1. Delete 1 CS   2. Delete all CS's   3. Delete CS on filter-basis";
			switch (error_check())
			{
			case 1:
				cout << "Input ID of the CS" << endl;
				CS_redacting_ID = error_check();
				if (CSmap[CS_redacting_ID].department_amount != 0) {
					CSmap.erase(CS_redacting_ID);
				}
				else
				{
					cout << "Compressor Station does not exist" << endl;
				}
				break;
			case 2:
				for (int i = 1; i <= CS_id; i++) {
					CSmap.erase(i);
				}
				break;
			case 3:
				cout << "1. Delete CS on a name-basis   2. Delete CS on functioning-percentage-basis" << endl;
				switch (error_check())
				{
				case 1:
					CS_name_filter();
					for (int i = 0; i < CSfilter.size(); i++) {
						CSmap.erase(CSfilter[i]);
					}
					break;
				case 2:
					CS_percent_filter();
					for (int i = 0; i < CSfilter.size(); i++) {
						CSmap.erase(CSfilter[i]);
					}
					break;
				default:
					cout << "Input a valid command ID" << endl;
					break;
				}
				break;
			default:
				cout << "Input a valid command ID" << endl;
				break;
			}
			break;
		case 3:
			edit_CS_switch = false;
			break;
		default:
			cout << endl << "Enter a valid command id" << endl;
			break;
		}
	}
}

void Compressor_Station::find_CS(Compressor_Station& CS1)
{
	string input_name;
	if (CS_id > 0)
	{
		float left_limit, right_limit;
		bool pipe_looking_switch = true;
		while (pipe_looking_switch)
		{
			bool functioning_pipe_looking_switch = true;
			cout << "Type 1 to find CS's on a name-basis" << endl;
			cout << "Type 2 to find CS's on a functionong-departemnts-basis" << endl;
			cout << "Type 3 to stop looking for CS's" << endl;
			switch (error_check())
			{
			case 1:
				CS_name_filter();
				for (int i = 0; i < CSfilter.size(); i++) {
					show_CS(CSfilter[i]);
				}
				break;
			case 2:
				CS_percent_filter();
				for (int i = 0; i < CSfilter.size(); i++) {
					show_CS(CSfilter[i]);
				}
				cout << endl;
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