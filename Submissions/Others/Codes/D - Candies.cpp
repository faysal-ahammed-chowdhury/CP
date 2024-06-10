#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if(n % 2 == 0) {
        cout << "-1\n";
        return;
    }
    deque<int> ans;
    for(int i = 1; i <= 40; i++) {
        int half = (n + 1) / 2;
        if(half % 2 == 0) {
            ans.push_front(2);
            n = half - 1;
        }
        else {
            ans.push_front(1);
            n = half;
        }
        if(n == 1) {
            break;
        }
    }

    cout << (int)ans.size() << '\n';
    for(auto i: ans) {
        cout << i << ' ';
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