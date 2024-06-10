#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    int a[m + 1];
    for(int i = 0; i <= m; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        int x = a[m] ^ a[i];
        if(__builtin_popcount(x) <= k) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}