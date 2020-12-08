#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
vector<int> optimal_sequence_2(int n, vector<int>& inp) {
	if (n % 3 == 0) {
		inp.push_back(n);
		optimal_sequence_2(n % 3, inp);
	}
	return inp;
}
vector<int> optimal_sequence(int n) {
	std::vector<int> dp;
	dp.push_back(-1);
	for (int i = 1; i <= n; i++)
	{
		int c_2, c_1;
		int c_3 = c_2 = c_1 = n;
		if (i % 3 == 0)
			c_3 = dp[int(i / 3)];
		if (i % 2 == 0)
			c_2 = dp[int(i / 2)];
		if (i - 1 >= 0)
			c_1 = dp[i - 1];

		int min = std::min(c_1, std::min(c_2, c_3)) + 1;
		dp.push_back(min);
	}

	std::vector<int> arr;
	int max = dp[n];
	arr.push_back(n);
	//sequence.push_back(max);
	for (int i = n; i > 1; )
	{
		int c_2, c_1;
		int c_3 = c_2 = c_1 = n;
		if (i % 3 == 0)
			c_3 = dp[int(i / 3)];
		if (i % 2 == 0)
			c_2 = dp[int(i / 2)];
		if (i - 1 >= 0)
			c_1 = dp[i - 1];

		if (c_1 <= std::min(c_2, c_3))
		{
			arr.push_back(i - 1);
			i = i - 1;
		}
		else if (c_2 <= std::min(c_1, c_3))
		{
			arr.push_back((int)i / 2);
			i = i / 2;
		}
		else if (c_3 <= std::min(c_1, c_2))
		{
			arr.push_back((int)i / 3);
			i = i / 3;
		}
	}
	std::reverse(arr.begin(), arr.end());
	return arr;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> sequence = optimal_sequence(n);
	std::cout << sequence.size() - 1 << std::endl;
	for (size_t i = 0; i < sequence.size(); ++i) {
		std::cout << sequence[i] << " ";
	}
}