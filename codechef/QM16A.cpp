#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        bool match = false;
        string line1, line2, aux;
        getline(cin, line1);
        getline(cin, line2);

        vector<string> words1, words2;

        stringstream ss1(line1);
        stringstream ss2(line2);

        while (ss1 >> aux) words1.push_back(aux);
        while (ss2 >> aux) words2.push_back(aux);
        
        for (int i = 0; i < words1.size(); i++) {
            for (int j = 0; j < words2.size(); j++) {
                if (words1[i] == words2[j]) {
                    match = true;
                    break;
                }
            }
            if (match) break;
        }

        cout << ((match) ? "Yes" : "No") << endl;
    }
}