#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const size_t MAX_BITS = 25;
int score_sum = 0;

struct State {
    int remaining, level, sum;
    bitset<MAX_BITS> set;
    State() {}
    State(int su, int r, bitset<MAX_BITS> s, int l) : sum(su), remaining(r), set(s), level(l) {}
};

struct ScorePair {
    int score;
    bitset<MAX_BITS> set;
    ScorePair();
    ScorePair(int sc, bitset<MAX_BITS> s) : score(sc), set(s) {}

    bool operator<(const ScorePair& sp) {
        unsigned long s1 = set.to_ulong(), s2 = sp.set.to_ulong();
        if (s1 == s2) return score < sp.score;
        return s1 < s2;
    }

    void print() {
        for (int i = 0; i < MAX_BITS; i++) {
            if (set[i]) {
                cout << " " << i + 1;
            }
        }

        cout << endl;
    }
};

int score(int curr) {
    return floor((double(curr) / score_sum) * double(100));
}

int main() {
    int n, g;
    int min_steps = 100000;
    cin >> n >> g;

    int scores[n], min_sum;
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
        score_sum += scores[i];
    }

    queue<State> btq;
    vector<ScorePair> ans;

    btq.push(State(0, score_sum, bitset<MAX_BITS>(), 0));

    while (!btq.empty()) {
        State s = btq.front();
        btq.pop();

        if (s.set.count() > min_steps) continue;

        if (score(s.sum) >= g && s.level != 0) {
            ans.push_back(ScorePair(score(s.sum), s.set));
            min_steps = s.set.count();
        } else {
            if (score(s.sum + s.remaining) >= g && s.level < n) {
                bitset<MAX_BITS> add_set, dis_set;
                add_set = s.set;
                add_set[s.level] = 1;
                dis_set = s.set;
                dis_set[s.level] = 0;
                btq.push(State(s.sum, s.remaining - scores[s.level], dis_set, s.level + 1));
                btq.push(State(s.sum + scores[s.level], s.remaining - scores[s.level], add_set, s.level + 1));
            }
        }
    }

    sort(ans.begin(), ans.end());

    vector<ScorePair> filtered_ans;

    for (auto p : ans) {
        if (p.set.count() == min_steps) {
            filtered_ans.push_back(p);
        }
    }

    cout << min_steps << " " << filtered_ans.size() << endl;

    for (auto p : filtered_ans) {
        cout << p.score;
        p.print();
    }
}