#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    long long sum = 0;
    int neg = 0;
    int mn = INT_MAX;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        sum += abs(x);
        mn = min(mn, abs(x));   
        if(x <= 0) neg++;
    }
    if(neg % 2 == 0) cout << sum << '\n';
    else cout << sum - (2 * mn) << '\n';
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