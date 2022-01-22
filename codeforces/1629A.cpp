#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Ram {
    int gives, takes;
    Ram() {}
};

struct CompRam {
    inline bool operator()(Ram &r1, Ram &r2) {
        if (r1.takes == r2.takes) return r1.gives > r2.gives;

        return r1.takes < r2.takes;
    }
};

int main() {
    int t, n, curr_ram;
    cin >> t;
    while (t--) {
        cin >> n >> curr_ram;
        vector<Ram> ram_values(n);

        for (int i = 0; i < n; i++) cin >> ram_values[i].takes;
        for (int i = 0; i < n; i++) cin >> ram_values[i].gives;

        sort(ram_values.begin(), ram_values.end(), CompRam());

        for (auto rv : ram_values) {
            if (rv.takes > curr_ram) break;
            curr_ram += rv.gives;
        }

        cout << curr_ram << endl;
    }
}