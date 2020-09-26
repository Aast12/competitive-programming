// PENDING
#include <iostream>

using namespace std;

class SegmentTree {
public:
    int* max_tree;
    int* min_tree;
    int* arr;
    int size;
    bool intersting;
    pair<int, int> answer;
    SegmentTree(int* _arr, int _size) {
        size = _size;
        max_tree = new int[size * 4];
        min_tree = new int[size * 4];
        arr = _arr;
        intersting = 0;
        build(0, 0, size - 1);
    }
    ~SegmentTree() {
        delete[] max_tree;
        delete[] min_tree;
        delete[] arr;
    }
    void build(int node, int start, int end) {
        if (start == end) {
            max_tree[node] = arr[start];
            min_tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            max_tree[node] = max(max_tree[2 * node + 1], max_tree[2 * node + 2]);
            min_tree[node] = min(min_tree[2 * node + 1], min_tree[2 * node + 2]);
            if (max_tree[node] - min_tree[node] >= size) {
                intersting = 1;
                answer = make_pair(start + 1, end + 1);
            }
        }
    }
};

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        } 
        SegmentTree tree(arr, n);
        if (tree.intersting) {
            cout << "YES" << endl;
            cout << tree.answer.first << " " << tree.answer.second << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}