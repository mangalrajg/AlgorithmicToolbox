// 1_money_change_again.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int get_change(int m) {
	//write your code here
	std::vector<int> dp[3];
	for (int i = 0; i <= m; i++)
	{
		dp[0].push_back(i);
		dp[1].push_back(0);
		dp[2].push_back(0);
	}
	for (int i = 1; i <= m; i++)
	{
		int n = 3;
		if (i < n)
			dp[1][i] = dp[0][i];
		if (i == n)
			dp[1][i] = dp[1][i - n] + 1;
		if (i > n)
			dp[1][i] = std::min(dp[0][i], dp[1][i - n] + 1);
	}
	for (int i = 0; i <= m; i++)
	{
		int n = 4;
		if (i < n)
			dp[2][i] = dp[1][i];
		if (i == n)
			dp[2][i] = dp[2][i - n] + 1;
		if (i > n)
			dp[2][i] = std::min(dp[1][i], dp[2][i - n] + 1);
	}

	return dp[2][m];
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}