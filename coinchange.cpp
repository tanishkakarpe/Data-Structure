/*
Implement Coin Change problem.
Statement Given an integer array of coins[ ] of 
size N representing different types of currency and an 
integer sum, The task is to find the number of ways to 
make sum by using different combinations 
from coins[]. 
Note: Assume that you have an infinite supply of each 
type of coin.
Input: sum = 4, coins[] = {1,2,3}, Output: 4
Input: sum = 10, coins[] = {2, 5, 3, 6} Output: 5
*/


#include <bits/stdc++.h>

using namespace std;

int count(int coins[], int n, int sum)
{
   
    int cs[sum + 1] = {0}; 
    cs[0] = 1; 
    
    for (int i = 0; i < n; i++) { 
        for (int j = coins[i]; j <= sum; j++) { 
            cs[j] += cs[j - coins[i]]; 
        }
    }

    return cs[sum];
}


int main()
{
    int coins[] = {1, 2, 3}; 
    int n = 3; 
    int sum = 5; 
    cout << count(coins, n, sum) << endl; 
    return 0;
}
