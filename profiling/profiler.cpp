#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
	string avrg = "" , formula = "";
	vector<int> inputs;
	int x;
	size_t i = 1;
	double average;
	while (cin >> x) {
		inputs.push_back(x);
	}
	avrg += "(" + to_string(inputs[0]);
	for (size_t n = 1; n < inputs.size(); n++)
	{
		i++;	
		avrg += "+" + to_string(inputs[n]);
	}
	avrg += "):" + to_string(i) + "=";

	system(("./kaukulacka_pro_cumacky \""+avrg+"\"> temp.txt").c_str());

	ifstream fin("temp.txt");

	fin >> average;

	system("rm temp.txt");

	formula += "2s(((" + to_string(inputs[0]) + "-" + to_string(average) + ")^2";
	
	for (size_t n = 1; n < inputs.size(); n++)
	{
		formula += "+(" + to_string(inputs[n]) + "-" + to_string(average) + ")^2";
	}

	formula += "):(" + to_string(i) +"-1))=";

	system(("./kaukulacka_pro_cumacky \""+formula+"\"").c_str());

	return 0;
}

