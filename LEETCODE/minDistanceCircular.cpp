#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> minDistanceQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> answer;
        
        // Process each query
        for(const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            int val = query[2];
            
            // For each number in range, check if we can reduce it to 0
            bool canReduce = true;
            for(int i = l; i <= r; i++) {
                int num = nums[i];
                // Try to reduce the number to 0
                if(num == 0) continue;
                if(val <= num) {
                    canReduce = true;
                } else {
                    canReduce = false;
                    break;
                }
            }
            
            answer.push_back(canReduce ? val : -1);
        }
        
        return answer;
    }
}; 