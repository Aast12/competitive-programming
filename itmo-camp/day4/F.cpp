#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> graph;

graph adjacencies;

vector<int> color;
int n, e;

bool has_cycle(int u) {
    cout << "- " << u << endl;
    color[u] = 1;

    for (int& v : adjacencies[u]) {
        cout << "check - " << u << " , " << v << endl;
        if (color[v] == 1) {
            cout << "bad " << v << endl;
            return true;
        }

        if (color[v] == 0 && has_cycle(v)) {
            return true;
        }
    }

    color[u] = 2;

    cout << "pass " << u << endl;

    return false;
}

int main() {
    int u, v;
    cin >> n;

    color = vector<int>(n, 0);

    adjacencies = graph(n);

    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        adjacencies[u].push_back(v);
    }
    
    bool pos = true;
    for (int v = 0; v < n && pos; v++) {
        if (color[v] == 0) {
            pos = !has_cycle(v);
        }
    }

    cout << (pos ? "YES" : "NO") << endl;
}