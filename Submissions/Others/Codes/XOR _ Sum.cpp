#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int l, r; cin >> l >> r;
    int count = 0;
    for(int i = l; i <= r; i++) {
        for(int j = i; j <= r; j++) {
            if(i + j == (i ^ j)) count++;
        }
    }
    cout << count << '\n';
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