#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Spreadsheet {
private:
    int numRows;
    unordered_map<string, int> cells; 
    int getCellValue(const string& cell) {
        return cells.count(cell) ? cells[cell] : 0;
    }
    int parseValue(const string& token) {
        if (isdigit(token[0])) {
            return stoi(token);
        }
        return getCellValue(token);
    }
public:
    Spreadsheet(int rows) {
        numRows = rows;
    }
    void setCell(string cell, int value) {
        cells[cell] = value;
    }
    void resetCell(string cell) {
        cells.erase(cell); 
    }
    int getValue(string formula) {
        formula = formula.substr(1);
        size_t plusPos = formula.find('+');
        string first = formula.substr(0, plusPos);
        string second = formula.substr(plusPos + 1);
        return parseValue(first) + parseValue(second);
    }
};
void test() {
    Spreadsheet spreadsheet(3);
    
    cout << spreadsheet.getValue("=5+7") << endl;        // 12
    spreadsheet.setCell("A1", 10);
    cout << spreadsheet.getValue("=A1+6") << endl;       // 16
    spreadsheet.setCell("B2", 15);
    cout << spreadsheet.getValue("=A1+B2") << endl;      // 25
    spreadsheet.resetCell("A1");
    cout << spreadsheet.getValue("=A1+B2") << endl;      // 15
}

int main() {
    test();
    return 0;
} 