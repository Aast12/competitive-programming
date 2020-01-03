#include <iostream>
#include <cmath>

using namespace std;

unsigned long long target = 600851475143;
const int limit = sqrt(600851475143);
bool sieve[limit];

int main() { 
    int max_prime = 0;
    sieve[0] = sieve[1] = 1;
    sieve[2] = 0;
    for (int i = 2; i <= limit; i++) {
        if (!sieve[i]) {
            if (target % i == 0) {
                max_prime = i;
            }
            for (int j = 2; i * j <= limit; j++) {
                sieve[i * j] = 1;
            }
        }
    }
    
    cout << max_prime << endl;
}