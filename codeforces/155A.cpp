#include <iostream>

using namespace std;

int main() {
    int n, score, min, max, amz = 0;
    cin >> n;
    cin >> score;
    min = max = score;
    
    for (int i = 1; i < n; i++) {
        cin >> score;
        if (score > max) {
            max = score;
            amz++;
        }
        else if (score < min) {
            min = score;
            amz++;
        }
    }

    cout << amz << endl;
}