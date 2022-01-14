#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> graph;

graph adjacencies;

vector<int> color;
int current_color = 1;
int n, e;

void dfs(int u) {
    if (color[u]) return;
    color[u] = current_color;

    for (int &v : adjacencies[u]) {
        if (!color[v]) {
            dfs(v);
        }
    }
}

int main() {
    int u, v;
    cin >> n >> e;

    color = vector<int>(n, 0);
    adjacencies = graph(n);

    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        u--;
        v--;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    for (int v = 0; v < n; v++) {
        if (!color[v]) {
            dfs(v);
            current_color++;
        }
    }

    for (int v = 0; v < n; v++)
        if (!color[v]) color[v] = current_color++;

    cout << current_color - 1 << endl;
    for (int v = 0; v < n; v++) cout << color[v] << " ";

    cout << endl;
}