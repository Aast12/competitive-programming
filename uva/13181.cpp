#include <iostream>
#include <vector>

using namespace std;

int main() {
    string beds;
    while (cin >> beds) {
        int n = beds.size();
        vector<int> max_dist(n, 500002);
        int count = 0;
        bool found_first = false;

        for (int i = 0; i < n; i++) {
            if (beds[i] == 'X') {
                found_first = true;
                count = 0;
                int dist = 0;

                max_dist[i] = -1;
                for (int j = i - 1; j >= 0; j--) {
                    if (max_dist[j] > dist) {
                        max_dist[j] = dist++;
                    } else {
                        break;
                    }
                }
            } else if (found_first) {
                max_dist[i] = count++;
            }
        }   

        int max_d = -1;
        for (int i = 0; i < n; i++) {
            max_d = max(max_dist[i], max_d);
        }
        cout << max_d << endl;
    }
}