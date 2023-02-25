#include <iostream>

using namespace std;

typedef pair<int, int> block;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        string s;
        cin >> n >> s;

        int half_start = n / 2 + n % 2, block_count = 0,
            curr_start = half_start;
        bool noteq = s[n - half_start - 1] != s[half_start], curr_noteq;
        for (int i = half_start + 1; i < n; i++) {
            curr_noteq = s[i] != s[n - i - 1];
            if (curr_noteq != noteq) {
                if (noteq) block_count++;

                curr_start = i;
                noteq = curr_noteq;

                if (block_count > 1) break;
            }
        }

        if (noteq) block_count++;

        cout << (block_count > 1 ? "No" : "Yes") << endl;
    }
}