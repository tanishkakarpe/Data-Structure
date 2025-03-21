/*Implement program to find all distinct subsets of a 
given set using Bit Masking Approach.
Statement Given an array of integers arr[], The task is 
to find all its subsets. The subset cannot contain 
CO4
 Sanjivani College of Engineering, Kopargaon Page 40 of 100
duplicate elements, so any repeated subset should be 
considered only once in the output.
Input: S = {1, 2, 2} Output: {}, {1}, {2}, {1, 2}, {2, 
2}, {1, 2,2}
Input: S = {1, 2} Output: {}, {1}, {2}, {1, 2}
*/



#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 

void genSubs(int idx, vector<int>& arr, vector<int>& curr, vector<vector<int>>& res) { 
    res.push_back(curr); // Add current subset to result
    for (int i = idx; i < arr.size(); i++) { 
        if (i != idx && arr[i] == arr[i - 1]) 
            continue; // Skip duplicates

        curr.push_back(arr[i]); 
        genSubs(i + 1, arr, curr, res); 
        curr.pop_back(); // Backtrack to try other subsets
    } 
} 

vector<vector<int>> findSubs(int arr[], int n) { 
    vector<int> nums(arr, arr + n); 
    vector<int> temp; 
    sort(nums.begin(), nums.end()); // Sort to handle duplicates
    vector<vector<int>> result; 
    genSubs(0, nums, temp, result); 
    return result; 
} 

int main() { 
    int input[] = { 10, 12, 12 }; 
    vector<vector<int>> subsets = findSubs(input, 3); 

    // Print all unique subsets
    for (auto subset : subsets) { 
        cout << "["; 
        for (int i = 0; i < subset.size(); i++) { 
            cout << subset[i]; 
            if (i < subset.size() - 1) { 
                cout << ", "; 
            } 
        } 
        cout << "], "; 
    } 

    return 0; 
} 
