#include <iostream>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int s_len = s.size(), t_len = t.size();
    int distance[s_len + 1][t_len + 1];

    distance[0][0] = 0;
    for (int i = 0; i < s_len + 1; i++) {
        for (int j = 0; j < t_len + 1; j++) {
            if (i == 0 && j == 0) continue;
            int best = s_len + t_len + 1;
            if (i > 0) best = min(best, distance[i - 1][j] + 1);
            if (j > 0) best = min(best, distance[i][j - 1] + 1);
            if (i > 0 && j > 0)
                best =
                    min(best, distance[i - 1][j - 1] + (s[i - 1] != t[j - 1]));

            distance[i][j] = best;
        }
    }

    cout << distance[s_len][t_len] << endl;
}