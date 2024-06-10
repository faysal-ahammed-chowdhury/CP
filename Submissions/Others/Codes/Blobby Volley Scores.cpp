#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int score1 = 0, score2 = 0;
    char ch = 'A';
    for(auto i: s) {
        if(i == 'A') {
            if(ch == 'A') {
                score1++;
            }
            else {
                ch = 'A';
            }
        }
        else {
            if(ch == 'B') {
                score2++;
            }
            else {
                ch = 'B';
            }
        }
    }

    cout << score1 << ' ' << score2 << '\n';
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