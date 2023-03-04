#include <iostream>
#include <map>
#include <vector>
#define MAX (10e6 + 5)
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> appears;
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int arrows = 0;
    for (int i = n - 1; i >= 0; i--) {
        int curr = height[i], downstep = curr - 1;

        appears[curr]++;
        arrows++;
        auto downstep_freq = appears.find(downstep);
        if (downstep_freq == appears.end()) {
            appears[downstep] = 0;
        } if (downstep_freq->second > 0) {
            appears[downstep]--;
            arrows--;
        }
    }

    cout << arrows << endl;
}