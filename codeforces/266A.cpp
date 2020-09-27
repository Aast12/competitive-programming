#include <iostream>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    char current = s[0];
    int reps = 0, total = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == current) {
            reps++;
        } else {
            total += reps;
            current = s[i];
            reps = 0;
        }
    }

    total += reps;

    cout << total << endl;
}