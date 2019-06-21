#include <iostream>
#include <iomanip>

using namespace std;
//           A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
int codes[] = {0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string name;
    
    cout << "         NAME                     SOUNDEX CODE\n";
    while (cin >> name) {
        int prev = -1, count = 0;
        
        cout << "         " << name;
        for (int i = name.size(); i < 25; i++) cout << " ";

        for (int i = 0; i < name.size(); i++) {
            if (count == 3) break;
            int curr = codes[name[i] - 'A'];
            if (i == 0) {
                cout << name[i];
                prev = curr;
            } else {
                if (curr != prev && curr != 0) {
                    cout << curr;
                    count++;
                }
                prev = curr;
            }
            
        }
        cout << setfill('0') << setw(3 - count) << "" <<  endl;
    }
    
    cout << "                   END OF OUTPUT\n";
}