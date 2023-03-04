#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>

using namespace std;

string search(vector<string>& names, int pos) {
    if (names[pos] != "?") {
        return names[pos];
    }

    int left = pos - 1, right = pos + 1;
    string leftname, rightname;
    int ww = 0;
    while (ww < 50) {
        ww++;
        leftname = (left >= 0) ? names[left] : "?";
        rightname = (right < names.size()) ? names[right] : "?";
        if (leftname != "?" and rightname != "?") {
            return "middle of " + leftname + " and " + rightname;
        } else if (leftname != "?") {
            string newname = "";
            for (int i = 0; i < pos - left; i++) newname += "right of ";
            return newname + leftname;
        } else if (rightname != "?") {
            string newname = "";
            for (int i = 0; i < right - pos; i++) newname += "left of ";
            return newname + rightname;
        }

        left--;
        right++;
    }

    return "";
}

int main() {
    int n, q, p;

    cin >> n;
    vector<string> names(n);
    for (int i = 0; i < n; i++) cin >> names[i];

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> p;
        p--;
        string name = search(names, p);  

        cout << name << endl;
    }
}