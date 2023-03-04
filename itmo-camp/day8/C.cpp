#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vector<vi> tree;
vi weight;
vi f, g;  // pick / no pick vertex funcs

void dfs(int node) {
    f[node] = weight[node];
    g[node] = 0;
    for (auto &child : tree[node]) {
        dfs(child);
        f[node] += g[child];
        g[node] += max(f[child], g[child]);
    }
}

int maxIndependentSet(int root) {
    dfs(root);
    return max(f[root], g[root]);
};

int main() {
    int n, pi, wi;
    cin >> n;

    tree = vector<vi>(n);
    weight = vi(n);
    f = vi(n);
    g = vi(n);

    int root = 0;
    for (int i = 0; i < n; i++) {
        cin >> pi >> wi;
        weight[i] = wi;
        if (pi != 0)
            tree[pi - 1].push_back(i);
        else
            root = i;
        
    }

    cout << maxIndependentSet(root) << endl;
}