#include <iostream>
#include <list>
#include <queue>

using namespace std;

struct CrashTime {
    list<int>::iterator it;
    double t;

    CrashTime() {}
    CrashTime(list<int>::iterator it, int t) : it(it), t(t) {}
};

bool operator<(const CrashTime& a, const CrashTime& b) { return a.t > b.t; }

int main() {
    list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);

    priority_queue<CrashTime> pq;
    auto it = lst.begin();
    cout << "INSERT " << *it << endl;
    pq.push(CrashTime(it++, 2));
    cout << "INSERT " << *it << endl;
    pq.push(CrashTime(it++, 5));
    cout << "INSERT " << *it << endl;

    pq.push(CrashTime(it++, 10));

    while (!pq.empty()) {
        auto top = pq.top();
        cout << "TOP " << (*top.it) << endl;
        pq.pop();
        top.it++;        
        cout << "ERASE " << (*top.it) << endl;
        lst.erase(top.it);
    }
}