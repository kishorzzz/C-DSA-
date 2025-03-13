#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; 
    }
}

int main() {
    vector<int> v;
    v.push_back(5);
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(8);
    bubbleSort(v);
    for (int i : v)
        cout << i << " ";
    return 0;
}
