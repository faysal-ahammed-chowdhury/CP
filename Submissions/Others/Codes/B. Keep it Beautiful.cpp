#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int q; cin >> q;
    q--;
    int first; cin >> first;
    cout << 1;
    bool flag = false;
    int last = first;
    while(q--) {
        int x; cin >> x;
        if(flag == true) {
            if(x >= last && x <= first) {
                cout << 1;
                last = x;
            }
            else {
                cout << 0;
            }
        }
        else {
            if(x >= last) {
                cout << 1;
                last = x;
            }
            else {
                if(x <= first) {
                    cout << 1;
                    last = x;
                    flag = true;
                }
                else {
                    cout << 0;
                }
            }
        }
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