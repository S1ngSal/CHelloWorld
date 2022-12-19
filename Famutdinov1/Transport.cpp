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
#include <algorithm>

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
		else
		{
			cout << "Starting CS: " << endl;
			trio.start = CS_is_real(CS1);
			cout << "Finishing CS:" << endl;
			trio.finish = CS_is_real(CS1);
			Network_id++;
			NW_member.insert(make_pair(Network_id,trio));
		}
		
	}
	else {
		cout << "CS's do not exist!" << endl;
	}
};

void Network::show_network(int network_index, Compressor_Station& CS1, Pipestruct& pipe1) {
	if (NW_member.size() > 0) {
		cout << CS1.CSmap[NW_member[network_index].start].name << " - " << pipe1.pipemap[NW_member[network_index].pipe].pipe_name << " - " << CS1.CSmap[NW_member[network_index].finish].name << endl;
	}
};

void Network::show_sorted_network() {
	NW_member_copy = NW_member;
	int count = 0;
	bool flag = true;
	bool flag2;
	vector<int> unsorted_graph;
	vector<int> sorted_graph;
	vector<int> megagraph;
	if (NW_member.size() > 0) {
		unsorted_graph.push_back(NW_member[1].start);
		for (int i = 1; i <= NW_member.size(); ++i) {
			flag = true;
			for (int j = 1; j <= NW_member.size(); ++j) {
				if (NW_member[i].finish == NW_member[j].start) {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			for (int i = 1; i <= NW_member.size(); ++i) {
				megagraph.push_back(NW_member[i].start);
				megagraph.push_back(NW_member[i].finish);
			}
			for (int i : megagraph) {
				flag2 = true;
				for (int j : unsorted_graph) {
					if (megagraph[i - 1] == unsorted_graph[j - 1]) {
						flag2 = false;
						break;
					}
				}
				if (flag2) {
					unsorted_graph.push_back(megagraph[i-1]);
				}
			}
			while (NW_member.size() != count)
			{
				flag2 = true;
				for (int i : unsorted_graph) {
					flag2 = true;
					for (int j = 0; j < NW_member_copy.size(); ++j) {
						if (unsorted_graph[i - 1] == NW_member_copy[j].start) {
							flag2 = false;
							break;
						}
					}
					if (flag2) {
						sorted_graph.push_back(unsorted_graph[i - 1]);
						auto res = remove(unsorted_graph.begin(), unsorted_graph.end(), unsorted_graph[i-1]);
						unsorted_graph.erase(res, unsorted_graph.end());
						for (int j = 0; j < NW_member_copy.size(); ++j) {
							if (sorted_graph[sorted_graph.size()-1] == NW_member_copy[j].finish) {
								NW_member_copy.erase(j);
								count++;
							}
						}
					}
				}
			}
			
		}
		else
		{
			cout << "Graph can not be sorted" << endl;
		}
	}
	else
	{
		cout << "There is no graph!" << endl;
	}
};