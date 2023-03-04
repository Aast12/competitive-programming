#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, a;
    cin >> n;

    stack<int> socks, aux, *prim, *sec;
    for (int i = 0; i < 2 * n; i++) {
        cin >> a;
        aux.push(a);
    }

    while (!aux.empty()) {
        socks.push(aux.top());
        aux.pop();
    }

    prim = &socks, sec = &aux;
    int movs = 0;
    bool moved = false, pos = true;
    while (!aux.empty() || !socks.empty()) {
        if (prim->empty()) {
            pos = false;
            break;
        } else {
            if (!sec->empty() && sec->top() == prim->top()) {
                moved = true;
                movs++;
                sec->pop();
                prim->pop();
            } else {
                sec->push(prim->top());
                prim->pop();
                movs++;
            }
        }
    }

    if (pos)
        cout << movs << endl;
    else
        cout << "Impossible" << endl;
}