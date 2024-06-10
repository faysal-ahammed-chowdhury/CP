#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k, m; cin >> n >> k >> m;
  string s[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  map<string, int> mp;
  int grp_cost[k + 1];
  for (int i = 1; i <= k; i++) {
    int x; cin >> x;
    int mn = 2e9;
    for (int j = 1; j <= x; j++) {
      int val; cin >> val;
      mp[s[val]] = i;
      mn = min(mn, a[val]);
    }
    grp_cost[i] = mn;
  }

  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    string x; cin >> x;
    ans += grp_cost[mp[x]];
  }
  cout << ans << '\n';

  return 0;
}