#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

void process_lines(vector<string>& lines, int largest_len) {
    for (auto& line : lines) reverse(line.begin(), line.end());
    sort(lines.begin(), lines.end());
    for (auto& line : lines) reverse(line.begin(), line.end());

    for (auto& line : lines) cout << setw(largest_len) << line << endl;
}

int main() {
    string line;
    vector<string> lines;
    int largest_len = 0;

    while (getline(cin, line)) {
        if (line.size() > 0) {
            lines.push_back(line);
            largest_len = max(largest_len, (int)line.size());
        } else {
            process_lines(lines, largest_len);
            cout << endl;
            largest_len = 0;
            lines.clear();
        }
    }

    process_lines(lines, largest_len);
}