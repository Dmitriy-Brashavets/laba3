#include <string>
#include <vector> 
#include <fstream> 
#include <iostream> 

using namespace std;
vector<string> get_data(const string&);
int main() {
	string file = "data.txt";
	int parameter;
	cout << "Parameter: ";
	cin >> parameter;
	vector<string> data = get_data(file);
	for (auto i = data.begin(); i < data.end(); i++)
		if (i->size() < parameter) data.erase(i--);
	vector<string> copy = data;
	int count = 0;
	for (int i = 0; i < data.size(); i++) {
		count = 0;
		for (int j = i + 1; j < data.size(); j++) {
			bool flag_cmp = true;
			for (int f = 0; f < parameter; f++) {
				if (data[i][f] != data[j][f]) flag_cmp = false;
				if (!flag_cmp) break;
			}
			if (flag_cmp) {
				count++;
				data.erase(begin(data) + j);
				j--;
			}
		}
		if (count) {
			data.erase(begin(data) + i);
			i--;
		}
	}
	for (auto i = copy.begin(); i + 1 < copy.end(); i++)
		for (auto j = i + 1; j < copy.end(); j++)
			if (*i == *j)copy.erase(j--);
	for (int i = 0; i < copy.size() - 1; i++)
	{
		for (int j = i + 1; j < copy.size(); j++)
			if (copy[i] > copy[j]) swap(copy[i], copy[j]);
		cout << copy[i] << endl;
	}
	return 0;
}

vector<string> get_data(const string & s) {
	ifstream file(s);
	vector<string> data;
	while (!file.eof()) {
		string temp;
		file >> temp;
		data.push_back(temp);
	}
	file.close();
	return data;
}
