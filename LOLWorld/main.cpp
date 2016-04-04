#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

enum line_t
{
	MID = 1 << 0
	, TOP = 1 << 1
	, JUNGLE = 1 << 2
	, ADC = 1 << 3
	, SUP = 1 << 4
};

struct player_t
{
	string			name;
	int				point;
	vector<line_t>	lines;

	player_t(ifstream & fin)
		: name()
		, lines()
	{
		fin >> name >> point;

		string line;
		getline(fin, line);
		stringstream linein(line);
		
		while (linein.eof() == false)
		{
			string lineattr;
			linein >> lineattr;
			lines.push_back(GetLineValue(lineattr));
		}
	}

	line_t GetLineValue(const string & a)
	{
		if (a == "mid")
		{
			return MID;
		}
		else if (a == "top")
		{
			return TOP;
		}
		else if (a == "jungle")
		{
			return JUNGLE;
		}
		else if (a == "sup")
		{
			return SUP;
		}
		else if (a == "adc")
		{
			return ADC;
		}
	}

	void Dump()
	{
		cout << name << " : ";
		for (auto line : lines)
		{
			cout << line << " ";
		}
		cout << endl;
	}
};

vector<player_t> players;

void GetPlayers()
{
	ifstream fin("players.txt");

	while (fin.eof() == false)
	{
		player_t p(fin);
		players.push_back(p);
	}
}

void DumpPlayers()
{
	for (auto & p : players)
	{
		p.Dump();
	}
}

int main()
{
	GetPlayers();

	DumpPlayers();

	return 0;
}