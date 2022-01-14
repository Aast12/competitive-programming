#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> graph;

graph adj_mat;

vector<int> color;
int n;

bool has_cycle(int u) {
    cout << "- " << u << endl;
    color[u] = 1;

    for (int v = 0; v < n; v++) {
        if (adj_mat[u][v]) {
            cout << "check - " << u << " , " << v << endl;
            if (color[v] == 1) {
                cout << "bad " << v << endl;
                return true;
            }

            if (color[v] == 0 && has_cycle(v)) {
                return true;
            }
        }
    }

    color[u] = 2;

    cout << "pass " << u << endl;

    return false;
}

int main() {
    cin >> n;

    adj_mat = graph(n, vi(n));

    vector<bool> sink(n, 1);
    int sink_count = n;
    vector<bool> source(n, 1);
    int source_count = n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj_mat[i][j];
            if (adj_mat[i][j]) {
                if (source[j]) {
                    source[j] = 0;
                    source_count--;
                }
                if (sink[i]) {
                    sink[i] = 0;
                    sink_count--;
                }
            }
        }
    }

    cout << source_count << " ";
    for (int i = 0; i < n; i++)
        if (source[i]) cout << i + 1 << " ";
    cout << endl;

    cout << sink_count << " ";
    for (int i = 0; i < n; i++)
        if (sink[i]) cout << i + 1 << " ";
    cout << endl;
}
