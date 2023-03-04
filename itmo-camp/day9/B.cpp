#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

vector<string> permutations;

void printVec(vi &vec) {
    permutations.push_back("");
    for (int i = 0; i < vec.size(); i++) {
        permutations.back() += vec[i] + '0';
        permutations.back() += ' ';
    }
}

void genPermutations(vi &vec, int size) {
    if (size == 1) {
        printVec(vec);
        return;
    }

    genPermutations(vec, size - 1);
    for (int i = 0; i < size - 1; i++) {

        if (size & 1)
            swap(vec[0], vec[size - 1]);
        else
            swap(vec[i], vec[size - 1]);

        genPermutations(vec, size - 1);
    }
}

int main() {
    int n;
    cin >> n;

    vi seq(n);
    for (int i = 0; i < n; i++)
        seq[i] = i + 1;

    permutations = vector<string>();
    
    genPermutations(seq, n);

    sort(permutations.begin(), permutations.end());

    for (auto &next: permutations) {
        cout << next << endl;
    }
}