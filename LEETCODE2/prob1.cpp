#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> lastSeen;  // To store the last position of each element
        int start = 0;  // Start of the current sliding window
        int maxSum = INT_MIN;  // Variable to store the maximum sum
        int currentSum = 0;  // Variable to store the sum of the current window

        for (int end = 0; end < n; end++) {
            // If we encounter a duplicate element in the current window
            if (lastSeen.find(nums[end]) != lastSeen.end() && lastSeen[nums[end]] >= start) {
                // Move the start pointer to one position after the last occurrence of the duplicate
                start = lastSeen[nums[end]] + 1;

                // Recalculate the current sum since the window has changed
                currentSum = 0;
                for (int i = start; i <= end; i++) {
                    currentSum += nums[i];
                }
            } else {
                // Add the current element to the sum
                currentSum += nums[end];
            }

            // Update the last seen position of the current element
            lastSeen[nums[end]] = end;

            // Update the maximum sum
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
