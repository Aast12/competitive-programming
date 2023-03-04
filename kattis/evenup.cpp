#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n, a;
    cin >> n;

    stack<int> cards;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (!cards.empty() && !((cards.top() + a) & 1)) {
            cards.pop();
        } else {
            cards.push(a);
        }
    }

    cout << cards.size() << endl;
}