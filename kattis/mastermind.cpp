#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, alph_size = 'Z' - 'A' + 1;
    string code, guess;
    cin >> n >> code >> guess;

    vector<int> code_freqs(alph_size, 0), guess_freqs(alph_size, 0);
    int r = 0, s = 0;

    for (int i = 0; i < n; i++) {
        if (code[i] == guess[i]) {
            r++;
        } else {
            code_freqs[code[i] - 'A']++;
            guess_freqs[guess[i] - 'A']++;
        }
    }

    for (int i = 0; i < alph_size; i++) {
        s += min(code_freqs[i], guess_freqs[i]);
    }

    cout << r << " " << s << endl;
}