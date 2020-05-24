#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
	long long max_product = 0;
	int n = numbers.size();
	int max_number = numbers[0];
	for (int first = 1; first < n; ++first) {
		long long pr = (long long) (((long long)max_number) * ((long long)numbers[first]));
		if (pr > max_product)
			max_product = pr;
		if (numbers[first] > max_number)
			max_number = numbers[first];
	}
	return max_product;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> numbers(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> numbers[i];
	}

	std::cout << MaxPairwiseProduct(numbers) << "\n";
	return 0;
}
