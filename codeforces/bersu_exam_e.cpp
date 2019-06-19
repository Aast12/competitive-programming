#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool exists(const vector<int>& vec, int val) {
    return find(vec.begin(), vec.end(), val) != vec.end();
}

int main() {
    int n, m;
    cin >> n >> m;
    int times[n];
    for (int i = 0; i < n; i++) {
        cin >> times[i];
        if (i != 0) times[i] += times[i - 1];
    }

    for (int i = 0; i < n; i++) {
        if (times[i] <= m) {
            cout << 0 << " ";
        } else {
            int value = times[i], counter = 0;;
            vector<int> used_indexes;
            while (true) {
                int max = 0, max_i = 0;
                for (int j = i - 1; j >= 0; j--) {
                    int i_val = times[j] - ((j == 0) ? 0 : times[j - 1]);
                    if (i_val > max && !exists(used_indexes, j)) {
                        max_i = j;
                        max = i_val;
                    }
                }
                used_indexes.push_back(max_i);
                value -= max;
                counter++;
                if (value <= m) {
                    cout << counter << " " ;
                    break;
                }
            }
        }
    }
}