#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, v1, v2;
    cin >> n >> a;
    vector<vector<int>> graph(n);
    vector<int> counter(n);
    int dropped = 0;
    for (int i = 0; i < n; i++) {
        counter[i] = 0;
        graph[i] = vector<int>();
    };
    for (int i = 0; i < a; i++) {
        cin >> v1 >> v2;
        v1--;
        v2--;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
        counter[v1]++;
        counter[v2]++;
    }
    bool flag = 1;
    while (flag) {
        flag = 0;
        vector<int> mod(n);
        for (int i = 0; i < n; i++) mod[i] = 0;
        for (int i = 0; i < n; i++) {
            if (counter[i] == 1) {
                flag = 1;
                counter[i] = 0;
                for (int j = 0; j < graph[i].size(); j++) {
                    if (counter[graph[i][j]] != 0) {
                        mod[graph[i][j]]++;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) counter[i] -= mod[i];
        if (flag) {
            dropped++;
        }
    }
    cout << dropped << endl;
}