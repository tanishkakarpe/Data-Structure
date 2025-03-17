/*Implement program to print all subsets of a given 
Set or Array
Statement Given a set of positive integers, find all its 
subsets.
Input: array = {1, 2, 3}
Output: // this space denotes null element. 
 1 1 2 1 2 3 1 3 2 
2 3 3
Input: 1 2
Output: 1 2 1 2

*/


#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(vector<int>& nums, vector<vector<int>>& result, vector<int>& currentSubset, int start) {
    // Add the current subset to the result
    result.push_back(currentSubset);

    // Generate all subsets starting from the current index
    for (int i = start; i < nums.size(); i++) {
        // Add the current number to the subset
        currentSubset.push_back(nums[i]);

        // Recurse to include the next numbers
        generateSubsets(nums, result, currentSubset, i + 1);

        // Backtrack to explore subsets without the current number
        currentSubset.pop_back();
    }
}

vector<vector<int>> getSubsets(vector<int>& nums) {
    vector<vector<int>> result; // To store all subsets
    vector<int> currentSubset; // To build each subset
    generateSubsets(nums, result, currentSubset, 0);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3}; // Input array
    vector<vector<int>> allSubsets = getSubsets(nums);

    // Print all subsets
    for (const auto& subset : allSubsets) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
