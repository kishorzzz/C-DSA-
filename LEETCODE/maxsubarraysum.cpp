#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = 0;
        
        // Try each possible subarray after deletions
        for(int i = 0; i < n; i++) {
            unordered_set<int> seen;
            int currentSum = 0;
            
            // Try extending subarray starting at i
            for(int j = i; j < n; j++) {
                // If current element is already seen, break
                if(seen.count(nums[j])) {
                    break;
                }
                
                // Add current element to set and sum
                seen.insert(nums[j]);
                currentSum += nums[j];
                maxSum = max(maxSum, currentSum);
            }
        }
        
        return maxSum;
    }
    
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        
        // Calculate prefix sums
        for(int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        int maxSum = nums[0];  // Initialize with first element
        unordered_map<int, int> lastSeen;  // Store last position of each number
        int start = 0;  // Start of current window
        
        for(int end = 0; end < n; end++) {
            // If current number was seen before in our window
            if(lastSeen.find(nums[end]) != lastSeen.end() && lastSeen[nums[end]] >= start) {
                // Move start to position after the last occurrence
                start = lastSeen[nums[end]] + 1;
            }
            
            // Update last seen position of current number
            lastSeen[nums[end]] = end;
            
            // Calculate current sum using prefix sums
            int currentSum = prefixSum[end + 1] - prefixSum[start];
            
            // Update maximum sum if current sum is larger
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
    
private:
    void findMaxSum(vector<int>& nums, int index, vector<int>& current, int& maxSum) {
        // Base case: reached end of array
        if(index == nums.size()) {
            // Find maximum sum subarray with unique elements
            maxSum = max(maxSum, maximumUniqueSubarray(current));
            return;
        }
        
        // Option 1: Include current element
        current.push_back(nums[index]);
        findMaxSum(nums, index + 1, current, maxSum);
        current.pop_back();
        
        // Option 2: Skip current element
        findMaxSum(nums, index + 1, current, maxSum);
    }
}; 