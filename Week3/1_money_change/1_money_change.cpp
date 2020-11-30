#include <iostream>

int get_change_impl(int* remainingCoins, int balanceSize, int balanceAmount)
{
	if (balanceSize > 0)
	{
		int currCoin = remainingCoins[0];
		return balanceAmount / currCoin + get_change_impl(&remainingCoins[1], balanceSize - 1, balanceAmount % currCoin);
	}
	return 0;
}
int get_change(int m) {
	int remainingCoins[3] = { 10,5,1 };
	int n = get_change_impl(remainingCoins, 3, m);
	return n;
}
int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}