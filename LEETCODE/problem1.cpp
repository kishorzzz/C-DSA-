// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    // Helper function to find the longest common prefix length between two strings
    int gettinglcp(string& s1, string& s2) {
        int len = 0;
        int minlen = min(s1.length(), s2.length());
        while(len < minlen && s1[len] == s2[len]) {
            len++;
        }
        return len;
    }
    
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        int n = words.size();
        vector<int> result(n, 0);
        
        // If k is 1, we don't need to find common prefix
        if(k == 1) {
            return result;  // Return all zeros
        }
        
        // For each position
        for(int i = 0; i < n; i++) {
            // Skip if remaining words are less than k
            if(n-1 < k) continue;
            
            // Try each word as base
            for(int j = 0; j < n; j++) {
                if(j == i) continue;  // Skip the removed word
                
                vector<int> lcps;
                // Compare with all other words except i and j
                for(int l = 0; l < n; l++) {
                    if(l != i && l != j) {
                        lcps.push_back(gettinglcp(words[j], words[l]));
                    }
                }
                
                // If we don't have enough matches, continue
                if(lcps.size() < k-1) continue;
                
                // Sort lcps in descending order
                sort(lcps.begin(), lcps.end(), greater<int>());
                
                // k-2 is safe here because we checked size >= k-1
                result[i] = max(result[i], lcps[k-2]);
            }
        }
        
        return result;
    }
};
