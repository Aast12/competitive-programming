#include <iostream>
#include <set>

using namespace std;

int main() {
    int color;
    set<int> colors;

    for (int i = 0; i < 4; i++) {
        cin >> color;
        colors.insert(color);
    }

    cout << 4 - colors.size() << endl;
}