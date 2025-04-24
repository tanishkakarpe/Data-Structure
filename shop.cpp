/*
Implement a problem of activity selection problem 
with K persons.
Statement: Given two arrays S[] and E[] of size N denoting starting 
and closing time of the shops and an integer value K denoting the 
number of people, the task is to find out the maximum number of 
shops they can visit in total if they visit each shop optimally based 
on the following conditions:
 A shop can be visited by only one person
 A person cannot visit another shop if its timing collide with it
Input: S[] = {1, 8, 3, 2, 6}, E[] = {5, 10, 6, 5, 9}, K = 2
Output: 4
Input: S[] = {
*/




#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Comparator function to sort shops by their ending times
bool compare(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}

int maxShopsVisited(vector<int> &S, vector<int> &E, int K) {
    int N = S.size();
    vector<pair<int, int>> shops(N);

    // Create pairs of (start time, end time) and store them
    for (int i = 0; i < N; ++i) {
        shops[i] = {S[i], E[i]};
    }

    // Sort shops by their ending times
    sort(shops.begin(), shops.end(), compare);

    // Vector to track the end time of the latest shop visited by each person
    vector<int> endTimes(K, 0);

    int maxVisited = 0;

    for (int i = 0; i < N; ++i) {
        // Find the first person who can visit this shop (i.e., whose end time <= start time of the current shop)
        int personIndex = -1;
        for (int j = 0; j < K; ++j) {
            if (endTimes[j] <= shops[i].first) {
                personIndex = j;
                break;
            }
        }

        // If there is an available person, assign the shop to that person
        if (personIndex != -1) {
            endTimes[personIndex] = shops[i].second;
            maxVisited++;
        }
    }

    return maxVisited;
}

int main() {
    int N, K;

    // Input number of shops
    cout << "Enter the number of shops: ";
    cin >> N;

    vector<int> S(N), E(N);

    // Input starting times of shops
    cout << "Enter the starting times of the shops: ";
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    // Input ending times of shops
    cout << "Enter the ending times of the shops: ";
    for (int i = 0; i < N; ++i) {
        cin >> E[i];
    }

    // Input the number of persons
    cout << "Enter the number of persons: ";
    cin >> K;

    // Calculate the maximum number of shops that can be visited
    int result = maxShopsVisited(S, E, K);

    // Output the result
    cout << "Maximum number of shops visited: " << result << endl;

    return 0;
}
