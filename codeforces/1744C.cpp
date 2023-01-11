#include <iostream>
#include <vector>

using namespace std;

inline int next_pos(int idx, int n) {
    idx--;
    if (idx < 0) return n + idx;
    return idx;
}

int main() {
    int t, n;
    char match;
    string pattern;
    cin >> t;

    while (t--) {
        cin >> n >> match >> pattern;

        vector<int> time(n);
        int initial_pos = pattern.find_first_of('g');
        int pointer = initial_pos;
        int min_time = 0;

        time[pointer] = 0;
        pointer = next_pos(pointer, n);

        int distance = 1;
        while (pointer != initial_pos) {
            if (pattern[pointer] == 'g') 
                distance = 0;

            time[pointer] = distance;
            if (pattern[pointer] == match)
                min_time = max(min_time, distance);

            pointer = next_pos(pointer, n);
            distance++;
        }

        // for (int i = 0; i < n; i++) {
        //     cout << time[i] << " ";
        // }
        // cout << endl;

        cout << min_time << endl;
    }
}