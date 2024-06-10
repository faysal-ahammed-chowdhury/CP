#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = abs(arr[0] - arr[n - 1]);
    int i, j; i = 0, j = n - 1;
    while(i < j) {
        int d = abs(arr[i] - arr[j]);
        ans = __gcd(ans, d);
        i++, j--;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}