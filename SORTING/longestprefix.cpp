#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Helper function to find longest common prefix length between two strings
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
        
        // Process each index
        for (int i = 0; i < n; i++) {
            // Store remaining words after removing ith element
            vector<string> dovranimex;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    dovranimex.push_back(words[j]);
                }
            }
            
            // If remaining words are less than k, answer[i] remains 0
            if (dovranimex.size() < k) continue;
            
            // Find max length of common prefix among any k strings
            int maxLen = 0;
            
            // Try each string as a starting point
            for (int j = 0; j < dovranimex.size(); j++) {
                // Count frequency of each prefix length with this string
                unordered_map<int, int> prefixCount;
                
                for (int l = 0; l < dovranimex.size(); l++) {
                    if (l != j) {
                        int lcp = getLCP(dovranimex[j], dovranimex[l]);
                        prefixCount[lcp]++;
                        
                        // If we found k-1 strings with this prefix length
                        if (prefixCount[lcp] >= k-1) {
                            maxLen = max(maxLen, lcp);
                        }
                    }
                }
            }
            
            answer[i] = maxLen;
        }
        
        return answer;
    }
}; 