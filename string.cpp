/*Implement Check if it is possible to transform one 
string to another.
Statement Given two strings s1 and s2 (all letters in uppercase). 
Check if it is possible to convert s1 to s2 by performing following 
operations.
1. Make some lowercase letters uppercase.
2. Delete all the lowercase letters.
Input: s1 = daBcd s2 = ABC Output: yes
Input: s1 = argaju s2 = RAJ Output: yes
*/


#include <bits/stdc++.h>
using namespace std;

bool canConvert(string str1, string str2) {
    int len1 = str1.length(), len2 = str2.length();
    bool dp[len1 + 1][len2 + 1] = {false};

    dp[0][0] = true; // Base case

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (dp[i][j]) {
                if (j < len2 && toupper(str1[i]) == str2[j]) 
                    dp[i + 1][j + 1] = true;
                if (!isupper(str1[i])) 
                    dp[i + 1][j] = true;
            }
        }
    }

    return dp[len1][len2];
}

int main() {
    string str1 = "daBcd", str2 = "ABC";
    cout << (canConvert(str1, str2) ? "YES" : "NO");
    return 0;
}
