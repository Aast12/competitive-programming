#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    string word;
    ull word_set[n], initials = 0;
    bool pos = 0;

    for (int i = 0; i < n; i++) {   
        cin >> word;
        word_set[i] = 0;

        if (pos) continue;
        
        initials |= (1 << (word[0] - 'A'));

        for (auto& ch : word) {
            word_set[i] |= (1 << (ch - 'A'));
        }

        if ((initials & word_set[i]) == word_set[i]) {
            cout << 'Y' << endl;
            pos = 1;
        }
    }

    if (pos) return 0;

    
    for (int i = 0; i < n; i++) {
        if ((initials & word_set[i]) == word_set[i]) {
            cout << 'Y' << endl;
            return 0;
        }
    }

    cout << 'N' << endl;


}