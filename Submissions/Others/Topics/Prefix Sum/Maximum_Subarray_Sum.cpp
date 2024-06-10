#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    int n; cin >> n;
    int arr[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    long long prefix[n + 1];
    prefix[0] = 0;
    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    long long ans = INT64_MIN;
    long long low = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, prefix[i] - low);
        low = min(low, prefix[i]);
    }

    cout << ans << '\n';
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