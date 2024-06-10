#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void print(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void solve() {
    int n = 3;
    int arr[] = {1, 3, 2};
    cout << "Original:\n";
    print(arr, n);
    cout << "Next:\n";
    next_permutation(arr, arr + n); // generate next lexicographical greater
    print(arr, n);
    next_permutation(arr, arr + n);
    print(arr, n);
    next_permutation(arr, arr + n);
    print(arr, n);
    next_permutation(arr, arr + n);
    print(arr, n);
    next_permutation(arr, arr + n);
    print(arr, n);
    next_permutation(arr, arr + n);
    print(arr, n);
    cout << "Prev:\n";
    prev_permutation(arr, arr + n); // generate prev lexicographical order
    print(arr, n);
    prev_permutation(arr, arr + n);
    print(arr, n);
    prev_permutation(arr, arr + n);
    print(arr, n);
    prev_permutation(arr, arr + n);
    print(arr, n);
    prev_permutation(arr, arr + n);
    print(arr, n);
    prev_permutation(arr, arr + n);
    print(arr, n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}