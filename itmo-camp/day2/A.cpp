#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &A, int lo, int mid, int up) {
    int i = lo, j = mid + 1, k = 0;
    vector<int> result(up - lo + 1);

    while (i <= mid && j <= up) {
        if (A[i] < A[j])
            result[k++] = A[i++];
        else
            result[k++] = A[j++];
    }
    while (i <= mid) result[k++] = A[i++];
    while (j <= up) result[k++] = A[j++];

    for (int q = 0; q < result.size(); q++) A[q + lo] = result[q];
}

void mergeSort(vector<int> &A, int lo, int up) {
    if (lo >= up) return;
    int mid = (lo + up) / 2;

    mergeSort(A, lo, mid);
    mergeSort(A, mid + 1, up);

    merge(A, lo, mid, up);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}