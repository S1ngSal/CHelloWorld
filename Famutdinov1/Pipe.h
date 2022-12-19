#pragma once
#include <string>
#include <unordered_map>
#include <iostream>
#include <fstream>
using namespace std;

class Pipestruct
{
private:

	float length = 0;
	int working = 1;
	vector<int>pipefilter;
	int Pipe_id = 0;
public:
	string pipe_name = "";
	float diameter = 0;
	vector<int> pipe_connected;
	unordered_map<int, Pipestruct> pipemap;

	float work_check();
	void save_pipe(Pipestruct& pipe1, string file_name);
	void load_pipe(Pipestruct& pipe1, string file_name);
	void show_pipe(int pipe_index);
	void pipe_name_filter();
	void pipe_functioning_filter(int x);
	void pipe_adding(Pipestruct& pipe1);
	void pipe_redactng(int pipe_index);
	void edit_pipe(Pipestruct& pipe1);
	void find_pipe(Pipestruct& pipe1);


};