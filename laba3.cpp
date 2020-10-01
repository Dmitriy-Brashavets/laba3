#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void sort(vector<string>& v);

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
		do {
			word.push_back(fin.get());
		} while (word.back() != '\n' && !fin.eof());
		word.pop_back();
		data.push_back(word);
	} while (!fin.eof());
	fin.close();
	sort(data);
	ofstream fout;
	fout.open(patch.c_str(), ios::trunc | ios::binary);
	for (int i = 0; i < data.size(); i++)
		fout << data[i].c_str() << '\n';
	fout.close();
}

void sort(vector<string> & v)
{
	for (int i = 0; i < v.size() - 1; i++)
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[i].size() > v[j].size()) swap(v[i], v[j]);
			else if (v[i].size() == v[j].size() && v[i] > v[j]) swap(v[i], v[j]);
		}
}
