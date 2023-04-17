#include <sstream>
#include <iostream>
#include <ctime>
#include <vector>
using std::vector;
using std::stoi;
using std::getline;
using std::string;
using std::cout;

struct Date
{
	int day;
	int month;
	int year;
};

struct Worker
{
	string surname;
	string position;
	Date contractSignDate;
	int contractDuration;
	int salary;
};


vector<int> parseDateString(string input);
void printIf(Worker input);