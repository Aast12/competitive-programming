#include <iostream>

using namespace std;

int main() {
    int caps_conversion = 'A' - 'a';
    int lowercase = 0; 
    
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            lowercase++;
        }
    }

    bool upper = lowercase < (s.size() - lowercase);

    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] += caps_conversion * upper;
        } 
        else {
            s[i] -= caps_conversion * !upper;
        }
    }

    cout << s << endl;
}