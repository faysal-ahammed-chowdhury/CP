#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    int mismatch  = 0;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if(abs(i - x) % k != 0) {
            mismatch++;
        }
    }
    if(mismatch == 0) {
        cout << "0\n";
    }
    else if(mismatch <= 2) {
        cout << "1\n";
    }
    else {
        cout << "-1\n";
    }
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