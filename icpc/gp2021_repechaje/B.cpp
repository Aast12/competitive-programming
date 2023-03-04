#include <iostream>

using namespace std;

pair<int, int> calc(string &str, int start, int segment) {
    int str_index = start;
    int row_index = 0;
    int value = 0;
    while (row_index < segment) {
        if (str[str_index] == ')') {
            row_index++;
        } else if (str[str_index] == '*') {
            value += 1 << (segment - row_index - 1);
        }
        str_index++;
    }

    return {str_index, value};
}

int main() {
    int T;
    cin >> T;

    int segments[] = {2, 4, 3, 4, 3, 4};

    for (int t = 1; t <= T; t++) {
        string bin;
        cin >> bin;
        int start_idx = 0;
        string hour_str;

        for (int i = 0; i < 6; i++) {
            auto value = calc(bin, start_idx, segments[i]);
            start_idx = value.first;
            hour_str += char(value.second + '0');
            if (i % 2 == 1 && i != 5) hour_str += ':';
        }

        cout << "Case " << t << ": " << hour_str << endl;
    }
}