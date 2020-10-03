#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> &vec) {
    cout << vec.size() << " ";
    for (auto &item : vec) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    int n, a;
    vector<int> set1, set2, set3, neg;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a < 0) {
            if (set1.size() == 0) set1.push_back(a);
            else neg.push_back(a); 
        }
        else if (a > 0) {
            if (set2.size() == 0) set2.push_back(a);
            else set3.push_back(a); 
        }
        else {
            set3.push_back(a);
        }
    }

    if (set2.size() == 0) {
        set2.push_back(neg.back());
        neg.pop_back();
        set2.push_back(neg.back());
        neg.pop_back();
    }
    for (auto item : neg) {
        set3.push_back(item);
    }

    print_vec(set1);
    print_vec(set2);
    print_vec(set3);    
}