#include <iostream>

using namespace std;

int main() {
    int multiples_of_3 = 3 * ((333 * 334) / 2);
    int multiples_of_5 = 5 * ((199 * 200) / 2);
    int multiples_of_15 = 15 * ((66 * 67) / 2);

    cout << multiples_of_3 + multiples_of_5 - multiples_of_15;
}