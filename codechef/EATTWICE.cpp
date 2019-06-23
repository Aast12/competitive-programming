#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
    int T, N, M, day, taste, sum, key_used, max_n = 0;    
    cin >> T;

    while (T--) {
        max_n = 0;
        key_used = 0;
        sum = 0;

        cin >> N >> M;
        map<int,int> dishes; 
        for (int i = 0; i < N; i++) {
            cin >> day >> taste;
            if (dishes.find(day) != dishes.end()) {
                dishes[day] = max(taste, dishes[day]);
            } else {
                dishes[day] = taste;
            }
        }

        for (auto &dish : dishes) {
            if (dish.second > max_n) {
                max_n = dish.second;
                key_used = dish.first;
            }
        }

        sum = max_n;
        max_n = 0;

        for (auto &dish : dishes) {
            if (dish.second > max_n && dish.first != key_used) {
                max_n = dish.second;
            }
        }

        cout << sum + max_n << endl;
    }
    return 0;
}
