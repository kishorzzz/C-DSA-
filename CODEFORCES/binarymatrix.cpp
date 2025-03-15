#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int> > matrix(n, vector<int>(m));
    
    // Read matrix
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            matrix[i][j] = s[j] - '0';
        }
    }
    
    // Calculate row and column XORs
    vector<int> row_xor(n, 0);
    vector<int> col_xor(m, 0);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            row_xor[i] ^= matrix[i][j];
            col_xor[j] ^= matrix[i][j];
        }
    }
    
    // Count ones in rows and columns
    int row_ones = 0, col_ones = 0;
    for(int i = 0; i < n; i++) row_ones += row_xor[i];
    for(int j = 0; j < m; j++) col_ones += col_xor[j];
    
    // If one is odd and other is even, impossible
    if(row_ones % 2 != col_ones % 2) {
        cout << -1 << "\n";
        return;
    }
    
    // Answer is the maximum of row_ones and col_ones
    cout << max(row_ones, col_ones) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
} 