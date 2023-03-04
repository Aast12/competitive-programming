#include <iostream>
#include <vector>
// #include <iostream>
#define INF 
using namespace std;
typedef unsigned long long ull;
ull min_time;


ull search(vector<int>& a, vector<ull>& hot, vector<ull>& cold, ull c,
           ull cpu0, ull cpu1, ull time) {
    if (c >= a.size()) {
        if (time < min_time) {
            min_time = time;
        }

        return min_time;
    }
    int next=a[c];

    if (time >= min_time) return min_time;
    ull left = search(a, hot, cold, next + 1, next, cpu1,
                      time + (cpu0 == next ? hot[next - 1] : cold[next - 1]));
    ull right = search(a, hot, cold, next + 1, cpu0, next,
                       time + (cpu1 == next ? hot[next - 1] : cold[next - 1]));
    return min(min_time, min(left, right));
}

int main() {
    int t, n, k;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        
        vector<int> a(n);
        vector<ull> hot(k), cold(k);
        int last_cpu[2] = {0, 0};

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < k; i++) cin >> cold[i];
        for (int i = 0; i < k; i++) cin >> hot[i];

        min_time = ULLONG_MAX;
        cout << search(a, hot, cold, 0, 0, 0, 0) << endl;
        // int time = 0;
        // for (int i = 0; i < n; i++) {
        //     if (last_cpu[0] == a[i] || last_cpu[1] == a[i]) {
        //         time += hot[a[i] - 1];
        //     } else {
        //         time += cold[a[i] - 1];
        //         for (int j = i + 1; j < n; j++) {
        //             if (a[j] == last_cpu[0]) {
        //                 last_cpu[1] = a[i];
        //                 break;
        //             }
        //             if (a[j] == last_cpu[1]) {
        //                 last_cpu[1] = a[i];
        //                 break;
        //             }
        //         }
        //     }
        // }
    }
}