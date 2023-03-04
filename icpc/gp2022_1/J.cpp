#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>
#define INF 1000000
#define UNMATCH -1

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> Graph;

bool try_kuhn(int v, Graph &graph, vb &used, vi &matches) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to : graph[v]) {
        if (matches[to] == -1 || try_kuhn(matches[to], graph, used, matches)) {
            matches[to] = v;
            return true;
        }
    }
    return false;
}


int main() {
    int n, m, size, mi;

    cin >> n >> m;
    Graph  graph(n);
    for (int i = 0; i < n; i++) {
        cin >> size;
        for (int j = 0; j < size; j++) {
            cin >> mi;
            mi--;
            graph[i].push_back(mi);
        }
    }

    vi matches(m, UNMATCH);
    
    vector<bool> used(n, false);
    vector<bool> used_aux(n, false);
    for (int v = 0; v < n; v++) {
        for (int to : graph[v]) {
            if (matches[to] == UNMATCH) {
                matches[to] = v;
                used_aux[v] = true;
                break;
            }
        }
    }
    
    for (int v = 0; v < n; ++v) {
        if (used_aux[v])
            continue;
        used.assign(n, false);
        try_kuhn(v, graph, used, matches);
    }


    int match_count = 0;
    for (auto match : matches) {
        if (match != UNMATCH) match_count++;
    }
    

    cout << m - match_count << endl;
}