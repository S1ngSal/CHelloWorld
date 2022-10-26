#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

int Pipe_id = 0;
int CS_id = 0;

struct Pipestruct
{
	float length = 0;
	float diameter = 0;
	int working = 1;
};

//struct TestStruct
//{
//	float a;
//	float b;
//	float c;
//};

//typedef struct struct1 {
//	int a;
//	int b;
//	float c;
//	float d;
//} my_struct_t;

//std::map< float, my_struct_t > my_struct_map;

struct Compressor_Station
{
	string name = "";
	int department_amount = 0;
	int functioning_department_amount = 0;
	float station_efficiency = 0;
};

map<int, Pipestruct> pipemap;
map<int, Compressor_Station> CSmap;
pair<int, Pipestruct> pipepair;
pair<int, Compressor_Station> CSpair;

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
	cout << "1. Add a pipe   2. Add a CS   3. View all objects   4. Edit a pipe   5. Edit a CS   6. Save   7. Load   8. Exit" << endl;
	return error_check();
}

void pipe_adding(Pipestruct& pipe1)
{
	Pipe_id ++;
	cout << "Pipe length: ";
	pipe1.length = value_check();
	cout << "Pipe diameter: ";
	pipe1.diameter = value_check();
	cout << "Is pipe working? (If it is - type 2 else type 1): ";
	pipe1.working = work_check();
	cout << endl;
	pipepair = make_pair(Pipe_id, pipe1);
	pipemap.insert(pipepair);
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
	cout << "CS efficiency: ";
	CS1.station_efficiency = value_check();
	cout << endl;
	CSpair = make_pair(CS_id, CS1);
	CSmap.insert(CSpair);
}

void inspect(Pipestruct& pipe1, Compressor_Station& CS1)
{
	cout << endl;
	if (Pipe_id > 0)
	{
		for (int i = 1; i <= Pipe_id; i++)
		{
			auto it = pipemap.find(i);
			cout << "Pipe " << i  << ":" << endl;
			cout <<"  Pipe length: " << it->second.length << endl;
			cout <<"  Pipe diameter: " << it->second.diameter << endl;
			if (it->second.working == 2)
			{
				cout << "  Pipe is working" << endl;
			}
			else
			{
				cout << "  Pipe is not working" << endl;
			}
		}
		cout << endl;
	}
	else
	{
		cout <<"Pipes do not exist"<< endl;
	}
	cout << endl;


	if (CS_id > 0)
	{
		for (int i = 1; i <= CS_id; i++)
		{
			auto it = CSmap.find(i);
			cout << "Compressor Station " << i << ":" << endl;
			cout << "  CS name: " << it->second.name << endl;
			cout << "  Amount of deparments: " << it->second.department_amount << endl;
			cout << "  Amount of functioning deparments: " << it->second.functioning_department_amount << endl;
			cout << "  CS efficiency: " << it->second.station_efficiency << endl;
		}
		cout << endl;
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
		pipe1.working = work_check();
	}
	else {
		cout << "Pipe does not exist " << endl;
	}
}

void edit_CS(Compressor_Station& CS1)
{
	if (CS1.department_amount > 0) {
		cout << "Amount of functioning departments: ";
		CS1.functioning_department_amount = comparasion(CS1.department_amount);
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

//	my_struct_t st = { 1, 2, 3.0, 4.0 };
//	std::pair< float, my_struct_t > p = std::make_pair(st.c, st);
//	my_struct_map.insert(p);
//	st = {5, 6, 7.0, 8.0};
//	p = make_pair(1, st);
//	my_struct_map.insert(p);

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