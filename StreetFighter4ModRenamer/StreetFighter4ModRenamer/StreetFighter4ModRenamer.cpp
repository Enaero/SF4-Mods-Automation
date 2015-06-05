#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (int argc, char** argv)
{
		const unsigned int NAME_LIMIT = 3;
		const char* fileName = "tmp.txt";

		char* name = new char [NAME_LIMIT+1];
		char* num = new char [2];

		string command = "DIR /A:-D /B > ";
		command += fileName;

		std::system (command.c_str());

		string file;
		ifstream input (fileName);

		cout << "Enter name of character: ";
		cin.getline(name, NAME_LIMIT+1);

		cout << endl << "Enter new costume number: ";
		cin.getline(num, 2);

		while (input >> file)
		{
			string n = name;
			string oldFile = file;

			size_t index = file.find(n);
			if (index == string::npos)
			{
				cerr << "ERROR: Name not in file.\n";
				break;
			}

			index = index + n.size();

			if (file[index] == '_')
			{
				file[index+2] = num[0];
			}

			command = "move \"";
			command += oldFile;
			command += "\" \"";
			command += file;
			command += "\"";

			std::system(command.c_str());
		}
		return 0;
}