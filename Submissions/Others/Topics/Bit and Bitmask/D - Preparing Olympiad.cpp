#include <bits/stdc++.h>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l, r, x; cin >> n >> l >> r >> x;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ways = 0;
    for(int mask = 1; mask < (1 << n); mask++) {
        int sum = 0, mn = INT_MAX, mx = INT_MIN, cnt = 0;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                sum += (a[i]);
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
                cnt++;
            }
        }
        if(sum >= l && sum <= r && abs(mx - mn) >= x && cnt >= 2) {
            ways++;
        }
    }
    cout << ways << '\n';
    return 0;
}