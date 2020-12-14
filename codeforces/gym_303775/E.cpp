#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

unordered_map<int, string> ans;

string curr;
int currIdx;

struct Node {
    int v, len;
    bool isEnd = 0;
    Node *l = nullptr, *r = nullptr;

    Node(int l) : len(l) {}
};

bool search(Node *r, int len) {
    if (r->isEnd) return false;
    if (r->len == len) {
        r->isEnd = 1;
        ans[currIdx] = curr;
        return true;
    }

    string s = curr;
    bool found = false;
    curr = s + '0';
    if (r->l == nullptr) r->l = new Node(r->len + 1);
    found = search(r->l, len);
    if (found) return true;
    curr = s + '1';
    if (r->r == nullptr) r->r = new Node(r->len + 1);
    return search(r->r, len);
}

int main() {
    int n;
    cin >> n;
    vector<int> lengths(n);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
        pq.push(make_pair(lengths[i], i));
    }

    Node root = Node(0);

    bool isPos = 1;
    while (!pq.empty()){
        auto top = pq.top();
        pq.pop();

        stack<Node*> state;
        string current = "";
        state.push(&root);

        int len = top.first;
        curr = "";
        currIdx = top.second;
        if (!search(&root, len)) {
            isPos = 0;
            break;
        }
    }
    cout << (isPos ? "YES\n" : "NO\n");

    for (int i = 0; isPos && i < lengths.size(); i++) {
        cout << ans[i] << endl;
    }

}
