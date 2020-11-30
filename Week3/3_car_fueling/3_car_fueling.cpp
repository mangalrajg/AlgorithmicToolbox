#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int compute_min_refills(int dist, const int tank, vector<int>& stops) {
	// write your code here
	int totalStops = 0;
	int lastStop = 0;
	stops.push_back(dist);
	for (int i = 0; i < stops.size(); i++)
	{
		while ((stops[i] - lastStop) <= tank)
		{
			i++;
			if (i >= stops.size())
				return totalStops;
		}
		i--;
		if (stops[i] == lastStop)
			return -1;
		lastStop = stops[i];
		totalStops++;
	}
	return totalStops;
}

int main() {
	int d = 0;
	cin >> d;
	int m = 0;
	cin >> m;
	int n = 0;
	cin >> n;

	vector<int> stops(n);
	for (size_t i = 0; i < n; ++i)
		cin >> stops.at(i);

	cout << compute_min_refills(d, m, stops) << "\n";

	return 0;
}