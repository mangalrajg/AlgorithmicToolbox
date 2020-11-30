#include <iostream>

long long lcm_naive(int a, int b) {
	for (long l = 1; l <= (long long)a * b; ++l)
		if (l % a == 0 && l % b == 0)
			return l;

	return (long long)a * b;
}
long long gcd_fast(long long a, long long b)
{
	long long rem = a % b;
	if (rem == 0)
		return b;

	return gcd_fast(b, rem);
}

long long lcm_fast(long long a, long long b)
{
	long long gcd = gcd_fast(a, b);
	long long bal_a = a / gcd;
	long long bal_b = b / gcd;
	return gcd * bal_a * bal_b;
}

int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << lcm_fast(a, b) << std::endl;
	return 0;
}