#include <iostream>
#include <string.h>
#define MAXN 3000
using namespace std;

int main() {
    int n;

    while (cin >> n) {
        int curr, prev, count = 0;
        bool appears[MAXN];

        memset(appears, 0, sizeof(appears));

        for (int i = 0; i < n; i++) {
            cin >> curr;
            if (i > 0) {
                int diff = curr - prev;
                if (diff < 0) diff *= -1;

                if (!appears[diff] && diff >= 1 && diff <= n - 1) {
                    appears[diff] = 1;
                    count++;
                }
            }
            prev = curr;
        }

        if (count == n - 1) {
            cout << "Jolly\n";
        } else {
            cout << "Not Jolly\n";
        }
    }
}