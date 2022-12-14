#pragma once
#include <string>
#include <unordered_map>
#include <iostream>
#include <fstream>
using namespace std;

class Compressor_Station
{
private:

	int CS_id = 0;
	string name = "";
	float department_amount = 0;
	float functioning_department_amount = 0;
	float station_efficiency = 0;
	float non_functioning_department_percent = 0;

public:
	
	vector<int> CSfilter;
	unordered_map<int, Compressor_Station> CSmap;

	float comparasion(float bigger_value);

	void save_CS(Compressor_Station& CS1, string file_name);
	void load_CS(Compressor_Station& CS1, string file_name);
	void CS_name_filter();
	void CS_percent_filter();
	void show_CS(int CS_index);
	void redact_CS(int CS_index);
	void CS_adding(Compressor_Station& CS1);
	void edit_CS(Compressor_Station& CS1);
	void find_CS(Compressor_Station& CS1);
};