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
	bool flag = false;
	if (CS1.CSmap.size() > 0) {
		cout << "Starting CS: " << endl;
		trio.start = CS_is_real(CS1);
		cout << "Finishing CS:" << endl;
		trio.finish = CS_is_real(CS1);
		width = width_check();
		while (!flag)
		{
			for (int i = 1; i <= Pipe1.pipemap.size(); ++i) {
				if (Pipe1.pipemap[i].diameter == width) {
					for (int j = 1; j <= Pipe1.pipe_connected.size(); ++j) {
						if (j == Pipe1.pipe_connected[j]) {
							cout << "Rigth pipe not found. Create new one: " << endl;
							Pipe1.pipe_adding(Pipe1);
						}
						else
						{
							trio.pipe = i;
							flag = true;
						}
					}
					break;
				}
			}
		}
	}
	else {
		cout << "CS's do not exist!" << endl;
	}
};