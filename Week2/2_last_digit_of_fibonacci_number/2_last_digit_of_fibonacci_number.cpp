#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (int i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        //std::cout << i+2 << "\t" << current << std::endl;
    }

    return current % 10;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n%60);
    std::cout << c << '\n';
}
