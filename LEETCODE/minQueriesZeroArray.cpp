#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperationsQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        
        // Process each query in sequence and apply them to nums
        for (int k = 1; k <= m; k++) {
            // Create a copy of nums to simulate queries
            vector<int> temp = nums;
            
            // Store array state midway
            vector<int> varmelistra;
            bool canMakeZero = true;
            
            // Process the first k queries
            for (int i = 0; i < k; i++) {
                int l = queries[i][0];
                int r = queries[i][1];
                int val = queries[i][2];
                
                // Apply the query: Decrement elements in range [l, r] by val
                for (int j = l; j <= r; j++) {
                    if (temp[j] >= val) {
                        temp[j] -= val;
                    }
                }
                
                // Store state at midpoint
                if (i == k/2) {
                    varmelistra = temp;
                }
            }
            
            // Check if the array is a zero array after k queries
            bool allZero = true;
            for (int x : temp) {
                if (x != 0) {
                    allZero = false;
                    break;
                }
            }
            
            if (allZero) {
                return k;  // Return the first k where the array becomes a zero array
            }
        }
        
        return -1;  // If no such k exists, return -1
    }
};

int main() {
    Solution solution;
    
    // Test Case 1: [2,0,2]
    vector<int> nums1 = {2, 0, 2};
    vector<vector<int>> queries1 = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
    cout << "Test Case 1: " << solution.minOperationsQueries(nums1, queries1) << endl;
    
    // Test Case 2: [4,3,2,1]
    vector<int> nums2 = {4, 3, 2, 1};
    vector<vector<int>> queries2 = {{1, 3, 2}, {0, 2, 1}};
    cout << "Test Case 2: " << solution.minOperationsQueries(nums2, queries2) << endl;
    
    // Test Case 3: [1,2,3,2,1]
    vector<int> nums3 = {1, 2, 3, 2, 1};
    vector<vector<int>> queries3 = {{0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 4, 1}};
    cout << "Test Case 3: " << solution.minOperationsQueries(nums3, queries3) << endl;
    
    // Test Case 4: [10]
    vector<int> nums4 = {10};
    vector<vector<int>> queries4 = {{0, 0, 4}, {0, 0, 8}, {0, 0, 1}, {0, 0, 10}, {0, 0, 10}};
    cout << "Test Case 4: " << solution.minOperationsQueries(nums4, queries4) << endl;
    
    return 0;
} 