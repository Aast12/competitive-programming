#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> graph;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, k, a, b;
    cin >> n >> k;

    graph fields(n);
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        a--;
        b--;
        fields[a].push_back(b);
        fields[b].push_back(a);
    }

    vector<bool> visited(n, 0), bob(n, 0);
    queue<int> bfsq;
    bfsq.push(n - 2);
    while (!bfsq.empty()) {
        int top = bfsq.front();
        bob[top] = true;
        bfsq.pop();

        for (auto& adj : fields[top]) {
            if (adj != n - 1 && !visited[adj]) {
                visited[adj] = 1;
                bfsq.push(adj);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << (bob[i] ? 'B' : 'A'); 
    }

    cout << endl;
}