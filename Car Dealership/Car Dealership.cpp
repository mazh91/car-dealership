// Car Dealership.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	const char* FILE_NAME = "autodata.txt";
	const int MAX_READ = 255;
	ofstream out;
	ifstream  in;
	char input[MAX_READ];

	in.open(FILE_NAME);
	// TEST
	if (in.fail()) {
		out.open(FILE_NAME);
	
		out << "Mazda 6,AWD,V6,Looks Good" << endl;
		out << "Honda Pilot,Large,V6" << endl;
		out.close();

		in.open(FILE_NAME);
	}

	in.getline(input, MAX_READ);


	auto input_str = string(input);

	stringstream ss(input_str);
	vector<string> input_tokens;

	// store input tokens
	while (ss.good()) {
		string substr;
		getline(ss, substr, ',');
		input_tokens.push_back(substr);
	}

	// iterate thru input tokens
	for (auto it = input_tokens.begin(); it != input_tokens.end(); ++it)
		cout << *it << endl;
	
	//cout << input << endl; // prints !!!Hello World!!!
	return 0;
}

