#include <bitset>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct State {
    list<int> options;
    bitset<100> set;
    int length, total_gcd;

    State(bitset<100> set, int length, int total_gcd)
        : set(set), length(length), total_gcd(total_gcd) {}
};

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool search(State& curr, const vector<int>& A, int n) {
    if (curr.length != 1 && curr.total_gcd > curr.length) return false;
    if (curr.length == n) return true;

    bool pos = false;
    for (int i = 0; i < n; i++) {
        if (!curr.set[i]) {
            bitset<100> next_set(curr.set);
            next_set[i] = 1;
            State next(next_set, curr.length + 1, gcd(A[i], curr.total_gcd));
            if (search(next, A, n)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        bool pos = false;
        for (int i = 0; i < n; i++) {
            bitset<100> set;
            State next(set, 1, A[i]);
            if (search(next, A, n)) {
                pos = true;
                break;
            }
        }

        cout << (pos ? "Yes" : "No") << endl;
    }
}