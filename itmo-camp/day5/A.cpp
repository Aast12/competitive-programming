#include <iostream>
#include <queue>
#include <vector>

#define INF 10000

using namespace std;

struct Edge {
    int from, to;
    Edge(int f, int t) : from(f), to(t) {}
};

typedef vector<int> vi;
typedef vector<vi> Graph;

int main() {
    int n, x;
    bool adj;

    cin >> n >> x;
    x--;

    Graph graph(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj;
            if (adj) {
                graph[i].push_back(j);
            }
        }
    }

    queue<int> bfs_q;
    vi dist(n, -1);
    dist[x] = 0;
    bfs_q.push(x);
    while (!bfs_q.empty()) {
        int curr = bfs_q.front();
        bfs_q.pop();

        for (int v : graph[curr]) {
            if (dist[v] == -1) {
                dist[v] = dist[curr] + 1;
                bfs_q.push(v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}
