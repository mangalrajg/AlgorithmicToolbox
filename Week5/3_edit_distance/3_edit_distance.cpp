// 3_edit_distance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

int edit_distance(const string& str1, const string& str2) {
	vector<vector<int>> arr(str2.length() + 1, vector<int>(str1.length() + 1));

	for (int i = 0; i <= str1.length(); i++)
		arr[0][i] = i;
	for (int i = 0; i <= str2.length(); i++)
		arr[i][0] = i;
	for (int i2 = 1; i2 <= str2.length(); i2++) // distance
	{
		for (int i1 = 1; i1 <= str1.length(); i1++) //editing
		{
			int cost = 1;
			if (str1[i1 - 1] == str2[i2 - 1])
				cost = 0;

			int c_1 = arr[i2][i1 - 1] + 1;
			int c_2 = arr[i2 - 1][i1] + 1;
			int c_3 = arr[i2 - 1][i1 - 1] + cost;
			arr[i2][i1] = std::min(c_1, std::min(c_2, c_3));
		}
	}
	return arr[str2.length()][str1.length()];
}

int main() {
	//string str1 = "short";
	//string str2 = "ports";
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	std::cout << edit_distance(str1, str2) << std::endl;
	return 0;
}