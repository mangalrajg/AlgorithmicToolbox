#include <iostream>
#include <vector>
#include<tuple>
#include <algorithm>

using std::vector;
double get_optimal_impl(vector<std::tuple<double, int, int>>& v, int remainingCapacity)
{
	if (v.size() == 0 || remainingCapacity == 0)
	{
		return 0;
	}
	auto& entry = v.back();
	v.pop_back();
	if (std::get<2>(entry) > remainingCapacity)
	{
		return (double)remainingCapacity * std::get<0>(entry);
	}
	else
	{
		return std::get<1>(entry) + get_optimal_impl(v, remainingCapacity - std::get<2>(entry));
	}
}
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;

	// write your code here
	// sort
	int n = weights.size();
	vector<std::tuple<double, int, int>> v;
	for (int i = 0; i < n; i++) {
		v.push_back(std::make_tuple((double)values[i] / (double)weights[i], values[i], weights[i]));
	}

	std::sort(v.begin(), v.end());
	value = get_optimal_impl(v, capacity);

	return value;
}

int main() {
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}