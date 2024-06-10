#include <bits/stdc++.h>
using namespace std;

const unsigned int N = (1u << 31);
bitset<N> exists;

void solve() {
    int q; unsigned int s, a, b; cin >> q >> s >> a >> b;
    long long sum = 0;
    while(q--) {
        unsigned int x = s / 2;
        if((s & 1) && !exists[x]) {
            sum += x;
            exists[x] = true;
        }
        else if(exists[x]) {
            sum -= x;
            exists[x] = false;
        }
        s = (a * s + b);
    }
    cout << sum << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}