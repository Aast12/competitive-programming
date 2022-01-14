#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> graph;

int main() {
    int n;
    cin >> n;

    graph adj_mat = graph(n, vi(n));
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj_mat[i][j];
            if (i <= j) count += adj_mat[i][j];
        }
    }

    cout << count << endl;
}