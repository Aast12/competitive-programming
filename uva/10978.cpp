#include <iostream>
#include <vector>

using namespace std;

typedef pair<string, string> pss;

int main() {
    int n;
    string sym, word;

    while (cin >> n) {
        if (n == 0) break;

        vector<pss> symbols(n);
        vector<string> cards(n, "");
        for (int i = 0; i < n; i++) {
            cin >> sym >> word;
            symbols[i] = make_pair(sym, word);
        }

        int curr_idx = 0;
        for (auto symbol : symbols) {
            word = symbol.second;
            sym = symbol.first;
            for (int steps = 0;; curr_idx = (curr_idx + 1) % n) {
                if (cards[curr_idx] == "") {
                    steps++;
                    if (steps == word.size()) {
                        cards[curr_idx] = sym;
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < cards.size(); i++) {
            cout << cards[i] << (i == cards.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
}