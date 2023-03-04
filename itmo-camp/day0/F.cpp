#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int len = s.size();
    vector<int> c_counts(len, 0);

    int subseq_count = 0;
    c_counts[len - 1] = s[len - 1] == 'c';
    for (int i = len - 2; i >= 0; i--) {
        c_counts[i] = c_counts[i + 1];
        if (s[i] == 'c') c_counts[i]++;
    }

    for (int i = 0; i < len; i++) {
        if (s[i] == 'a') {
            for (int j = i + 1; j < len; j++) {
                if (s[j] == 'b') {
                    subseq_count += c_counts[j];
                }
            }
        }
    }

    cout << subseq_count << endl;
}