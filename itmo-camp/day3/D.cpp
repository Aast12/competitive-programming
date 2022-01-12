#include <iostream>
#include <vector>
#define INF 1000000

using namespace std;

typedef vector<int> vi;

struct Node {
    int cost = -INF;
    bool includes = 0;
    pair<int, int> prev;
};

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> weight(n), cost(n);
    for (int i = 0; i < n; i++) cin >> weight[i];
    for (int i = 0; i < n; i++) cin >> cost[i];

    vector<vector<Node> > f_cost(n + 1, vector<Node>(W + 1));
    f_cost[0][0].cost = 0;
    int max_cost = 0, k;
    pair<int, int> max_trace;

    for (int i = 1; i < n + 1; i++) {
        for (int w = 0; w <= W; w++) {
            k = weight[i - 1];
            f_cost[i][w].cost = f_cost[i - 1][w].cost;
            f_cost[i][w].prev = make_pair(i - 1, w);
            if (k <= w) {
                if (f_cost[i - 1][w - k].cost + cost[i - 1] >
                    f_cost[i][w].cost) {
                    f_cost[i][w].cost = f_cost[i - 1][w - k].cost + cost[i - 1];
                    f_cost[i][w].includes = 1;
                    f_cost[i][w].prev = make_pair(i - 1, w - k);
                }
            }

            if (f_cost[i][w].cost > max_cost) {
                max_cost = f_cost[i][w].cost;
                max_trace = make_pair(i, w);
            }
        }
    }

    vector<int> trace;
    while (true) {
        int i = max_trace.first, j = max_trace.second;
        if (i == 0 || j <= 0) break;
        if (f_cost[i][j].includes) trace.push_back(i);

        max_trace = f_cost[i][j].prev;
    }

    cout << trace.size() << endl;
    for (int i = trace.size() - 1; i >= 0; i--) {
        cout << trace[i] << " ";
    }
}