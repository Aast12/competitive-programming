#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        char ordered[3];
        bool offered[3] = {0, 0, 0};
        string offer_str, offer;

        for (int i = 0; i < 3; i++) {
            cin >> ordered[i];
        }
        cin.ignore();
        getline(cin, offer_str);
        stringstream ss(offer_str);
        while (ss >> offer) {
            char offer_char = offer[0];
            offered[offer_char - 'A'] = 1;
        }

        for (int i = 0; i < 3; i++) {
            char check = ordered[i];
            if (offered[check - 'A']) {
                cout << char(check) << endl;
                break;
            }
        }
    }
}