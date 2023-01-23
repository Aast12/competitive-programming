// AC
#include <iostream>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

float EPS = 10e-5;

float calc_dist(pii coord) {
    return sqrt((float) (pow(coord.first, 2) + pow(coord.second, 2)));
} 


int main() {
    int t;
    pii alex, bob;
    
    cin >> t;

    while (t--) {
        cin >> alex.first >> alex.second >> bob.first >> bob.second;

        float alex_dist = calc_dist(alex), bob_dist = calc_dist(bob); 

        if (abs(alex_dist - bob_dist) < EPS) {
            cout << "EQUAL\n";
        } else if (alex_dist > bob_dist) {
            cout << "ALEX\n";
        } else{
            cout << "BOB\n";
        }
    }
}