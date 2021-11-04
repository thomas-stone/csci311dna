#include "algorithms.h"
#include <iostream>
#include <vector>

int longestCommonSubstring(std::string s, std::string t){
    int m = s.length();
    int n = t.length();
    //int table[m+1][n+1];
    std::vector<std::vector<int>> table(m+1, std::vector<int>(n+1));

    for (int i = 0; i < m+1; i++){
        for (int j = 0; j < n+1; j++){
            // std::cout << i << ", " << j << "\n";
            table[i][j] = 0;
        }
    }
    
    for (int i = 1; i < m+1; i++){
        for (int j = 1; j < n+1; j++){
            if (std::toupper(s.at(i-1)) == std::toupper(t.at(j-1))){
                table[i][j] = table[i-1][j-1] + 1;
            }
            else {
                table[i][j] = 0;
            }
        }
    }

    int currentBest = 0;
    for (int i = 0; i < m+1; i++){
        for (int j = 0; j < n+1; j++){
            if (table[i][j] > currentBest)
                currentBest = table[i][j];
        }
    }
    
    return currentBest;
}

int longestCommonSubsequence(std::string s, std::string t){
    int m = s.length();
    int n = t.length();
    //int table[m+1][n+1];
    std::vector<std::vector<int>> table(m+1, std::vector<int>(n+1));

    for (int i = 0; i < m+1; i++){
        for (int j = 0; j < n+1; j++){
           table[i][j] = 0;
        }
    }

    // Compare strings
    for (int i = 1; i < m+1; i++){
        for (int j = 1; j < n+1; j++){
            if (std::toupper(s.at(i-1)) == std::toupper(t.at(j-1))){
                table[i][j] = table[i-1][j-1] + 1;
            }
            else if (table[i-1][j] > table[i][j-1]){
                table[i][j] = table[i-1][j];
            }
            else {
                table[i][j] = table[i][j-1];
            }
        }
    }


    // Return bottom right  TODO
    int currentBest = 0;
    for (int i = 0; i < m+1; i++){
        for (int j = 0; j < n+1; j++){
            // std::cout << table[i][j];
            if (table[i][j] > currentBest)
                currentBest = table[i][j];
        }
        //std::cout << "\n";
    }
    
    return currentBest;
    return 0;
}

int editDistance(std::string s, std::string t){
    int m = s.length();
    int n = t.length();
    
    // Create a table to store results of subproblems
    std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1));
   
    // Fill dp[][] in bottom up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If first string is empty, only option is to
            // insert all characters of second string
            if (i == 0)
                dp[i][j] = j; // Min. operations = j
                
            // If second string is empty, only option is to
            // remove all characters of second string
            
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (std::toupper(s.at(i-1)) == std::toupper(t.at(j-1)))
                dp[i][j] = dp[i - 1][j - 1];
  
            // If the last character is different, consider
            // all possibilities and find the minimum
            else
                dp[i][j]
                    = 1
                      + std::min(dp[i][j - 1], // Insert
                            std::min(dp[i - 1][j], // Remove
                            dp[i - 1][j - 1])); // Replace
                            
        }
    }

    return dp[m][n];
}

int needlemanWunsch(std::string s, std::string t){
    std::cout << "Running Needleman Wunsch!";
    return 0;
}
