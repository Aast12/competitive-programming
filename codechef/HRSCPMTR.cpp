//PENDING

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Diagonal {
    vector<int> values;
    unordered_map<int, int> value_counts;

    void add(int v) {
        values.push_back(v);
        value_counts[v] = value_counts[v] + 1;
    }

    void replace(int i, int v) {
        value_counts[values[i]] = value_counts[values[i]] - 1;
        values[i] = v;
        value_counts[values[i]] = value_counts[v] + 1;
    }

    bool isValid() {
        return value_counts[values[0]] == values.size();
    }

    Diagonal() {}
};

int main() {
    int t, n, m, a, q, x, y, v;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        unordered_map<int, Diagonal> diagonals;
        unordered_set<int> valid_diagonals;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a;
                if (diagonals.find(j - i) == diagonals.end()) {
                    diagonals[j - i] = Diagonal();
                }
                diagonals[j - i].add(a);
            }
        }

        for (auto& pair : diagonals) {
            Diagonal& diag = pair.second;
            if (diag.isValid()) valid_diagonals.insert(pair.first);
        }

        cin >> q;
        for (int k = 0; k < q; k++) {
            cin >> x >> y >> v;
            int u = (y - 1) - (x - 1);
            if (u >= 0) {
                diagonals[u].replace(y - 1 - u, v);
            } else {
                diagonals[u].replace(x - 1 - u, v);
            }

            cout << "DIAGAS " << u << endl;
            for (auto it : diagonals[u].values) {
                cout << it << " ";
            }
            cout << endl;
            // for (auto diag : diagonals) {
            //     cout << "DIAGAS " << diag.first << endl;
            //     for (auto it : diag.second.values) {
            //         cout << it << " ";
            //     }
            //     cout << endl;
            // }

            if (!diagonals[u].isValid())
                valid_diagonals.erase(u);
            else
                valid_diagonals.insert(u);

            if (valid_diagonals.size() == n + m - 1)
                cout << "Yes";
            else
                cout << "No";
            cout << endl;
        }
    }
}
