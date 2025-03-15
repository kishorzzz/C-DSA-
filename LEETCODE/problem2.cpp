// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

class Solution {
public:
    // Helper function to find the longest common prefix length between two strings
    int getLCP(string& s1, string& s2) {
        int len = 0;
        int minLen = min(s1.length(), s2.length());
        while (len < minLen && s1[len] == s2[len]) {
            len++;
        }
        return len;
    }

    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        int n = words.size();
        vector<int> answer(n, 0);
        
        // Precompute LCP for all pairs of words
        vector<vector<int>> lcp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                lcp[i][j] = lcp[j][i] = getLCP(words[i], words[j]);
            }
        }

        // Process each word
        for (int i = 0; i < n; i++) {
            // We need to find the longest common prefix among k strings excluding the i-th word.
            vector<int> remainingLCPs;
            
            // Collect all the LCPs for the words excluding the i-th word
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    remainingLCPs.push_back(j);
                }
            }
            
            // Try to find the maximum common prefix among any k words
            int maxLen = 0;
            for (int j = 0; j < remainingLCPs.size(); j++) {
                int minPrefixLen = INT_MAX;
                
                // Compare this word with all other words in the remaining set
                for (int l = j + 1; l < remainingLCPs.size(); l++) {
                    int lcpLen = lcp[remainingLCPs[j]][remainingLCPs[l]];
                    minPrefixLen = min(minPrefixLen, lcpLen);
                }
                
                // Update maxLen with the smallest LCP for this pair of words
                maxLen = max(maxLen, minPrefixLen);
            }
            
            answer[i] = maxLen;
        }
        
        return answer;
    }
};
