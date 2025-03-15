#include <iostream>
using namespace std;
typedef long long ll;

void solve() {
    ll x, n, m;
    cin >> x >> n >> m;
    
    // If no operations, return x, x
    if (n == 0 && m == 0) {
        cout << x << " " << x << "\n";
        return;
    }
    
    // Key observation: After a few operations, the numbers become very small
    // For any number > 2, floor(x/2) and ceil(x/2) differ by at most 1
    // And both operations essentially divide by 2
    
    // First, find how many times we need to divide by 2 to get to 0 or 1
    ll total = n + m;
    ll minVal = x, maxVal = x;
    
    while (total > 0 && (minVal > 1 || maxVal > 1)) {
        ll new_min = (minVal + 1) / 2;  // ceil
        ll new_max = (maxVal + 1) / 2;  // ceil
        
        if (n > 0) {
            new_min = min(new_min, minVal / 2);  // floor
            new_max = max(new_max, maxVal / 2);  // floor
        }
        
        minVal = new_min;
        maxVal = new_max;
        
        if (n > 0) n--;
        else m--;
        total--;
    }
    
    cout << minVal << " " << maxVal << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
} 