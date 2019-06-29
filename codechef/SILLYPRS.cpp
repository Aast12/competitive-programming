#include <iostream>
#include <queue>

using namespace std;
typedef unsigned long long ull;

int main() {
    int T;
    cin >> T;

    while (T--) {
        queue<ull> A_pairs, A_odds, B_pairs, B_odds;
        ull n, aux, sum = 0;
        cin >> n;

        for (ull i = 0; i < n; i++) {
            cin >> aux;
            if (aux % 2) A_odds.push(aux);
            else A_pairs.push(aux);
        }

        for (ull i = 0; i < n; i++) {
            cin >> aux;
            if (aux % 2) B_odds.push(aux);
            else B_pairs.push(aux);
        }

        while (!A_pairs.empty()) {
            if (!B_pairs.empty()) {
                sum += (A_pairs.front() + B_pairs.front()) / 2;
                A_pairs.pop();
                B_pairs.pop();
            } else {
                sum += (A_pairs.front() + B_odds.front()) / 2;
                A_pairs.pop();
                B_odds.pop();
            }
        }

        while (!A_odds.empty()) {
            if (!B_odds.empty()) {
                sum += (A_odds.front() + B_odds.front()) / 2;
                A_odds.pop();
                B_odds.pop();
            } else {
                sum += (A_odds.front() + B_pairs.front()) / 2;
                A_odds.pop();
                B_pairs.pop();
            }
        }

        cout << sum << endl;
    }
}