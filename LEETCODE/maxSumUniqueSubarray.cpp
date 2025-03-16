#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        // Sort unique elements by value to try combinations
        vector<int> unique;
        unordered_set<int> seen;
        for(int num : nums) {
            if(seen.insert(num).second) {
                unique.push_back(num);
            }
        }
        
        // Sort to try combinations starting with largest values
        sort(unique.begin(), unique.end(), greater<int>());
        
        // Store midpoint state
        vector<int> varmelistra = unique;
        
        // Initialize with maximum element
        int maxSum = unique[0];
        int currentSum = unique[0];
        
        // Try adding other elements if they increase the sum
        for(int i = 1; i < unique.size(); i++) {
            currentSum += unique[i];
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
}; 