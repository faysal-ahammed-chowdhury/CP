#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n + 1), ans(n + 1, 0);
    set<int> se;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        se.insert(i);
    }

    for(int i = 1; i <= n; i++) {
        if(se.find(a[i]) != se.end()) {
            ans[i] = a[i];
            se.erase(a[i]);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(ans[i] == 0) {
            ans[i] = *se.begin();
            se.erase(se.begin());
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}   