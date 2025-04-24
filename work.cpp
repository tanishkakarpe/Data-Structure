/*
Implement a problem of minimum work to be done 
per day to finish given tasks within D days problem.
Statement: Given an array task[] of size N denoting 
amount of work to be done for each task, the problem 
is to find the minimum amount of work to be done on 
each day so that all the tasks can be completed in at 
most D days. Note: On one day work can be done for 
only one task.
Input: task[] = [3, 4, 7, 15], D = 10 
Output: 4
Input: task[] = [30, 20, 22, 4, 21], D = 6
Output:22
*/



#include <bits/stdc++.h>
using namespace std;

// Function to check if all tasks can be completed 
// with 'tasksPerDay' tasks per day within 'days' days
bool isValid(int tasksPerDay, vector<int>& tasks, int days) {
    int totalDays = 0;
    for (int task : tasks) {
        totalDays += ceil((double)task / tasksPerDay);
        if (totalDays > days) return false; // Exceeds available days
    }
    return totalDays <= days;
}

// Function to find the minimum number of tasks to be done each day
int findMinTasks(vector<int>& tasks, int days) {
    int low = 1, high = *max_element(tasks.begin(), tasks.end());
    int minTasksPerDay = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if current `mid` is valid
        if (isValid(mid, tasks, days)) {
            minTasksPerDay = mid; // Store result
            high = mid - 1;       // Search in the lower half
        } else {
            low = mid + 1;        // Search in the upper half
        }
    }

    return minTasksPerDay;
}

// Driver Code
int main() {
    vector<int> tasks = {3, 4, 7, 15};
    int days = 10;

    cout << findMinTasks(tasks, days) << endl;

    return 0;
}
