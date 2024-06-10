#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if(y1 > y2) {
        cout << "-1\n";
        return;
    }
    int move = 0;
    move += abs(y1 - y2);
    x1 += move;
    if(x1 < x2) {
        cout << "-1\n";
        return;
    }
    move += abs(x1 - x2);
    cout << move << '\n';
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