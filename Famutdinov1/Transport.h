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
	unordered_map <int, Trio> NW_member;
	vector<Trio> connection;
public:
	void connect(Trio& trio, Compressor_Station& CS1, Pipestruct& Pipe1);
};
