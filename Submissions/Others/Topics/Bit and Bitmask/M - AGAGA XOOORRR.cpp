#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 2005;
int a[N], prefix_xor[N];
int get_xor(int l, int r) {
    return prefix_xor[r] ^ prefix_xor[l - 1];
}

void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix_xor[i] = prefix_xor[i - 1] ^ a[i];
    }
    bool yes = false;
    for(int i = 1; i < n; i++) {
        int x = get_xor(0, i);
        int y = get_xor(i + 1, n);
        if(x == y) {
            yes = true;
            break;
        }
    }
    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int x = get_xor(1, i);
            int y = get_xor(i + 1, j);
            int z = get_xor(j + 1, n);
            if(x == y && y == z) {
                yes = true;
                break;
            }
        }
    }

    cout << (yes ? "YES\n" : "NO\n");
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