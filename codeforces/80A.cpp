#include <iostream>

using namespace std;

bool sieve[70]; 

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 2; i <= 55; i++) {
       if (!sieve[i]) {
           for (int j = 2; i * j <= 55; j++) {
               sieve[i * j] = 1;
           }
       } 
    }

    for (int i = n + 1; i < 55; i++) {
        if (!sieve[i]) {
            cout << (i == m ? "YES" : "NO") << endl;
            break;
        }
    }
}