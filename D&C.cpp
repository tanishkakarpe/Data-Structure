/*
Implement a problem of smallest number with at 
least n trailing zeroes in factorial.
Statement: Given a number n. The task is to find the 
smallest number whose factorial contains at least n 
trailing zeroes.
Input : n = 1 Output : 5 
Input : n = 6 Output : 25
CO1
B 1. Implement a problem of activit
*/





#include <iostream>

using namespace std;

int trailingZeroes(int n) {
    int count = 0;
    while (n >= 5) {
        count += n / 5;
        n /= 5;
    }
    return count;
}

int findNumWithNTrailingZeros(int n) {
    long long low = 0, high = 5 * n;
    while (low < high) {
        long long mid = (low + high) / 2;
        int zeros = trailingZeroes(mid);
        if (zeros < n) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    int n;
    cout << "Enter the number of trailing zeros: ";
    cin >> n;

    int result = findNumWithNTrailingZeros(n);
    cout << "The smallest number with at least " << n << " trailing zeros is: " << result << endl;
    return 0;
}
