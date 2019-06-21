#include <iostream>
#include <vector>
#include <deque>
using namespace std;

typedef unsigned long long ull;
typedef pair<ull, ull> pair_ull;
typedef vector<pair_ull> v_pair_u;
typedef vector<ull> v_ull;

int main() {
    ull n, q, aux, i_0, max_n = 0, max_i = 0;
    cin >> n >> q;
    deque<ull> nums;
    v_ull last_ns;
    v_pair_u pairs_n;

    for (ull i = 0; i < n; i++) {
        cin >> aux;
        if (i == 0) i_0 = aux;
        else nums.push_back(aux);
        if (aux > max_n) {
            max_n = aux;
            max_i = i;
        }
    }

    for (ull i = 0; i < n - 1; i++) {
        ull tmp = nums.front();
        pairs_n.push_back({i_0, nums.front()});
        if (i_0 > nums.front()) {
            nums.pop_front();
            nums.push_back(tmp);
            if (i_0 == max_i) break;
        } else {
            nums.push_back(i_0);
            i_0 = nums.front();
            nums.pop_front();
        }
    }
    for (ull i = 0; i < n - 1; i++) {
        ull tmp = nums.front();
        last_ns.push_back(nums.front());
        nums.pop_front();
        nums.push_back(tmp);
    }

    for (ull i = 0; i < q; i++) {
        cin >> aux;
        if (aux > max_i) {
            ull index = -1;
            index = (aux - 1) % last_ns.size();
            cout << max_n << " " << last_ns[index] << endl;
        } else {
            cout << pairs_n[aux - 1].first << " " << pairs_n[aux - 1].second << endl;
        }
    }
}