#include <string> 
#include <vector> 
#include <fstream> 
#include <iostream> 

using namespace std;
vector<string> get_data(const string&);
int main() {
	string file = "data.txt";
	int parameter;
	cout В« "Parameter: ";
	cin В» parameter;
	vector<string> data = get_data(file);
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
	for (int i = 0; i < copy.size(); i++) {
		bool flag_repeat = false;
		for (int j = 0; j < data.size(); j++) {
			if (copy[i] == data[j]) {
				flag_repeat = true;
				break;
			}
		}
		if (!flag_repeat) {
			cout В« copy[i] В« endl;
		}
	}
	return 0;
}

vector<string> get_data(const string& s) {
	ifstream file(s);
	vector<string> data;
	while (!file.eof()) {
		string temp;
		file В» temp;
		data.push_back(temp);
	}
	file.close();
	return data;
}
