#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> graph;

graph adj_mat;

vector<int> color;
int n;

int main() {
    cin >> n;

    color = vector<int>(n, 0);

    adj_mat = graph(n, vi(n));

    bool pos = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj_mat[i][j];
            if (j < i && adj_mat[i][j] != adj_mat[j][i]) pos = false;
            if (j == i && adj_mat[i][j]) pos = false;
        }
    }

    cout << (pos ? "YES" : "NO") << endl;
}
