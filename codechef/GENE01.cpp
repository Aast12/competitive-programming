#include <iostream>
#include <map>

using namespace std;

int main() {
    char pa, pb;
    map<char, short> rarity;
    rarity['R'] = 0;
    rarity['B'] = 1;
    rarity['G'] = 2;

    cin >> pa >> pb;

    if (rarity[pa] < rarity[pb]) {
        cout << pa << endl;
    } else {
        cout << pb << endl;
    }
}