#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int countOccurance(vector<int>& a, int elem, int left, int right)
{
	int ret = 0;
	for (auto it = a.begin() + left; it < a.begin() + right; it++)
	{
		if (*it == elem)
			ret++;
	}
	return ret;
}
int get_majority_element(vector<int>& a, int left, int right) {
	if (left == right) return -1;
	if (left + 1 == right) return a[left];
	//write your code here
	int mid = (left + right) / 2;
	int len = right - left;
	int leftMaj = get_majority_element(a, left, mid);
	int rightMaj = get_majority_element(a, mid, right);

	if (leftMaj == rightMaj)
		return leftMaj;

	int lCount = leftMaj == -1 ? -1 : countOccurance(a, leftMaj, left, right);
	int rCount = rightMaj == -1 ? -1 : countOccurance(a, rightMaj, left, right);

	if (lCount > len / 2)
		return leftMaj;
	if (rCount > len / 2)
		return rightMaj;
	return -1;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}