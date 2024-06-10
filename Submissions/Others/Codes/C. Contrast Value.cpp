#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    int a[n];
    int last = -1, cnt  = 0, remove_cnt = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(last != x) {
            a[cnt++] = x;
            last = x;
        }
    }
    remove_cnt = n - cnt;
    for(int i = 1; i + 1 < cnt; i++) {
        int curr = a[i];
        int prev = a[i - 1];
        int next = a[i + 1];
        if(abs(curr - next) + abs(curr - prev) == abs(prev - next)) {
            remove_cnt++;
        }
    }
    cout << n - remove_cnt << '\n';
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