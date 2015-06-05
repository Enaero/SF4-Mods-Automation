#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int strToInt (string s)
{
	int num = 0;
	int power = 0;

	for (int i = s.size()-1; i >= 0; --i)
	{
		num += int(s[i]-'0')*pow(10.0, power++);
	}

	return num;
}

string intToStr (int i)
{
	switch(i)
	{
	case 1:
		return "01";
	case 2:
		return "02";
	case 3:
		return "03";
	case 4:
		return "04";
	case 5:
		return "05";
	case 6:
		return "06";
	case 7:
		return "07";
	case 8:
		return "08";
	case 9:
		return "09";
	case 10:
		return "10";
	default:
		return "00";
	}
}

int main (int argc, char** argv)
{
	if (argc < 2)
		return -1;

	for (int i = 1; i < argc; ++i)
	{
		string file = argv[i];
		int dash = file.find_last_of ('_');
		int dot = file.find('.');

		string file_number = intToStr(strToInt(file.substr(dash+1, dot-dash-1)) + (argc-1)/2);

		string new_file = file.substr(0, dash+1);
		new_file += file_number;
		new_file += file.substr(dot, file.size());

		string command = "copy \"";
		command += file + "\" \"";
		command += new_file + "\"";

		system(command.c_str());
	}

	return 0;
}
/*#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

string numToString (int i)
{
	if (i > 10 || i < 1)
		return "";

	if (i == 10)
		return "10";

	else
		return "0" + ('0' + i);
}

int main (int argc, char** argv)
{
	system("dir /B -/D > SFDuplicateMaker.txt");

	ifstream file ("SFDuplicateMaker.txt");
	string line;

	if (!file.is_open())
	{
		cout << "uh oh";
		cin.get();
	}

	cout << "How many valid files? ";
	int numValidFiles = 0;
	cin >> numValidFiles;

	vector<string> files;
	while(getline(file, line))
	{
		files.push_back(line);
	}

	int level = 1;
	for (int j = 1; j <= numValidFiles; ++j)
	{
		for (int i = 0; i < files.size(); ++i)
		{
			if (files[i].find_last_of(numToString(level*numValidFiles + j)) != string::npos)
			{
				string command = "copy ";
				command += 
			}
		}
	}

	return 0;
}*/