#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct DSU {
    vector<int> size;
    vector<int> parent;
    vector<bool> active_parents;

    DSU(int s) {
        size = vector<int>(s, 1);
        parent = vector<int>(s);
        active_parents = vector<bool>(s, 1);
        for (int i = 0; i < s; i++) parent[i] = i;
    }

    void insert(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

    void join(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            active_parents[b] = 0;
        }
    }

    vector<int> calc_sizes() {
        vector<int> size_list;
        for (int i = 0; i < active_parents.size(); i++) {
            if (active_parents[i]) {
                size_list.push_back(size[i]);
            }
        }

        return size_list;
    }
};

vector<bool> unique_sizes;
vector<int> accum_values;

bool hasSum(vector<int> &set, int n, int sum) {
    bool subset[n + 1][sum + 1];

    for (int i = 0; i <= n; i++) subset[i][0] = true;
    for (int i = 1; i <= sum; i++) subset[0][i] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1]) {
                subset[i][j] = subset[i - 1][j];
            }
            if (j >= set[i - 1])
                subset[i][j] =
                    subset[i - 1][j] || subset[i - 1][j - set[i - 1]];

            unique_sizes[j] = subset[i][j];
        }
    }

    return subset[n][sum];
}

int main() {
    int n, p, a, b;
    cin >> n >> p;
    DSU sets = DSU(n);

    for (int i = 0; i < p; i++) {
        cin >> a >> b;
        sets.join(a - 1, b - 1);
    }

    vector<int> size_list = sets.calc_sizes();
    accum_values = vector<int>(size_list.size());
    unique_sizes = vector<bool>(n, 0);

    sort(size_list.begin(), size_list.end());

    for (int i = 0; i < size_list.size(); i++) {
        int prev = i == 0 ? 0 : accum_values[i - 1];
        accum_values[i] = size_list[i] + prev;
        unique_sizes[size_list[i]] = 1;
        unique_sizes[accum_values[i]] = 1;
    }
    int count = 0;
    for (int i = n; i > 0; i--) {
        if (unique_sizes[i] || hasSum(size_list, n, i)) count++;
    }

    cout << count << endl;
}