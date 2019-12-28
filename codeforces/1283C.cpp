// OK
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> rels(n);
    bool check[n];
    list<int> available;
    list<int> priority;
    for (int i = 0; i < n; i++) check[i] = 0;
    for (int i = 0; i < n; i++) {
        cin >> rels[i];
        check[rels[i] - 1] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (check[i] == 0) {
            if (rels[i] == 0) {
                priority.push_back(i);
            } else {
                available.push_back(i);
            }
        }
    }
    for (auto i = priority.begin(); i != priority.end(); i++) {
        auto next = i;
        next++;
        if (next != priority.end()) {
            rels[*i] = *next + 1;
        } 
        else if (priority.size() > 1){
            rels[*i] = *priority.begin() + 1;
        }
        else {
            rels[*i] = *available.begin() + 1;
            available.push_back(*i);
            available.erase(available.begin());
        }
    }
    for (int i = 0; i < n; i++) {
        if (rels[i] == 0) {
            for (auto j = available.begin(); j != available.end(); j++) {
                if (*j != i) {
                    cout << *j + 1 << " ";
                    available.erase(j);
                    break;
                }
            }
        } else {
            cout << rels[i] << " ";
        }
    }
    cout << endl;
}
