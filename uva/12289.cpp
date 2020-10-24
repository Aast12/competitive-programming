#include <iostream>

using namespace std;

int main() {
    int n, err;
    string word, one = "one";
    cin >> n;

    while (n--) {
        cin >> word;
        if (word.size() == 5) cout << 3 << endl;
        else {
            err = 0;
            if (word[0] != 'o') err++;
            if (word[1] != 'n') err++;
            if (word[2] != 'e') err++;

            if (err <= 1) cout << 1 << endl;
            else cout << 2 << endl;
        }
    }
}