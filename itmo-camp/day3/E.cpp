#include <iostream>
#include <map>
#include <stack>
#include <vector>
#define MAX 10000005

using namespace std;

map<int, pair<int, int> > memo;
vector<int> trace;

int min_ops(int n);

pair<int, int> check_div(int n, int d, pair<int, int> current) {
    int candidate;
    candidate = min_ops(n / d) + 1;
    if (candidate < current.first) {
        current = make_pair(candidate, n / d);
    }

    return current;
}

int min_ops(int n) {
    if (n <= 1) return n;
    if (memo[n].first) return memo[n].first;

    pair<int, int> best = make_pair(n, n - 1);
    if (n % 3 == 0) best = check_div(n, 3, best);
    if (n % 2 == 0) best = check_div(n, 2, best);

    if (min_ops(n - 1) + 1 < best.first) {
        best = make_pair(min_ops(n - 1) + 1, n - 1);
    }

    trace.push_back(best.second);

    memo[n] = best;
    return memo[n].first;
    // return best.first;
}

int main() {
    int n;
    cin >> n;

    // memo = new pair<int, int>[MAX];

    memo[0] = make_pair(0, 0);
    memo[1] = make_pair(1, 0);
    int op_count = min_ops(n), last_trace = n;
   stack<int> trace;
    while (last_trace != 0) {
        trace.push(last_trace);
        last_trace = memo[last_trace].second;
    }



    // while (!trace.empty()) {
    //     cout << trace.top() << " ";
    //     trace.pop();
    // }

    // for (int i = 0; i < trace.size(); i++) {
    //     cout << trace[i] << " ";
    // }

    cout << endl;
}
