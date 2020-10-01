#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	setlocale(0, "RUS");
	ifstream fin;
	string patch;
	getline(cin, patch);
	fin.open(patch.c_str(), ios::binary);
	vector<string> data;
	do {
		string word;
		fin >> word;
		data.push_back(word);
	} while (!fin.eof());
	fin.close();
	for (auto i = 0; i < data.size(); i++)
		cout << data[i] << endl;
	cout << "\n";
	for (int i = 0; i < data.size() - 1; i++)
		for (int j = i + 1; j < data.size(); j++)
			if (strcmp(data[i].c_str(), data[j].c_str()) > 0) swap(data[i], data[j]);
	for (int i = 0; i < data.size() - 1; i++)
		for (int j = i + 1; j < data.size(); j++)
			if (data[i].size() > data[j].size()) swap(data[i], data[j]);
	for (auto i = 0; i < data.size(); i++)
		cout << data[i] << endl;
	ofstream fout;
	fout.open(patch.c_str(), ios::trunc | ios::binary);
	for (int i = 0; i < data.size(); i++)
		fout << data[i].c_str() << '\n';
	fout.close();
}
