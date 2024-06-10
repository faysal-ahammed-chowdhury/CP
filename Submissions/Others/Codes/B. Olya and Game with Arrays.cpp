#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> a[n];
    long long ans = 0, mn = INT_MAX, mn2 = INT_MAX;
    for(int i = 0; i < n; i++) {
      int m; cin >> m;
      for(int k = 0; k < m; k++) {
        int x; cin >> x;
        a[i].push_back(x);
      }
      sort(a[i].begin(), a[i].end());
      ans += a[i][1];
      mn = min(mn, 1ll * a[i][0]);
      mn2 = min(mn2, 1ll * a[i][1]);
    }
    cout << ans - mn2 + mn << '\n';
  }

  return 0;
}