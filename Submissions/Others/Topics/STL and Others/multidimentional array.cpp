#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const double PI = (2 * acos(0.0));

void solve() {
    int n, m; cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j] << ' ';
      }
      cout << '\n';
    }
    // int a[4][5][6]; //3D
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