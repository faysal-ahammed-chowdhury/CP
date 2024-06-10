#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    int n, x; cin >> n >> x;
    int arr[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    long long cnt = 0;
    unordered_map<long long, int> mp;
    mp[0]++;

    long long prefix[n + 1];
    prefix[0] = 0;
    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
        mp[prefix[i]]++;
        if(mp.find(prefix[i] - x) != mp.end()) {
            cnt += mp[prefix[i] - x];
        }
    }

    for(int i = 1; i < n; i++) {
        if(prefix[i] != prefix[i + 1]) {
            cout << cnt << '\n';
            return;
        }
    }

    cout << (1LL * n * (n + 1)) / 2 << '\n';
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