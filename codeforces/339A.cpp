#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> numbers;
    for(int i = 0; i < s.length(); i += 2) {
       numbers.push_back(s[i] - '0'); 
    }

    sort(numbers.begin(), numbers.end());


    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << char((i == numbers.size() - 1) ? '\n' : '+'); 
    }
}