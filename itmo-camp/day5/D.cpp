#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> Graph;

struct CostNode {
    int from, to, cost, dist;

    CostNode() {}

    CostNode(int f, int t, int c, int d) : from(f), to(t), cost(c), dist(d) {}
};

struct CompareNode {
    bool operator()(CostNode const& n1, CostNode const& n2) {
        if (n1.dist == n2.dist) {
            return n1.cost < n2.cost;
        }
        return n1.dist < n2.dist;
    }
};

int main() {
    int n, m, u, v;
    cin >> n >> m;

    vi domain(n);
    for (int i = 0; i < n; i++) {
        cin >> domain[i];
    }

    Graph graph(n);

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    priority_queue<CostNode, vector<CostNode>, CompareNode> pq;
    pq.push(CostNode())
}
