#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        string word;
        cin >> word;
        
        // If word length is more than 10, abbreviate it
        if (word.length() > 10) {
            // First letter + number of letters between + last letter
            cout << word[0] << word.length() - 2 << word[word.length() - 1] << endl;
        } else {
            // Print the word as is if it's not too long
            cout << word << endl;
        }
    }
    
    return 0;
} 