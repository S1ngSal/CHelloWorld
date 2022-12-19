#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include "Pipe.h"
#include "Checks.h"
#include "CS.h"

struct Trio
{
private:

public:
	int start;
	int finish;
	int pipe;
};


class Network
{
private:
	int Network_id;
	vector<Trio> connection;
public:
	unordered_map <int, Trio> NW_member;
	unordered_map<int, Trio>NW_member_copy;
	void connect(Trio& trio, Compressor_Station& CS1, Pipestruct& Pipe1);
	void show_network(int network_index, Compressor_Station& CS1, Pipestruct& pipe1);
	void show_sorted_network();
};
