#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    int a[n];
    int even = 0, odd = 0;
    int mn = INT_MAX;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2 == 0) even++;
        else {
            odd++;
            mn = min(mn, a[i]);
        }
    }
    if(even == 0 || odd == 0) {
        cout << "YES\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 == 0 && a[i] <= mn) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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