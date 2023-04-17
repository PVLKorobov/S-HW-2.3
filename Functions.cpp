#include "Header.h"
using std::to_string;


vector<int> parseDateString(string input)
{
	vector<int> res;
	int prevPos = 0, pos = 0;
	while (input.find(' ', prevPos + 1) != string::npos)
	{
		string buffer;
		pos = input.find(' ', prevPos + 1);
		if (prevPos == 0)
			buffer = input.substr(prevPos, pos - prevPos);
		else
			buffer = input.substr(prevPos, pos - prevPos + 1);
		res.push_back(stoi(buffer));
		prevPos = pos;

		if (input.find(' ', prevPos + 1) == string::npos)
		{
			buffer = input.substr(prevPos, input.length() - 1);
			res.push_back(stoi(buffer));
		}
	}
	return res;
}

string printDate(Date date)
{
	return to_string(date.day) + to_string(date.month) + to_string(date.year);
}

void printIf(Worker input)
{
	if (input.contractDuration <= 5)
	{
		cout << input.surname << " -- " << input.position << '\n';
		cout << "Оклад: " << input.salary << '\n';
		cout << "Дата подписания контракта: " << printDate(input.contractSignDate) << '\n';
		cout << "Срок действия контракта: " << input.contractDuration << '\n';
	}
}

