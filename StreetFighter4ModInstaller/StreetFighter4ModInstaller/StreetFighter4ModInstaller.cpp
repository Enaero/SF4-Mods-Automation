#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main (int argc, char** argv)
{
		const int LINE_SIZE = 256;
		const int NAME_SIZE = 4;
		const char* fileName = "modfiles.txt";

		char* modDir = new char[LINE_SIZE];
		char* costumeDir = new char[LINE_SIZE];

		char* name = new char[NAME_SIZE];
		char* costume_num = new char[2];

		cout << "Enter directory of the mods (max " << LINE_SIZE << " characters):\n";
		cin.getline(modDir, LINE_SIZE);

		size_t modDirLen = 0;

		for (; modDir[modDirLen] != '\0'; ++modDirLen)
		{}

		if (modDirLen == 0) modDir = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\Super Street Fighter IV - Arcade Edition\\resource\\battle\\chara";

		cout << "\nEnter which character you want to mod (use their 3 letter names):\n";
		cin.getline(name, NAME_SIZE);

		cout << "\nEnter which costume number to use: \n";
		cin.getline(costume_num, 2);

		cout << endl << "Enter the name of the folder which contains the costume data: " << endl;
		cin.getline(costumeDir, LINE_SIZE);

		//cout << endl << modDir << endl << name << endl << costumeDir;

		/*string command = "cd \"";
		command += modDir;
		command += "\"";
		cout << "command: " << command.c_str() << endl;
		system(command.c_str());

		// DOESTN WORK
		system ("cd");
		system("PAUSE");
		*/

		string command = "DIR /A:-D /B \"";
		command += modDir;
		command += "\\";
		command += costumeDir;
		command += "\" > ";
		command += fileName;

		cout << endl;
		cout << "command: " << command << endl << endl;
		cin.get();

		std::system(command.c_str());
		ifstream input (fileName);

		string file = "";

		while (input >> file)
		{
			command = "copy \"";

			command += modDir;
			command += "\\";
			command += costumeDir;
			command += "\\";
			command += file;

			command += "\" \"";

			string n = name;
			size_t index = file.find(n);
			if (index == string::npos)
			{
				cerr << "ERROR: Name not in file.\n";
				break;
			}

			index = index + n.size();

			if (file[index] == '_')
			{
				file[index+2] = costume_num[0];
			}

			command += modDir;
			command += "\\";
			command += name;
			command += "\\";
			command += file;
			command += "\"";
			cout << "copy command: " << command.c_str() << endl;

			std::system(command.c_str());
		}


		std::system("PAUSE");

		return 0;
}