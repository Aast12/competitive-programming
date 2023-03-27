#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define MAXT ull(1000000005)
#define MOD ull(1000000007)
using namespace std;

// typedef unsigned long long ull;
typedef unsigned long long ull;

struct Edge {
    int from, to;
    ull lo, up;
    Edge() {}
    Edge(int from, int to, ull lo, ull up)
        : from(from), to(to), lo(lo), up(up) {}
};

bool operator<(const Edge &a, const Edge &b) {
    // if (a.lo == b.lo)
    //     return a.up < b.up;

    return a.lo < b.lo;
}

struct State {
    Edge edge;
    int step;
    State() {}
    State(Edge e, int s) : edge(e), step(s) {}
};

typedef vector<ull> vull;
typedef vector<vull> mat;
typedef vector<mat> cube;

typedef vector<bool> vb;
typedef vector<vb> matb;
typedef vector<matb> cubeb;

typedef vector<Edge> ve;
typedef vector<ve> graph_t;

int main() {
    int k, l, n;
    cin >> k >> l;

    ull t;
    graph_t graph(k, ve(k));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cin >> t;
            graph[i][j] = Edge(i, j, l >= t ? 1 : t - l, min(MAXT, t + l));
        }
        // sort(graph[i].begin(), graph[i].end());
    }

    cin >> n;
    vull password(n);
    for (int i = 0; i < n - 1; i++) cin >> password[i];

    cube counts(n, mat(k, vull(k, 0)));
    cubeb visit(n, matb(k, vb(k, 0)));

    queue<State> bfsq;
    ull q = password[0];
    for (int i = 0; i < k; i++) {
        // auto it = lower_bound(graph[i].begin(), graph[i].end(), Edge(0, 0, q,
        // q));
        auto it = lower_bound(graph[i].begin(), graph[i].end(), q,
                              [](const Edge &e, const ull v) {
                                  if (e.up < v) return true;
                                  return false;
                              });

        // auto it = graph[i].begin();
        for (; it != graph[i].end(); it++) {
            if (it->lo > q) break;
            // if (!(it->lo <= q && it->up >= q))
            //     continue;
            if (it->up < q) continue;

            counts[1][it->from][it->to] = 1;
            bfsq.push(State(*it, 1));
        }
    }

    ull total = 0;
    while (!bfsq.empty()) {
        auto curr = bfsq.front();
        bfsq.pop();
        // cout << "Check " << curr.step << " " << curr.edge.from << ", " <<
        // curr.edge.to << " = " <<
        // counts[curr.step][curr.edge.from][curr.edge.to] << endl;
        if (curr.step == n - 1) {
            total += counts[curr.step][curr.edge.from][curr.edge.to] % MOD;
            total %= MOD;
            continue;
        }

        int from = curr.edge.from;
        int to = curr.edge.to;
        q = password[curr.step];

        // auto it = lower_bound(graph[to].begin(), graph[to].end(), Edge(0, 0,
        // q, q)); auto it = lower_bound(graph[i].begin(), graph[i].end(),
        // Edge(0, 0, q, q));
        auto it = lower_bound(graph[to].begin(), graph[to].end(), q,
                              [](const Edge &e, const ull v) {
                                  if (e.up < v) return true;
                                  return false;
                              });
        // auto it = graph[to].begin();
        for (; it != graph[to].end(); it++) {
            if (it->lo > q) break;
            if (it->up < q) continue;
            // if (!(it->lo <= q && it->up >= q))
            //     continue;
            // if (!(it->lo <= q && it->up >= q))
            //     continue;

            // cout << "\t Next  " << curr.step + 1 << " " << it->from << ", "
            // << it->to << " = ";

            counts[curr.step + 1][it->from][it->to] +=
                counts[curr.step][from][to] % MOD;
            counts[curr.step + 1][it->from][it->to] %= MOD;
            // cout << counts[curr.step + 1][it->from][it->to] << endl;
            // if (curr.step + 1 == n - 2)
            //     total += counts[curr.step][from][to];
            // counts[curr.step + 1][it->from][it->to] %= MOD;

            if (!visit[curr.step + 1][it->from][it->to]) {
                visit[curr.step + 1][it->from][it->to] = 1;
                bfsq.push(State(*it, curr.step + 1));
            }

            // break;
        }
    }
    // total = 0;
    // for (int i = 0; i < k; i++)
    // {
    //     for (int j = 0; j < k; j++)
    //     {
    //         total += counts[n - 1][i][j];
    //     }
    // }

    cout << (total % MOD) << endl;
}