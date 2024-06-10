#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    int a[n];
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    if(mp.size() == 1) {
        cout << "NO\n";
        return;
    }

    sort(a, a + n);
    reverse(a, a + n);
    cout << "YES\n";
    int step = n;
    for(int i = 0; i < step; i++) {
        if(i == 1 && a[i] == a[i - 1]) {
            cout << a[n - 1] << ' ';
            step--;
        }
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}