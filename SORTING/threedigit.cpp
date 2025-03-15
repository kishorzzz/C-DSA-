#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;  // To store the numbers in sorted order
        set<int> uniqueNums;  // To handle duplicates
        int n = digits.size();
        
        // Try all possible combinations of three digits
        for(int i = 0; i < n; i++) {
            // Skip if first digit is 0
            if(digits[i] == 0) continue;
            
            for(int j = 0; j < n; j++) {
                if(j == i) continue;  // Skip if same position
                
                for(int k = 0; k < n; k++) {
                    if(k == i || k == j) continue;  // Skip if same position
                    
                    // Form the number
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    
                    // Check if it's even
                    if(num % 2 == 0) {
                        uniqueNums.insert(num);
                    }
                }
            }
        }
        
        // Convert set to vector for sorted output
        result.assign(uniqueNums.begin(), uniqueNums.end());
        return result;
    }
};

int main() {
    int n;
    cin >> n;  // Size of array
    
    vector<int> digits(n);
    for(int i = 0; i < n; i++) {
        cin >> digits[i];
    }
    
    Solution sol;
    vector<int> result = sol.findEvenNumbers(digits);
    
    // Print the result
    cout << result.size() << endl;  // First print the count
    for(int num : result) {
        cout << num << " ";  // Then print all the numbers
    }
    cout << endl;
    
    return 0;
} 