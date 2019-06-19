#include <iostream>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        int w_len = 0;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ' || i == line.size() - 1) {
                if (line[i] != ' ') cout << line[i];
                for (int j = 1; j <= w_len; j++) {
                    cout << line[i - j];
                }
                if (line[i] == ' ') cout << ' ';
                w_len = 0;
            } else {
                w_len++;
            }
        }
        cout << endl;
    }
}