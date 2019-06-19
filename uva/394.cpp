#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct rArray {
    int base, b_size, n_dimensions;
    vector<pair<int, int>> bounds;
};

int c_d(const rArray &A, int d) {
    if (d == -1) {
        int value = A.base;
        for (int i = 0; i < A.n_dimensions; i++) {
            value -= c_d(A, i) * A.bounds[i].first;
        }
        return value;
    }
    
    if (d == A.n_dimensions - 1) return A.b_size;

    return c_d(A, d + 1) * (A.bounds[d + 1].second - A.bounds[d + 1].first + 1);
}

int main() {
    int n_arrays, references, a, b, index;
    string name;
    map<string, rArray> arrays;

    cin >> n_arrays >> references;

    for (int i = 0; i < n_arrays; i++) {
        rArray n_array;
        cin >> name >> n_array.base >> n_array.b_size >> n_array.n_dimensions;
        for (int j = 0; j < n_array.n_dimensions; j++) {
            cin >> a >> b;
            n_array.bounds.push_back(make_pair(a, b));
        }
        arrays[name] = n_array;
    }

    for (int i = 0; i < references; i++) {
        cin >> name;
        int address = c_d(arrays[name], -1);
        cout << name << "[";
        for (int j = 0; j < arrays[name].n_dimensions; j++) {
            cin >> index;
            if (j != arrays[name].n_dimensions - 1) {
                cout << index << ", ";
            }   else {
                cout << index << "] = ";
            }
            address += c_d(arrays[name], j) * index;
        }
        cout << address << endl;
        
    }

}