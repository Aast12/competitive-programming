#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1000000
#define UNMATCH -1

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

struct Node {
    int deg = 0;
    vi adjs;

    Node() {}

    bool operator<(const Node &a) const { return deg < a.deg; }
};

typedef vector<Node> Graph;

int main() {
    int n, m, size, mi;

    cin >> n >> m;
    Graph graph(n);
    Graph graph_r(m);
    vb matched(m, 0);
    for (int i = 0; i < n; i++) {
        cin >> size;

        graph[i].deg = size;
        for (int j = 0; j < size; j++) {
            cin >> mi;
            mi--;
            graph_r[mi].adjs.push_back(i);
            graph_r[mi].deg++;
            graph[i].adjs.push_back(mi);
        }
    }

    sort(graph.begin(), graph.end());
    int matches = 0;

    for (auto node : graph) {
        int min_adj = -1, min_adj_deg = INF;
        for (auto adj : node.adjs) {
            if (!matched[adj]) {
                if (graph_r[adj].deg < min_adj_deg) {
                    min_adj = adj;
                    min_adj_deg = graph_r[adj].deg;
                }
                graph_r[adj].deg--;
            }
        }

        if (min_adj >= 0) {
            matched[min_adj] = 1;
            matches++;
        }
    }

    cout << m - matches << endl;
}