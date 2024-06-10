#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    int p[n];
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    if(n == 1) {
        cout << p[0] << '\n';
        return;
    }
    int target = (p[0] == n ? n - 1 : n);
    int target_idx = -1;
    for(int i = 0; i < n; i++) {
        if(p[i] == target) {
            target_idx = i;
            break;
        }
    }
    bool target_last = (target_idx == n - 1? true : false);
    for(int i = target_idx; i < n; i++) {
        cout << p[i] << ' ';
    }
    int idx = target_idx - 1;
    int now = -1;
    int first = true;
    for(int i = idx; i >= 0; i--) {
        if((p[i] > p[0]) || (first)) {
            if(first && target_last && p[i] < p[0]) {
                now = i;
                break;
            }
            else {
                cout << p[i] << ' ';
                first = false;
            }
        }
        else {
            now = i;
            break;
        }
    }
    for(int i = 0; i <= now; i++) {
        cout << p[i] << ' ';
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