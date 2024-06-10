#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s = to_string(n);
    int x = 0, y = 0, last = 0;
    for(auto i: s) {
        int d = i - '0';
        if(d % 2 == 0) {
            x = (x * 10) + (d / 2);
            y = (y * 10) + (d / 2);
        }
        else {
            if(last == 0) {
                x = (x * 10) + (d / 2);
                y = (y * 10) + (d / 2) + 1;
                last = 1;
            }
            else {
                x = (x * 10) + (d / 2) + 1;
                y = (y * 10) + (d / 2);
                last = 0;
            }
        }
    }
    cout << x << ' ' << y << '\n';
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