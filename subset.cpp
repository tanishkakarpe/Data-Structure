/*
Implement Subset Sum Problem.
Statement Given a set of non-negative integers and a 
value sum, the task is to check if there is a subset of the 
given set whose sum is equal to the given sum.
Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9 
Output: True
Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30 
Output: False
*/


#include <bits/stdc++.h>
using namespace std;

bool subsetSumRec(vector<int>& arr, int n, int sum) {
    if (sum == 0) return true;
    if (n == 0) return false;
    if (arr[n - 1] > sum) return subsetSumRec(arr, n - 1, sum);
    return subsetSumRec(arr, n - 1, sum) || subsetSumRec(arr, n - 1, sum - arr[n - 1]);
}

bool subsetSum(vector<int>& arr, int sum) {
    return subsetSumRec(arr, arr.size(), sum);
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    cout << (subsetSum(arr, sum) ? "True" : "False") << endl;
    return 0;
}
