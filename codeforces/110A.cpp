#include <iostream>

using namespace std;

int main() {
    string num;
    int luckies = 0;
    cin >> num;
    for (int i = 0; i < num.size(); i++) {
        if (num[i] == '4' || num[i] == '7') {
            luckies++;
        }
    }
    
    bool is_nearly_lucky = (luckies != 0);
    while (luckies > 0) {
        short digit = luckies % 10;
        if (digit != 4 && digit != 7) {
            is_nearly_lucky = false;
            break;
        }
        luckies /= 10;
    }

    cout << (is_nearly_lucky ? "YES" : "NO") << endl;
}