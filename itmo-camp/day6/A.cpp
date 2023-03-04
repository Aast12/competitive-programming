#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pi(n, 0);

    for (int i = 1; i < n; i++) {
        int x = pi[i - 1];
        while (s[i] != s[x] && x > 0) 
            x = pi[x - 1];

        if (s[i] == s[x])
            x++;

        pi[i] = x;
    }

    for (int i = 0; i < n; i++)
        cout << pi[i] << " ";
    
    cout << endl;
}
