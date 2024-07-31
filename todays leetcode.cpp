#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    ifstream file("file.txt");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    vector<vector<string>> data;
    string line;

    // Read file content into a 2D vector
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> row;
        string cell;
        while (ss >> cell) {
            row.push_back(cell);
        }
        data.push_back(row);
    }

    file.close();

    if (data.empty()) {
        cerr << "File is empty or cannot be read" << endl;
        return 1;
    }

    // Transpose the 2D vector
    size_t numRows = data.size();
    size_t numCols = data[0].size();
    vector<vector<string>> transposed(numCols, vector<string>(numRows));

    for (size_t i = 0; i < numRows; ++i) {
        for (size_t j = 0; j < numCols; ++j) {
            transposed[j][i] = data[i][j];
        }
    }

    // Output the transposed data
    for (const auto& row : transposed) {
        for (const auto& cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }

    return 0;
}
