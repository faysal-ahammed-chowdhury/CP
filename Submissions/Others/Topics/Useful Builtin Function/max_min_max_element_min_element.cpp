#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    cout << max(5, 10) << '\n';
    cout << max({5, 10, 20, 15}) << '\n';
    cout << min(5, 10) << '\n';
    cout << min({10, 20, 15}) << '\n';
    int arr[5] = {1, 2, 3, 4, 5};
    cout << *max_element(arr, arr + 5) << '\n';
    cout << *min_element(arr, arr + 5) << '\n';
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