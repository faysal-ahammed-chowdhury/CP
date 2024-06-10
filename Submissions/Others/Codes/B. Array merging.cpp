#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int a[n + 1], b[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    
    map<int, int> mp1;
    int last = a[1];
    int consecutive = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] == a[i - 1]) {
            consecutive++;
        }
        else {
            mp1[last] = max(mp1[last], consecutive);
            consecutive = 1;
            last = a[i];
        }
    }
    mp1[last] = max(mp1[last], consecutive);

    map<int, int> mp2;
    last = b[1];
    consecutive = 1;
    for(int i = 2; i <= n; i++) {
        if(b[i] == b[i - 1]) {
            consecutive++;
        }
        else {
            mp2[last] = max(mp2[last], consecutive);
            consecutive = 1;
            last = b[i];
        }
    }
    mp2[last] = max(mp2[last], consecutive);

    long long ans = -1;
    for(auto i: mp1) {
        int val = mp2[i.first];
        ans = max(ans, (long long)i.second + val);
    }
    for(auto i: mp2) {
        int val = mp1[i.first];
        ans = max(ans, (long long)i.second + val);
    }
    cout << ans << '\n';
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