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

bool pipe_exist(Pipestruct& pipe1, int x) {
	bool flag = false;
	if (pipe1.pipe_connected.size() != 0) {
		for (int i = 0; i < pipe1.pipe_connected.size(); ++i) {
			if (x != pipe1.pipe_connected[i]) {
				flag = true;
			}
		}
	}
	else
	{
		flag = true;
	}
	return flag;
};

int CS_is_real(Compressor_Station& CS1) {
	int x;
	bool flag = false;
	while (!flag)
	{
		x = value_check();
		for (int i = 1; i <= CS1.CSmap.size(); ++i) {
			if (x == i) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << "Pipe does not exist!" << endl;
		}
	}
	
	return x;
};

int width_check() {
	int x;
	cout << "Input width of a pipe (500/700/1400):" << endl;
	bool flag = false;
	while (!flag)
	{
		cin >> x;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		if (x != 500 && x != 700 && x != 1400)
		{
			cout << "Width must be 500/700/1400. Input correct value:" << endl;
		}
		else
		{
			flag = true;
		}
	}

	return x;
};

void Network::connect(Trio& trio, Compressor_Station& CS1, Pipestruct& Pipe1) {
	int width;
	int count_flag = 0;
	bool flag = false;
	if (CS1.CSmap.size() > 0) {
		width = width_check();
		for (int i = 1; i <= Pipe1.pipemap.size(); ++i)
		{
			if (Pipe1.pipemap[i].diameter == width) {
				if (pipe_exist(Pipe1, i)) {
					trio.pipe = i;
					Pipe1.pipe_connected.push_back(i);
					flag = true;
				}
			}
		}
		if (!flag) {
			cout << "Rigth pipe does not exist. Create a new one" << endl;
		}
		cout << "Starting CS: " << endl;
		trio.start = CS_is_real(CS1);
		cout << "Finishing CS:" << endl;
		trio.finish = CS_is_real(CS1);
		
	}
	else {
		cout << "CS's do not exist!" << endl;
	}
};