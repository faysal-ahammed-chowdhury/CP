#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if(n == 1) {
        cout << 1 << '\n';
        return;
    }
    if((n * (n + 1) / 2) % n == 0) {
        cout << "-1\n";
        return;
    }
    int half = n / 2, odd = 1, even = 2;
    for(int i = 1; i <= half; i++) {
        cout << even << ' ' << odd << ' ';
        odd += 2, even += 2;
    }  
    if(n % 2 == 1) {
        cout << ++odd;
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