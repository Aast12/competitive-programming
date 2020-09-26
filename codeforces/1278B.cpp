#include <iostream>
#include <cmath>


using namespace std;

typedef long long lli;

bool isTriangular(lli n){
    return ((float)sqrt(8*n+1) == floor(floor((float)sqrt(8*n+1))));
}

int main() {
    lli t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        lli c = abs(a - b);
        lli k = 0;
        while (a != b) {
            lli tr = k * (k + 1) / 2;
            if (tr >= c && tr % 2 == c % 2) {
                break;
            }
            k++;
        }
        cout << k << endl;
    }
}