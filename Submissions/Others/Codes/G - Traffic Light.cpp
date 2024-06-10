#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; char init; cin >> n >> init;
    string s; cin >> s;
    if(init == 'g') {
        cout << 0 << '\n';
        return;
    }
    bool complete = true;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == init) {
            int start = i;
            while(i < n && s[i] != 'g') {
                i++;
            }
            if(i < n) {
                ans = max(ans, i - start);
            }
            else {
                complete = false;
            }
        }
    }
    if(complete) {
        cout << ans << '\n';
        return;
    }
    int last_init, first_green;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == init) {
            last_init = i;
        }
        else if(s[i] == 'g') {
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if(s[i] == 'g') {
            first_green = i;
            break;
        }
    }
    ans = max(ans, (n - last_init) + first_green);
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