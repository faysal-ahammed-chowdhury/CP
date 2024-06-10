#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void print(int arr[]) {
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void solve() {
    int n = 5;
    int arr[n] = {10, 30, 20, 50, 40};
    print(arr);
    sort(arr, arr + n); // O(n*logn)
    cout << "Sorted: ";
    print(arr);
    reverse(arr, arr + n); // O(n)
    cout << "Reverse: ";
    print(arr);
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