#include <iostream>
#include <map>

using namespace std;

typedef unsigned long long ull;

map<ull, ull> memo;

ull solve(ull n) {
    if (n < 2) return n;
    if (memo.find(n) != memo.end()) return memo[n];

    if (n % 2 == 0) {
        return memo[n] = solve(n / 2);
    } else {
        ull even = (n - 1) / 2, odd = even + 1;
        return memo[n] = solve(even) + solve(odd);
    }
}

int main() {
    ull n;
    cin >> n;
    memo = map<ull, ull>();
    cout << solve(n);
}