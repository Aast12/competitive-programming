#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;

    while (cin >> n) {
        if (n == 0) break;

        vector<string> names(n);
        for (int i = 0; i < n; i++) {
            cin >> names[i];
        }

        stable_sort(names.begin(), names.end(),
                    [](const string& fst, const string& snd) -> bool {
                        return fst.substr(0, 2) < snd.substr(0, 2);
                    });

        for (auto& name : names) {
            cout << name << endl;
        }
    
        cout << endl;
    }
}