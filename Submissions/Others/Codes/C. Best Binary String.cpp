#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '?') {
            if(i + 1 < s.size() && (s[i + 1] != '?')) {
                s[i] = s[i + 1];
            }
            else if(i - 1 >= 0 && (s[i - 1] != '?')) {
                s[i] = s[i - 1];
            }
            if(s[i] == '?') {
                s[i] = '0';
            }
        }
    }
    cout << s << '\n';
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