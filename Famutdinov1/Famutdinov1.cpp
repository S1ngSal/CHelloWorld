#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

float value_check();
int error_check();
float work_check();
float comparasion(float bigger_value);

/*class MyClass
{
public:
	map<int, int> MyClass_map;
	pair<int, int> MyClass_pair;
	int a = 1;
	float one()
	{
		cout << "1234" << endl;
		MyClass_map = make_pair(1, 2);
		return value_check();
	}

};*/



class Pipestruct
{
private:
public:
	float length = 0;
	float diameter = 0;
	int working = 1;
	int Pipe_id = 0;
	map<int, Pipestruct> pipemap;

	void pipe_adding(Pipestruct& pipe1)
	{
		Pipe_id++;
		cout << "Pipe length: ";
		pipe1.length = value_check();
		cout << "Pipe diameter: ";
		pipe1.diameter = value_check();
		cout << "Is pipe working? (If it is - type 2 else type 1): ";
		pipe1.working = work_check();
		cout << endl;
		pipemap.insert(make_pair(Pipe_id,pipe1));
	}

	void edit_pipe(Pipestruct& pipe1)
	{
		bool pipe_edit_switch = true;
		while (pipe_edit_switch)
		{
			cout << "Type 1 to edit pipes" << endl << "Type 2 to delete a pipe" << endl << "Type 3 to stop editing" << endl;
			switch (error_check())
			{
			case 1:
				if (Pipe_id > 0) {
					cout << "Is pipe working? (If it is - type 2 else type 1): ";
					pipe1.working = work_check();
				}
				else {
					cout << "Pipe does not exist " << endl;
				}
				break;
			case 2:
				cout << "Input id of the pipe: " << endl;
				{int pipe_del_id = error_check();
				pipemap.erase(pipe_del_id); }
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

class Compressor_Station
{
private:

public:
	string name = "";
	int department_amount = 0;
	int functioning_department_amount = 0;
	float station_efficiency = 0;
	int CS_id = 0;
	map<int, Compressor_Station> CSmap;

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
		CSmap.insert(make_pair(CS_id, CS1));
	}

	void edit_CS(Compressor_Station& CS1)
	{
		bool edit_CS_switch = true;
		while (edit_CS_switch)
		{
			cout << "Type 1 to edit CS's" << endl << "Type 2 to delete a CS" << endl << "Type 3 to stop editing" << endl;
			switch (error_check())
			{
			case 1:
				if (CS_id > 0) {
					cout << "Amount of functioning departments: ";
					CS1.functioning_department_amount = comparasion(CS1.department_amount);
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
				edit_CS_switch = false;
				break;
			default:
				cout << endl << "Enter a valid command id" << endl;
				break;
			}
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
	cout << "1. Add a pipe   2. Add a CS   3. View all objects   4. Edit a pipe   5. Edit a CS   6. Save   7. Load \n  8. Exit" << endl;
	return error_check();
}





void inspect(Pipestruct& pipe1, Compressor_Station& CS1)
{
	cout << endl;
	if (pipe1.Pipe_id > 0)
	{
		for (int i = 1; i <= pipe1.Pipe_id; i++)
		{	
			auto it = pipe1.pipemap.find(i);
			if (it != pipe1.pipemap.end()) {
				cout << "Pipe " << i << ":" << endl;
				cout << "  Pipe length: " << it->second.length << endl;
				cout << "  Pipe diameter: " << it->second.diameter << endl;
				if (it->second.working == 2)
				{
					cout << "  Pipe is working" << endl;
				}
				else
				{
					cout << "  Pipe is not working" << endl;
				}
			}
		}
		cout << endl;
	}
	else
	{
		cout <<"Pipes do not exist"<< endl;
	}
	cout << endl;


	if (CS1.CS_id > 0)
	{
		for (int i = 1; i <= CS1.CS_id; i++)
		{
			auto it = CS1.CSmap.find(i);
			if (it != CS1.CSmap.end()) {
				cout << "Compressor Station " << i << ":" << endl;
				cout << "  CS name: " << it->second.name << endl;
				cout << "  Amount of deparments: " << it->second.department_amount << endl;
				cout << "  Amount of functioning deparments: " << it->second.functioning_department_amount << endl;
				cout << "  CS efficiency: " << it->second.station_efficiency << endl;
			}
		}
		cout << endl;
	}
	else
	{
		cout << "Compressor Stations does not exist" << endl;
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
//	my_struct_t st = { 1, 2, 3.0, 4.0 };
//	std::pair< float, my_struct_t > p = std::make_pair(st.c, st);
//	my_struct_map.insert(p);
//	st = {5, 6, 7.0, 8.0};
//	p = make_pair(1, st);
//	my_struct_map.insert(p);
//	MyClass q;
//	q.one();
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
			keep_running = false;
			break;
		default:
			cout << endl << "Enter a valid command id" << endl;
			break;
		}
	}
	return 0;
}