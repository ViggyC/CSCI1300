#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream file("numbers.txt"); // Replace with your filename
    string line;
    char delimiter = ','; // Define the delimiter
    vector<vector<int> > columns; // To store numbers column-wise
    int maxColumns = 0; // Track the maximum number of columns

    if (file.is_open()) {
        while (getline(file, line)) {
            vector<int> currentRow;
            string currentNumber;

            // Manual splitting of the line by the delimiter
            for (char ch : line) {
                // cout << "current: " << currentNumber << endl;
                // cout << "ch: " << ch << endl;

                if (ch == delimiter) {
                    if (!currentNumber.empty()) {
                        currentRow.push_back(stoi(currentNumber)); // Convert to integer
                        currentNumber.clear(); // Clear for the next number
                    }
                } else {
                    currentNumber += ch; // Add character to current number
                }
            }

            // Check for any number left after the loop
            if (!currentNumber.empty()) {
                currentRow.push_back(stoi(currentNumber));
            }

            // Update columns vector to accommodate current row
            if (currentRow.size() > maxColumns) {
                maxColumns = currentRow.size();
                columns.resize(maxColumns); // Resize columns to hold more data
            }

            // printing for each line
            // Output the current row
            cout << "Current row: ";
            for (int num : currentRow) {
                cout << num << " ";
            }
            cout << endl;

            // Add the current row to columns
            //columns : {{}, {} ,{}}
            for (size_t i = 0; i < currentRow.size(); i++) {
                columns[i].push_back(currentRow[i]);
                //             0     1     2
                //columns : {{5}, {-3} ,{4}}
                //columns : {{5, 0}, {-3,1} ,{4,1}}
                //columns : {{5, 0, 5}, {-3,1,8} ,{4,1 8}}
            }
        }
        file.close();
    } else {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    // Calculate and print the average for each column
    for (size_t i = 0; i < columns.size(); i++) {
        if (!columns[i].empty()) {
            int sum = 0;
            for (int val : columns[i]) {
                sum += val;
            }
            double average = static_cast<double>(sum) / columns[i].size();
            cout << "Average of column " << i + 1 << ": " << average << endl;
        } else {
            cout << "Column " << i + 1 << " is empty." << endl;
        }
    }

    return 0;
}
