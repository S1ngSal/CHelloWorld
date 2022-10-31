#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

float value_check();
int error_check();
float work_check();
float comparasion(float bigger_value);


class Pipestruct
{
private:
public:
	string pipe_name = "";
	float length = 0;
	float diameter = 0;
	int working = 1;
	int Pipe_id = 0;
	unordered_map<int, Pipestruct> pipemap;
	vector<int> pipefilter;
	vector<int> deleted_pipes;

	void show_pipe(int pipe_index) {
		int count = 0;
		for (int i = 0; i < deleted_pipes.size(); i++) {
			if (pipe_index == deleted_pipes[i]) {
				count++;
				break;
			}
		}
		if (count == 0) {
			cout << "Pipe " << pipe_index << endl;
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
		else
		{
			cout << "Pipe "<< pipe_index <<" do not exist" << endl;
		}
		
		
	}

	void pipe_name_filter() {
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

	void pipe_functioning_filter(int x) {
		pipefilter.clear();
		for (int i = 1; i <= Pipe_id; i++)
		{
			if (pipemap[i].working == x)
			{
				pipefilter.push_back(i);
			}
		}
	}

	void pipe_adding(Pipestruct& pipe1)
	{
		Pipe_id++;
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
		pipemap.insert(make_pair(Pipe_id,pipe1));
	}

	void pipe_redactng(int pipe_index)
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

	void edit_pipe(Pipestruct& pipe1)
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
						deleted_pipes.push_back(workings);
						pipemap.erase(workings);
					}
					else
					{
						cout << "Pipe does not exist" << endl;
					}
					break;
				case 2:
					for (int i = 1; i <= Pipe_id; i++) {
						deleted_pipes.push_back(i);
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
							deleted_pipes.push_back(pipefilter[i]);
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
								deleted_pipes.push_back(pipefilter[i]);
								pipemap.erase(pipefilter[i]);
							}
							break;
						case 2:
							pipe_functioning_filter(2);
							for (int i = 0; i < pipefilter.size(); i++) {
								deleted_pipes.push_back(pipefilter[i]);
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

	void find_pipe(Pipestruct& pipe1)
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
						switch (error_check()){
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

};

class Compressor_Station
{
private:

public:
	string name = "";
	float department_amount = 0;
	float functioning_department_amount = 0;
	float station_efficiency = 0;
	int CS_id = 0;
	float non_functioning_department_percent = 0;
	unordered_map<int, Compressor_Station> CSmap;
	vector<int> CSfilter;
	vector<int> deleted_CS;

	void CS_name_filter() {
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

	void CS_percent_filter() {
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

	void show_CS(int CS_index) {
		int count = 0;

		for (int i = 0; i < deleted_CS.size(); i++) {
			if (CS_index == deleted_CS[i]) {
				count++;
				break;
			}
		}

		if (count== 0) {
			cout << "Compressor Station " << CS_index << endl;
			cout << "  CS name: " << CSmap[CS_index].name << endl;
			cout << "  Amount of departments: " << CSmap[CS_index].department_amount << endl;
			cout << "  Amount of functioning departments: " << CSmap[CS_index].functioning_department_amount << endl;
			cout << "  " << CSmap[CS_index].non_functioning_department_percent << "% of departments are not functioning" << endl;
			cout << "  CS efficiency: " << CSmap[CS_index].station_efficiency << endl;
		}
		else
		{
			cout << "Compressor Station " << CS_index << " does not exist";
		}
		
	}

	void redact_CS(int CS_index) {
		show_CS(CS_index);
		cout << endl << "Input amount of functioning departments: ";
		CSmap[CS_index].functioning_department_amount = comparasion(CSmap[CS_index].department_amount);
		cout << endl;
	}

	void CS_adding(Compressor_Station& CS1)
	{
		CS_id++;
		cout << "CS name: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		getline(cin, CS1.name);
		cout << "Amount of departments: ";
		CS1.department_amount = value_check();
		cout << "Amount of functioning departments: ";
		CS1.functioning_department_amount = comparasion(CS1.department_amount);
		CS1.non_functioning_department_percent = round((1.00 - CS1.functioning_department_amount / CS1.department_amount)*100);
		cout << CS1.non_functioning_department_percent << "%" << " of departments are not functioning" << endl;
		cout << "CS efficiency: ";
		CS1.station_efficiency = value_check();
		cout << endl;
		CSmap.insert(make_pair(CS_id, CS1));
	}

	void edit_CS(Compressor_Station& CS1)
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
						deleted_CS.push_back(CS_redacting_ID);
						CSmap.erase(CS_redacting_ID);
					}
					else
					{
						cout << "Compressor Station does not exist" << endl;
					}
					break;
				case 2:
					for (int i = 1; i <= CS_id; i++) {
						deleted_CS.push_back(i);
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
							deleted_CS.push_back(CSfilter[i]);
							CSmap.erase(CSfilter[i]);
						}
						break;
					case 2:
						CS_percent_filter();
						for (int i = 0; i < CSfilter.size(); i++) {
							deleted_CS.push_back(CSfilter[i]);
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
		
	/*	while (redact_CS_switch)
		{
			cout << "Type 1 to redact CS's" << endl << "Type 2 to delete a CS" << endl << "Type 3 to stop editing" << endl;
			switch (error_check())
			{
			case 1:
				if (CS_id > 0) {
					cout << "Amount of functioning departments: ";
					CS1.functioning_department_amount = comparasion(CS1.department_amount);
					CS1.non_functioning_department_percent = round((1.00 - CS1.functioning_department_amount / CS1.department_amount) * 100);
					cout << CS1.non_functioning_department_percent << "%" << " of departments are not functioning" << endl;
				}
				else {
					cout << "Compressor station does not exist " << endl;
				}
				break;
			case 2:
				cout << "Input id of the CS: " << endl;
				{int CS_del_id = error_check();
				CSmap.erase(CS_del_id); }
				break;
			case 3:
				redact_CS_switch = false;
				break;
			default:
				cout << endl << "Enter a valid command id" << endl;
				break;
			}
		}*/
	}

	void find_CS(Compressor_Station& CS1)
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

};


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
	while (!check_variable)
	{
		cout << "Input value must be a number bigger than 0: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> check_variable;
	}
	return check_variable;
}

float work_check()
{
	float check_variable;
	cin >> check_variable;
	while ((!check_variable) || (check_variable != 1)&&(check_variable != 2))
	{
		cout << "Input value must be a number 1 or a number 2: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> check_variable;
	}
	return check_variable;
}

float comparasion(float bigger_value)
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

int menu()
{
	cout << "1. Add a pipe   2. Add a CS   3. View all objects   4. Edit a pipe   5. Edit a CS   6. Save   7. Load\n8.Look for a pipe   9. Look for CS   10. Exit" << endl;
	return error_check();
}





void inspect(Pipestruct& pipe1, Compressor_Station& CS1)
{
	cout << endl;
	for (int i = 1; i <= pipe1.Pipe_id; i++) {
		pipe1.show_pipe(i);
	}
	cout << endl;


	for (int i = 1; i <= CS1.CS_id; i++) {
		CS1.show_CS(i);
	}

	cout << endl;
}


/*void save_data(Pipestruct& pipe1, Compressor_Station& CS1)
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
} */

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
	//	case 6:
	//		save_data(pipe, CS);
	//		break;
	//	case 7:
	//		load_data(pipe, CS);
	//		break;
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