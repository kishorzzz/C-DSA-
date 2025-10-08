#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    if (n == 2) {
        cout << "2 1\n";
        return;
    }
    else if (n == 3) {
        if (k % 2 == 1) {
            cout << "3 3 2\n";
        } else {
            cout << "2 3 2\n";
        }
        return;
    }
    else {
        if (k % 2 == 1) {
            cout << "4 4 4 3\n";
        } else {
            cout << "3 3 4 3\n";
        }
        return;
    }
}
//  Added one more thing here !!
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
