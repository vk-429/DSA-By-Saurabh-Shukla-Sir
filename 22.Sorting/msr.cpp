#include <iostream>
#include <vector>
using namespace std;


void mergesortrec(int *p, int li, int ui) {
    if (ui - li == 0)
        return;
    int mid = (li + ui) / 2;
    mergesortrec(p, li, mid);
    mergesortrec(p, mid + 1, ui);
    int i, j;
    vector<int> a;
    vector<int> b;
    for (i = li; i <= mid; i++)
        a.push_back(p[i]);
    for (i = mid + 1; i <= ui; i++)
        b.push_back(p[i]);
    i = 0;
    j = 0;
    int k;
    for (k = li; k <= ui; k++) {
        if (i == a.size() || j == b.size())
            break;
        if (a[i] < b[j]) {
            p[k] = a[i];
            i++;
        } else {
            p[k] = b[j];
            j++;
        }
    }
    while (i < a.size()) {
        p[k] = a[i];
        i++;
        k++;
    }
    while (j < b.size()) {
        p[k] = b[j];
        j++;
        k++;
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    mergesortrec(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}
