#include <iostream>
#include <set>

using namespace std;

int main()  {
    string s;
    cin >> s;

    set<char> letters;
    for (int i = 0; i < s.length(); i++) {
        letters.insert(s[i]);
    }

    cout << ((letters.size() % 2) ? "IGNORE HIM!" : "CHAT WITH HER!") << endl;
}