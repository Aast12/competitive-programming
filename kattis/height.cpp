#include <iostream>
#include <list>

using namespace std;

int main() {
    int p, k, h;
    cin >> p;

    while (p--) {
        cin >> k;
        int height[20];
        list<int> height_ordered;
        for (int i = 0; i < 20; i++) {
            cin >> height[i];
        }

        height_ordered.push_back(height[0]);
        int moves = 0, curr, steps, j;
        for (int i = 1; i < 20; i++) {
            curr = height[i], j = 0;
            bool inserted = 0;
            for (auto it = height_ordered.begin(); it != height_ordered.end(); it++, j++) {
                if (*it > curr) {
                    steps = height_ordered.size() - j;
                    height_ordered.insert(it, curr);
                    inserted = 1;
                    moves += steps;
                    break;
                }
            }

            if (!inserted)
                height_ordered.push_back(curr);
            
        }

        cout << k << " " << moves << endl;
    }
}
