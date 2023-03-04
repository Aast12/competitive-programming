#include <iostream>
#include <vector>
#define MAXID 10000

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

typedef vector<bool> vb;
typedef vector<vb> vbb;

int main() {
    int T, n, pid, maxid;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        vbb solved(3, vb(MAXID + 1, 0));
        vii solved_ids(3);
        maxid = 0;
        for (int i = 0; i < 3; i++) {
            cin >> n;

            for (int j = 0; j < n; j++) {
                cin >> pid;
                solved[i][pid] = 1;
                maxid = max(maxid, pid);
            }
        }

        for (int id = 0; id <= maxid; id++) {
            int total = solved[0][id] + solved[1][id] + solved[2][id];
            if (total == 1) {
                for (int i = 0; i < 3; i++) {
                    if (solved[i][id]) {
                        solved_ids[i].push_back(id);
                        break;
                    }
                }
            }
        }

        int max_size = max(solved_ids[0].size(),
                           max(solved_ids[1].size(), solved_ids[2].size()));

        cout << "Case #" << t << ":" << endl;
        for (int i = 0; i < 3; i++) {
            if (solved_ids[i].size() == max_size) {
                if (max_size == 0) {
                    cout << i + 1 << " " << 0 << endl;
                } else {
                    cout << i + 1 << " " << max_size << " ";
                    for (int j = 0; j < max_size; j++) {
                        cout << solved_ids[i][j];
                        if (j != max_size - 1) cout << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
}