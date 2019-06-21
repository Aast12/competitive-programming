#include <iostream>

using namespace std;

int main() {
    int n, a_wins = 0, d_wins = 0;
    string results;
    cin >> n >> results;

    for (int i = 0; i < results.size(); i++) {
        if (results[i] == 'A') a_wins++;
        else d_wins++;
    }

    if (a_wins > d_wins) cout << "Anton\n";
    else if (d_wins > a_wins) cout << "Danik\n";
    else cout << "Friendship\n";

}