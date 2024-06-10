#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    int arr[5] = {1, 2, 3, 4, 5};
    int arr1[5] = {1, 2, 5, 4, 5};
    cout << is_sorted(arr, arr + 5) << '\n';
    cout << is_sorted(arr1, arr1 + 5) << '\n';
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